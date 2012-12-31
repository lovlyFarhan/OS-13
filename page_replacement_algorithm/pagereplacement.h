#ifndef PAGE_REPLACEMENT_H
#define PAGE_REPLACEMENT_H

#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

#define EMPTY -1 

/**
*������δʹ���û��㷨
*LEAST RECENTLY USED
**/
class PageReplacement
{
public:
	PageReplacement(int);
	~PageReplacement();
	void PAGE_REPLACEMENT_LUR_TEST();
	void printPhysicalBlock();
private:
	const static int DEFAULT_SIZE = 20;
	//�����
	int *physicalBlock;
	//��������Ŀ
	int count;
	//ҳ������ô�����
	int length;
	//
	int times;
	//ջ
	list<int> *stack;
};

#endif