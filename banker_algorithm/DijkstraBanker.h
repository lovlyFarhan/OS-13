#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class DijkstraBanker
{
public:
	DijkstraBanker(void);
	~DijkstraBanker(void);
	//���м��㷨
	bool BankerAgl(int,int *);
	//��ȫ���㷨
	bool SecurityAgl();
	//�������
	void Display();
	//��ȡ��Դ�����ĳ���
	int GetVectorLength();
private:
	//���̸���
	int count;
	//��������Դ�����ĳ���
	int vector_length;
	//����������
	int **Max;
	//�������
	int **Allocation;
	//�������
	int **Need;
	//��������Դ����
	int *Avaiable;
};

