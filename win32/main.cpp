#include "Windows.h"

int main()
{

}
//注册窗口类
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);


	return RegisterClassEx(&wcex);
}

//创建窗口
BOOL InitInstance(HINSTANCE hInstance,int nCmdShow)
{

	return TRUE;
}