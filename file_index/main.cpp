#include "MultIndexFCB.h"

int main()
{
	int blockSize;
	int block;
	cout<<"����ҳ����С(Ĭ��Ϊ4KB)> ";
	cin>>blockSize;
	cout<<"�������ռ�ռ�(Ĭ��Ϊ4B)> ";
	cin>>block;
	system("cls");
	MultIndexFCB(blockSize,block).MULT_INDEX_FCB_TEST();
	return 0;
}
