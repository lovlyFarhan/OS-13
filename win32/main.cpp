#include "Windows.h"

int main()
{

}
//ע�ᴰ����
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);


	return RegisterClassEx(&wcex);
}

//��������
BOOL InitInstance(HINSTANCE hInstance,int nCmdShow)
{

	return TRUE;
}