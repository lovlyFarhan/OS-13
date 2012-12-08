#ifndef INTEGER_SEMAPHORE_H
#define INTEGER_SEMAPHORE_H

#include <cstdio>
#include <cstdlib>
#include <Windows.h>

#define PRODUCER_CONSUMER_SIZE 10

/**
  *结构体：临界资源
  *@date 2012/12/08
  **/
struct CRITICALRESOURCE
{
	BOOL bufferPool[PRODUCER_CONSUMER_SIZE];//缓冲池
	int n;                                                                     //缓冲池的数目
	int in;                                                                    //输入指针
	int out;                                                                 //输出指针
	int counter;                                                          //整型变量
    //初始化
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
//生产者进程
DWORD WINAPI PRODUCERPROCESS(LPVOID lpParamter);
//消费者进程
DWORD WINAPI CONSUMERPROCESS(LPVOID lpParamter);
//测试函数
BOOL INTEGER_SEMAPHORE_TEST();

#endif // INTEGER_SEMAPHORE_H