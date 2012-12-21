#ifndef PRODUCER_CONSUMER_H
#define PRODUCER_CONSUMER_H

#include <Windows.h>
#include <iostream>

//����صĴ�С|����������Ŀ
const unsigned short SIZE_OF_BUFFER = 10;

//�������߳�
DWORD WINAPI Producer(LPVOID);
//�������߳�
DWORD WINAPI Consumer(LPVOID);

//��ʼ������
bool InitData();
//����һ����Ʒ
void Produce();
//����һ����Ʒ
void Consume();
//���������Ĳ�Ʒ���뻺�����
void Append();
//�ӻ������ȡ��һ����Ʒ
void Take();
//���Ժ���
void ProducerConsumer_Test();

#endif//PRODUCER_CONSUMER_H