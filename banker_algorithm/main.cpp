#include "windows.h"
#include "DijkstraBanker.h"

/**
 * �����������޲���
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
		system("echo ����'exit'�˳�;��������'go'������....");
		cin>>cmd;
		if(!strcmp(cmd,"exit"))
			break;
		system("pause");
		system("cls");
		cout<<"�������������";
		cin>>index;
		cout<<"��������������";
		for(int i = 0;i < db.GetVectorLength();++i)
			cin>>request[i];
		if(db.BankerAgl(index,request))
			system("echo ����ɹ�");
		else
			system("echo error|����ʧ�ܣ���������");
		db.Display();
	}
	system("pause");
	return EXIT_SUCCESS;
}