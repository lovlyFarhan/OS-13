#include "DijkstraBanker.h"

/**
 * constructed function
 * ��������������Դ�ڣ���С�����������.���������ϵͳ�������棩.�������������ӿƼ���ѧ������,2007
 * P108-111
 * ˵�������ڲ������ݱȽϸ��ӣ����캯���ĳ�ʼ�����ݿɸ����Լ���ʵ�������ȷ���������������ܴ�Ӱ�졣
 * ʱ�䣺2012-12-22
 **/
DijkstraBanker::DijkstraBanker(void)
{
	this->count = 5;
	this->vector_length = 3;
	this->Max = new int*[this->count];
	this->Allocation = new int*[this->count];
	this->Need = new int*[this->count];
	this->Avaiable = new int[this->vector_length];
	for(int i = 0;i < this->count;++i)
	{
		this->Max[i] = new int[this->vector_length];
		this->Allocation[i] = new int[this->vector_length];
		this->Need[i] = new int[this->vector_length];
	}

	char buffer[256];
	ifstream data("E:\\app\\github\\OS\\banker_algorithm\\Debug\\data.txt");
	if(!data)
	{
		system("echo read file error!");
		system("pause");
		exit(EXIT_FAILURE);
	}
	for(int i = 0;i < this->count;++i)
	{
		data.getline(buffer,256);
		sscanf(buffer,"%d %d %d %d %d %d",&this->Max[i][0],
			&this->Max[i][1],&this->Max[i][2],
			&this->Allocation[i][0],&this->Allocation[i][1],
			&this->Allocation[i][2]);
		for (int j = 0; j < this->vector_length; j++)
			this->Need[i][j] = this->Max[i][j] - this->Allocation[i][j];
	}
	data.getline(buffer,256);
	sscanf(buffer,"%d %d %d",&this->Avaiable[0],&this->Avaiable[1],&this->Avaiable[2]);
	data.close();
}

/**
 *destructor function
 **/
DijkstraBanker::~DijkstraBanker(void)
{	
	delete[] this->Avaiable;
	for(int i = 0;i < this->count;++i)
	{
		delete[] this->Max[i];
		delete[] this->Need[i];
		delete[] this->Allocation[i];
	}

	delete this->Max;
	delete this->Need;
	delete this->Allocation;

	this->count = 0;
	this->vector_length = 0;
		

}

/**
 * ���м��㷨
 **/
bool DijkstraBanker::BankerAgl(int index,int *request)
{
	for(int i = 0;i < this->vector_length;++i)
	{
		if(this->Need[index][i] < request[i] || this->Avaiable[i] < request[i])
		{
			system("echo error...");
			system("pause");
			return false;
		}
	}

	for (int i = 0; i < this->vector_length; i++)
	{
		this->Avaiable[i] -= request[i];
		this->Allocation[index][i] += request[i];
		this->Need[index][i] -= request[i];
	}
	//���Ϊͨ����ȫ�Լ�⣬��ԭ���ݣ�������ʧ���Ա���������
	if(!SecurityAgl())
	{
		for (int i = 0; i < this->vector_length; i++)
		{
			this->Avaiable[i] += request[i];
			this->Allocation[index][i] -= request[i];
			this->Need[index][i] += request[i];
		}
		return false;
	}
	return true;
}

/**
 * ��ȫ�Լ��
 */
bool DijkstraBanker::SecurityAgl()
{
	int *work = new int[this->vector_length];
	for(int i = 0; i < this->vector_length;++i)
		work[i] = this->Avaiable[i];
	bool *finish = new bool[this->count];
	for (int i = 0; i < this->count; i++)
		finish[i] = false;

	for(int i = 0;i < this->count;++i)
	{
		int j;
		for (j = 0; j < this->count; j++)
		{
			if(!finish[j])
			{
				int k;
				for(k = 0; k < this->vector_length;++k)
				{
					if(this->Need[j][k] > work[k])
						break;
				}
				if(k == this->vector_length)
				{
					for(k = 0;k < this->vector_length;++k)
						work[k] += this->Allocation[j][k];
					finish[j] = true;
					cout<<j<<' ';
					break;
				}
			}
		}
		if(j == this->count)
		{
			return false;
		}
	}
	delete[] work;
	delete[] finish;
	return true;
}

/**
 * �����ǰ�Ľ���״̬
 * ��ʾ���м��㷨��Ƶ����������ݽṹ����
 */
void DijkstraBanker::Display()
{
	cout<<"MAX:"<<endl;
	for(int i = 0;i < this->count;++i)
	{
		cout<<this->Max[i][0]<<' '<<
			this->Max[i][1]<<' '<<
			this->Max[i][2]<<endl;
	}
	cout<<"ALLOCATION:"<<endl;
	for(int i = 0;i < this->count;++i)
	{
		cout<<this->Allocation[i][0]<<' '<<
			this->Allocation[i][1]<<' '<<
			this->Allocation[i][2]<<endl;
	}
	cout<<"NEED:"<<endl;
	for(int i = 0;i < this->count;++i)
	{
		cout<<this->Need[i][0]<<' '<<
			this->Need[i][1]<<' '<<
			this->Need[i][2]<<endl;
	}
	cout<<"AVAILABLE:"<<endl;
	cout<<this->Avaiable[0]<<' '<<
		this->Avaiable[1]<<' '<<
		this->Avaiable[2]<<endl;
}

/**
 * ��ȡ��Դ�����ĳ���
 */
int DijkstraBanker::GetVectorLength()
{
	return this->vector_length;
}
