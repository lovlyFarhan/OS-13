#ifndef INTEGER_SEMAPHORE_H
#define INTEGER_SEMAPHORE_H

#include <cstdio>
#include <cstdlib>
#include <Windows.h>

#define PRODUCER_CONSUMER_SIZE 10

/**
  *�ṹ�壺�ٽ���Դ
  *@date 2012/12/08
  **/
struct CRITICALRESOURCE
{
	BOOL bufferPool[PRODUCER_CONSUMER_SIZE];//�����
	int n;                                                                     //����ص���Ŀ
	int in;                                                                    //����ָ��
	int out;                                                                 //���ָ��
	int counter;                                                          //���ͱ���
    //��ʼ��
	CRITICALRESOURCE()
	{
		this->counter = 0;
		this->n = PRODUCER_CONSUMER_SIZE;
		this->in = this->out = 0;
		for(int index = 0;index < this->n;++index)
			this->bufferPool[index] = FALSE;
	}

	void print()
	{
		printf("counter:%d in:%d out:%d @",counter,in,out);
	}
};
//Atomic Operation
BOOL wait();
//Atomic Operation
BOOL signal();
//�����߽���
DWORD WINAPI PRODUCERPROCESS(LPVOID lpParamter);
//�����߽���
DWORD WINAPI CONSUMERPROCESS(LPVOID lpParamter);
//���Ժ���
BOOL INTEGER_SEMAPHORE_TEST();

#endif // INTEGER_SEMAPHORE_H