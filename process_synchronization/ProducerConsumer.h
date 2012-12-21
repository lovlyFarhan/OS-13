#ifndef PRODUCER_CONSUMER_H
#define PRODUCER_CONSUMER_H

#include <Windows.h>
#include <iostream>

//缓冲池的大小|缓冲区的数目
const unsigned short SIZE_OF_BUFFER = 10;

//生产者线程
DWORD WINAPI Producer(LPVOID);
//消费者线程
DWORD WINAPI Consumer(LPVOID);

//初始化数据
bool InitData();
//生产一个产品
void Produce();
//消费一个产品
void Consume();
//将新生产的产品放入缓冲池中
void Append();
//从缓冲池中取出一个产品
void Take();
//测试函数
void ProducerConsumer_Test();

#endif//PRODUCER_CONSUMER_H