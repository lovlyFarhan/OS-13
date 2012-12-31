#include "MultIndexFCB.h"

int main()
{
	int blockSize;
	int block;
	cout<<"输入页面块大小(默认为4KB)> ";
	cin>>blockSize;
	cout<<"输入块所占空间(默认为4B)> ";
	cin>>block;
	system("cls");
	MultIndexFCB(blockSize,block).MULT_INDEX_FCB_TEST();
	return 0;
}
