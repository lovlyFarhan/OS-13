#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;
/**
 * 文件混合索引分配
 **/
class MultIndexFCB
{
public:
	MultIndexFCB(int,int);
	~MultIndexFCB(void);
	bool Allocate(int);
	int maxLimit();
	int directAdressStorage();
	int singleIndexStorage();
	int doubleIndexStorage();
	void MULT_INDEX_FCB_TEST();
private:
	int BLOCK_SIZE;//KB
	int BLOCK;	//B
	const static int KB = 1024;
	int index;
	int singleIndex;
	int doubleIndex;
};

