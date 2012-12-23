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
	//银行家算法
	bool BankerAgl(int,int *);
	//安全性算法
	bool SecurityAgl();
	//输出数据
	void Display();
	//获取资源向量的长度
	int GetVectorLength();
private:
	//进程个数
	int count;
	//可利用资源向量的长度
	int vector_length;
	//最大需求矩阵
	int **Max;
	//分配矩阵
	int **Allocation;
	//需求矩阵
	int **Need;
	//可利用资源向量
	int *Avaiable;
};

