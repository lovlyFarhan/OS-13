#include "ProducerConsumer.h"

//生产的产品号
unsigned short ProductID = 0;
//消费的产品号
unsigned short ConsumeID = 0;
//产品放进缓冲池的缓冲区指针
unsigned short in = 0;
//产品取去缓冲池的缓冲区指针
unsigned short out = 0;

//缓冲池|循环队列
int g_buffer[SIZE_OF_BUFFER];

//程序控制
bool g_continue = true;

/** 信号量 **/
//用于线程间的互斥
HANDLE g_hMutex;
//缓冲池满时|生产者进程等待
HANDLE g_hFullSemaphore;
//缓冲已空时|消费者进程等待
HANDLE g_hEmptySemaphore;

/**
 *初始化函数
 *
 */
bool InitData()
{
	//初始化互斥信号量
	g_hMutex = CreateMutex(NULL,FALSE,NULL);
	g_hFullSemaphore = CreateSemaphore(NULL,SIZE_OF_BUFFER - 1,SIZE_OF_BUFFER - 1,NULL);
	g_hEmptySemaphore = CreateSemaphore(NULL,0,SIZE_OF_BUFFER - 1,NULL);

	//设置生产者线程的数目
	const unsigned short PRODUCERS_COUNT = 3;
	//设置消费者线程的数目
	const unsigned short CONSUMERS_COUNT = 1;
	//线程的总数目
	const unsigned short THREADS_COUNT = PRODUCERS_COUNT + CONSUMERS_COUNT;

	HANDLE hTheads[THREADS_COUNT];
	HANDLE producerID[PRODUCERS_COUNT];
	HANDLE consumerID[CONSUMERS_COUNT];
	
	//创建线程
	int index = 0;
	for(;index < PRODUCERS_COUNT;++index)
	{
		hTheads[index] = CreateThread(NULL,0,Producer,NULL,0,(LPDWORD)&producerID[index]);
		if(NULL == hTheads[index])
			return false;
	}
	for(;index < THREADS_COUNT;++index)
	{
		hTheads[index] = CreateThread(NULL,0,Consumer,NULL,0,(LPDWORD)&consumerID[index - PRODUCERS_COUNT]);
		if(NULL == hTheads[index])
			return false;
	}
	return true;
}

/**
*生产者线程
**/
DWORD WINAPI Producer(LPVOID lpPara)
{
	while (g_continue)
	{
		WaitForSingleObject(g_hFullSemaphore,INFINITE);
		WaitForSingleObject(g_hMutex,INFINITE);
		/** 临界区 **/
		Produce();
		Append();
		Sleep(1500);
		ReleaseMutex(g_hMutex);
		ReleaseSemaphore(g_hEmptySemaphore,1,NULL);
	}
	return EXIT_SUCCESS;
}


/**
*消费者线程
**/
DWORD WINAPI Consumer(LPVOID lpPara)
{
	while (g_continue)
	{
		WaitForSingleObject(g_hEmptySemaphore,INFINITE);
		WaitForSingleObject(g_hMutex,INFINITE);
		/** 临界区 **/
		Take();
		Consume();
		Sleep(1500);
		ReleaseMutex(g_hMutex);
		ReleaseSemaphore(g_hEmptySemaphore,1,NULL);
	}
	return EXIT_SUCCESS;
}

void Produce()
{
	std::cerr<<"Producing@"<<++ProductID<<"...";
	std::cerr<<"Succeed"<<std::endl;
}

void Consume()
{
	std::cerr<<"Consuming@"<<ConsumeID++<<"...";
	std::cerr<<"Succeed"<<std::endl;
}

void Append()
{
	std::cerr << "Appending a product ... ";
	g_buffer[in] = ProductID;
	in = (in + 1) % SIZE_OF_BUFFER;
	std::cerr << "Succeed" << std::endl;

	//输出缓冲区当前的状态
	for (int i = 0;i < SIZE_OF_BUFFER;++i){
		std::cout << i <<": " << g_buffer[i];
		if (i == in) std::cout << " <-- 生产";
		if (i == out) std::cout << " <-- 消费";
		std::cout << std::endl;
	}
}

void Take()
{
	std::cerr << "Taking a product ... ";
	ConsumeID = g_buffer[out];
	out = (out + 1) % SIZE_OF_BUFFER;
	std::cerr << "Succeed" << std::endl;

	//输出缓冲区当前的状态
	for (int i = 0;i < SIZE_OF_BUFFER;++i){
		std::cout << i <<": " << g_buffer[i];
		if (i == in) std::cout << " <-- 生产";
		if (i == out) std::cout << " <-- 消费";
		std::cout << std::endl;
	}
}
/**
 *演示函数
 */
void ProducerConsumer_Test()
{
	InitData();
	while (g_continue)
	{
		if(getchar())
		{
			g_continue = false;
		}
	}
}