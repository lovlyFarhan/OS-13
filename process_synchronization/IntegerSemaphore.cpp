#include "IntegerSemaphore.h"

CRITICALRESOURCE CR;     //�ٽ���Դ
HANDLE hMutex;               //ʵ��ԭ�Ӳ������м����

//Atomic Operation|������Ʒ
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

//Atomic Operation|���Ѳ�Ʒ
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
*�����߽��̣����ϸ��������Ӳ�Ʒ��
**/
DWORD WINAPI PRODUCERPROCESS(LPVOID lpParamter)
{
	while (true)
	{
		Sleep(rand() % 5000);
		if(signal())
			printf("�����߽���|����һ����Ʒ\n");
		else
			printf("������������ȴ���\n");
	}
}

/**
*�����߽��̣��������ѻ�����в�Ʒ��
**/
DWORD WINAPI CONSUMERPROCESS(LPVOID lpParamter)
{
	while (true)
	{
			Sleep(rand() % 5000);
		if(wait())
			printf("�����߽���|ȡ��һ����Ʒ\n");
		else
			printf("�����Ϊ�գ��ȴ���\n");
	}
}

/**
*���Ժ���
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