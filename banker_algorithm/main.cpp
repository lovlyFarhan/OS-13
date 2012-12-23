#include "windows.h"
#include "DijkstraBanker.h"

/**
 * 主函数：仅限测试
 **/
int main(int agrc,char *argv[])
{
	DijkstraBanker db;
	db.Display();
	if(db.SecurityAgl())
		system("echo pass");
	else
		system("echo can't get through");
	int index = 0;
	int *request = new int[db.GetVectorLength()];

	while(true)
	{
		char cmd[5]; 
		system("echo 输入'exit'退出;否则，输入'go'，继续....");
		cin>>cmd;
		if(!strcmp(cmd,"exit"))
			break;
		system("pause");
		system("cls");
		cout<<"输入进程索引：";
		cin>>index;
		cout<<"输入请求向量：";
		for(int i = 0;i < db.GetVectorLength();++i)
			cin>>request[i];
		if(db.BankerAgl(index,request))
			system("echo 分配成功");
		else
			system("echo error|分配失败，避免死锁");
		db.Display();
	}
	system("pause");
	return EXIT_SUCCESS;
}