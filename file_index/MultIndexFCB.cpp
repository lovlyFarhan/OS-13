#include "MultIndexFCB.h"


MultIndexFCB::MultIndexFCB(int blockSize = 4,int block = 4)
{
	if(blockSize >= 2 && blockSize <= 64)
		this->BLOCK_SIZE = blockSize;
	if(block >= 2 && block <= 16)
		this->BLOCK = block;
	this->index = this->BLOCK_SIZE * KB / this->BLOCK;
}


MultIndexFCB::~MultIndexFCB(void)
{
}

bool MultIndexFCB::Allocate(int fileSize)
{
	if(fileSize > this->maxLimit())
	{
		system("echo 文件过大，无法存储。");
		return false;
	}
	int dir = 0;
	int sin = 0;
	int dou = 0;
	if(fileSize <= this->directAdressStorage())
	{
		system("echo 文件可直接地址存储，对应的盘块号：");
		dir = fileSize / this->BLOCK_SIZE;
		if(fileSize % BLOCK_SIZE)
			++dir;
		for (int i = 0; i < dir; i++)
			cout<<' '<<i;
		cout<<endl;
	}
	else if(fileSize <= this->singleIndexStorage())
	{
		dir = 3;
		sin = (fileSize - this->directAdressStorage()) / this->BLOCK_SIZE;
		if(sin % this->BLOCK_SIZE)
			sin++;
		system("echo 文件需先使用直接地址存储，盘块号：");
		for (int i = 0; i < dir; i++)
			cout<<' '<<i;
		cout<<endl;
		cout << "再使用盘块3作为一级索引块，指向" << sin << "个有效的盘块地址" << endl;
	}
	else
	{
		dir = 3;
		sin = this->index;
		dou = (fileSize - this->singleIndexStorage()) / this->BLOCK_SIZE;
		if(dou % this->BLOCK_SIZE)
			dou++;
		system("echo 文件需先使用直接地址存储，盘块号：");
		for (int i = 0; i < dir; i++)
			cout<<' '<<i;
		cout<<endl;
		cout << "再使用盘块3作为一级索引块，指向" << sin << "个有效的盘块地址" << endl;
		cout << "最后使用盘块4作为二级索引块，指向" << dou << "个有效的一级索引地址" << endl;
	}
	return true;
}

int MultIndexFCB::directAdressStorage()
{
	return 3 * this->BLOCK_SIZE;
}

int MultIndexFCB::singleIndexStorage()
{
	return this->directAdressStorage() +
		this->BLOCK_SIZE * this->index; 
}

int MultIndexFCB::doubleIndexStorage()
{
	return this->singleIndexStorage() +
		this->index * this->index * this->BLOCK_SIZE;
}

int MultIndexFCB::maxLimit()
{
	return (3 + this->index + this->index * this->index) * 
		this->BLOCK_SIZE;
}

void MultIndexFCB::MULT_INDEX_FCB_TEST()
{
	system("echo ===================== 文件混合索引分配 ===================== ");
	cout<<endl<<"页面块大小> "<< this->BLOCK_SIZE << "KB  "<<"块所占空间> "<<this->BLOCK<<'B'<<endl;
	cout << "直接地址存储大小> "<< this->directAdressStorage()<< endl;
	cout << "一级索引存储大小> "<<this->singleIndexStorage()<<endl;
	cout << "二级索引存储大小> "<<this->doubleIndexStorage()<<endl;
	cout << "注：输入非正数则退出"<< endl;
	cout << "File size(KB) > ";
	int fileSize;
	while(true)
	{
		cin>>fileSize;
		if(fileSize <= 0)
			break;
		this->Allocate(fileSize);
		system("pause");
		system("cls");
		
		cout << "File size(KB)> ";
	}
}