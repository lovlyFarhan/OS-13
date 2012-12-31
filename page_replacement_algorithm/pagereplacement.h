#ifndef PAGE_REPLACEMENT_H
#define PAGE_REPLACEMENT_H

#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

#define EMPTY -1 

/**
*最近最久未使用置换算法
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
	//物理块
	int *physicalBlock;
	//物理块的数目
	int count;
	//页面号引用串长度
	int length;
	//
	int times;
	//栈
	list<int> *stack;
};

#endif