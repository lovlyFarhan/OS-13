#include "ProducerConsumer.h"

//�����Ĳ�Ʒ��
unsigned short ProductID = 0;
//���ѵĲ�Ʒ��
unsigned short ConsumeID = 0;
//��Ʒ�Ž�����صĻ�����ָ��
unsigned short in = 0;
//��Ʒȡȥ����صĻ�����ָ��
unsigned short out = 0;

//�����|ѭ������
int g_buffer[SIZE_OF_BUFFER];

//�������
bool g_continue = true;

/** �ź��� **/
//�����̼߳�Ļ���
HANDLE g_hMutex;
//�������ʱ|�����߽��̵ȴ�
HANDLE g_hFullSemaphore;
//�����ѿ�ʱ|�����߽��̵ȴ�
HANDLE g_hEmptySemaphore;

/**
 *��ʼ������
 *
 */
bool InitData()
{
	//��ʼ�������ź���
	g_hMutex = CreateMutex(NULL,FALSE,NULL);
	g_hFullSemaphore = CreateSemaphore(NULL,SIZE_OF_BUFFER - 1,SIZE_OF_BUFFER - 1,NULL);
	g_hEmptySemaphore = CreateSemaphore(NULL,0,SIZE_OF_BUFFER - 1,NULL);

	//�����������̵߳���Ŀ
	const unsigned short PRODUCERS_COUNT = 3;
	//�����������̵߳���Ŀ
	const unsigned short CONSUMERS_COUNT = 1;
	//�̵߳�����Ŀ
	const unsigned short THREADS_COUNT = PRODUCERS_COUNT + CONSUMERS_COUNT;

	HANDLE hTheads[THREADS_COUNT];
	HANDLE producerID[PRODUCERS_COUNT];
	HANDLE consumerID[CONSUMERS_COUNT];
	
	//�����߳�
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
*�������߳�
**/
DWORD WINAPI Producer(LPVOID lpPara)
{
	while (g_continue)
	{
		WaitForSingleObject(g_hFullSemaphore,INFINITE);
		WaitForSingleObject(g_hMutex,INFINITE);
		/** �ٽ��� **/
		Produce();
		Append();
		Sleep(1500);
		ReleaseMutex(g_hMutex);
		ReleaseSemaphore(g_hEmptySemaphore,1,NULL);
	}
	return EXIT_SUCCESS;
}


/**
*�������߳�
**/
DWORD WINAPI Consumer(LPVOID lpPara)
{
	while (g_continue)
	{
		WaitForSingleObject(g_hEmptySemaphore,INFINITE);
		WaitForSingleObject(g_hMutex,INFINITE);
		/** �ٽ��� **/
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

	//�����������ǰ��״̬
	for (int i = 0;i < SIZE_OF_BUFFER;++i){
		std::cout << i <<": " << g_buffer[i];
		if (i == in) std::cout << " <-- ����";
		if (i == out) std::cout << " <-- ����";
		std::cout << std::endl;
	}
}

void Take()
{
	std::cerr << "Taking a product ... ";
	ConsumeID = g_buffer[out];
	out = (out + 1) % SIZE_OF_BUFFER;
	std::cerr << "Succeed" << std::endl;

	//�����������ǰ��״̬
	for (int i = 0;i < SIZE_OF_BUFFER;++i){
		std::cout << i <<": " << g_buffer[i];
		if (i == in) std::cout << " <-- ����";
		if (i == out) std::cout << " <-- ����";
		std::cout << std::endl;
	}
}
/**
 *��ʾ����
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