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
		system("echo �ļ������޷��洢��");
		return false;
	}
	int dir = 0;
	int sin = 0;
	int dou = 0;
	if(fileSize <= this->directAdressStorage())
	{
		system("echo �ļ���ֱ�ӵ�ַ�洢����Ӧ���̿�ţ�");
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
		system("echo �ļ�����ʹ��ֱ�ӵ�ַ�洢���̿�ţ�");
		for (int i = 0; i < dir; i++)
			cout<<' '<<i;
		cout<<endl;
		cout << "��ʹ���̿�3��Ϊһ�������飬ָ��" << sin << "����Ч���̿��ַ" << endl;
	}
	else
	{
		dir = 3;
		sin = this->index;
		dou = (fileSize - this->singleIndexStorage()) / this->BLOCK_SIZE;
		if(dou % this->BLOCK_SIZE)
			dou++;
		system("echo �ļ�����ʹ��ֱ�ӵ�ַ�洢���̿�ţ�");
		for (int i = 0; i < dir; i++)
			cout<<' '<<i;
		cout<<endl;
		cout << "��ʹ���̿�3��Ϊһ�������飬ָ��" << sin << "����Ч���̿��ַ" << endl;
		cout << "���ʹ���̿�4��Ϊ���������飬ָ��" << dou << "����Ч��һ��������ַ" << endl;
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
	system("echo ===================== �ļ������������ ===================== ");
	cout<<endl<<"ҳ����С> "<< this->BLOCK_SIZE << "KB  "<<"����ռ�ռ�> "<<this->BLOCK<<'B'<<endl;
	cout << "ֱ�ӵ�ַ�洢��С> "<< this->directAdressStorage()<< endl;
	cout << "һ�������洢��С> "<<this->singleIndexStorage()<<endl;
	cout << "���������洢��С> "<<this->doubleIndexStorage()<<endl;
	cout << "ע��������������˳�"<< endl;
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