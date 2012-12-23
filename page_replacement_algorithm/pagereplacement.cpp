#include "pagereplacement.h"

LRU::LRU(int count)
{
	this->count = count;
	this->physicalBlock = new int[count];
	for(int i = 0;i < count;++i)
		this->physicalBlock[i] = EMPTY;
	this->length = 0;
	this->times = 0;
	this->stack = new list<int>();
}

LRU::~LRU()
{
	delete[] this->physicalBlock;
	delete this->stack;
	this->count = 0;
	this->length = 0;
}

void LRU::PAGE_REPLACEMENT_TEST()
{
	int pageRefIndex;
	system("echo 输入-1退出程序；输入-2查看栈信息；输入其它数值表示页面号。\n建议输入值区间为[-2,20].");
	system("pause");
	system("cls");
	while (true)
	{
		this->printPhysicalBlock();
		cout<<"输入进程要访问的页面号：";
		cin>>pageRefIndex;
			
		if(pageRefIndex == -1)
			break;
		else if(pageRefIndex == -2)
		{
			for(list<int>::iterator i = this->stack->begin();i != this->stack->end();++i)
				cout<<*i<<' ';

			cout<<"\n输入进程要访问的页面号：";
			cin>>pageRefIndex;
		}
		if(this->length < this->count)
		{
			int i = 0;
			for(;i < this->length;++i)
			{
				if(this->physicalBlock[i] == pageRefIndex)
				{
					this->stack->remove(pageRefIndex);
					this->stack->push_front(pageRefIndex);
					break;
				}
			}
			if(i == this->length)
			{
				this->physicalBlock[this->length++] = pageRefIndex;
				this->stack->remove(pageRefIndex);
				this->stack->push_front(pageRefIndex);
			}
		}
		else
		{
			this->length++;
			int i = 0;
			for(;i < this->count;++i)
			{
				if(this->physicalBlock[i] == pageRefIndex)
				{
					this->stack->remove(pageRefIndex);
					this->stack->push_front(pageRefIndex);
					break;
				}
			}
			if(i == this->count)
			{
				int temp = this->stack->back();
				this->stack->pop_back();
				for(int j = 0;j < this->count;j++)
				{
					if(this->physicalBlock[j] == temp)
					{
						cout<<"页面"<<pageRefIndex<<"置换页面"<<physicalBlock[j]<<endl;
						this->physicalBlock[j] = pageRefIndex;
						this->stack->remove(pageRefIndex);
						this->stack->push_front(pageRefIndex);
						this->times++;
						break;
					}
				}
			}
		}
	}
	cout<<"进程访问页面次数："<<this->length<<"页面置换次数"<<this->times<<endl;
}


void LRU::printPhysicalBlock()
{
	cout<<"物理块中的页面号：";
	for(int i = 0;i < this->count;++i)
	{
		if(this->physicalBlock[i] != EMPTY)
			cout<<' '<<this->physicalBlock[i];
		else
			cout<<"_ ";
	}
	cout<<endl;
}