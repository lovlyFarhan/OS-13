#include "IntegerSemaphore.h"

CRITICALRESOURCE CR;     //临界资源
HANDLE hMutex;               //实现原子操作的中间变量

//Atomic Operation|生产产品
BOOL wait()
{
	WaitForSingleObject(hMutex,INFINITE);

	BOOL RETURN_STATUS = FALSE;
	if(0 != CR.counter)
	{
		CR.bufferPool[CR.out] = FALSE;
		CR.out = (CR.out + 1) % CR.n;
		CR.counter--;
		RETURN_STATUS = TRUE;
		CR.print();
	}
	ReleaseMutex(hMutex);
	return RETURN_STATUS;
}

//Atomic Operation|消费产品
BOOL signal()
{
	WaitForSingleObject(hMutex,INFINITE);
 
	BOOL RETURN_STATUS = FALSE;
	if(CR.counter != CR.n)
	{
		CR.bufferPool[CR.in] = TRUE;
		CR.in = (CR.in + 1) % CR.n;
		CR.counter++;	
		RETURN_STATUS = TRUE;
		CR.print();
	}	
	ReleaseMutex(hMutex);
	return RETURN_STATUS;
}
/**
*生产者进程：不断给缓冲池添加产品。
**/
DWORD WINAPI PRODUCERPROCESS(LPVOID lpParamter)
{
	while (true)
	{
		Sleep(rand() % 5000);
		if(signal())
			printf("生产者进程|生产一个产品\n");
		else
			printf("缓冲池已满，等待中\n");
	}
}

/**
*消费者进程：不断消费缓冲池中产品。
**/
DWORD WINAPI CONSUMERPROCESS(LPVOID lpParamter)
{
	while (true)
	{
			Sleep(rand() % 5000);
		if(wait())
			printf("消费者进程|取走一个产品\n");
		else
			printf("缓冲池为空，等待中\n");
	}
}

/**
*测试函数
**/
BOOL INTEGER_SEMAPHORE_TEST()
{
	hMutex = CreateMutex(NULL,FALSE,LPCWSTR("CR"));
	HANDLE producerThread = CreateThread(NULL,0,PRODUCERPROCESS,NULL,0,NULL);
	CloseHandle(producerThread);
	HANDLE consumerThread = CreateThread(NULL,0,CONSUMERPROCESS,NULL,0,NULL);
	CloseHandle(consumerThread);
	return EXIT_SUCCESS;
}