#include "windows.h"
#include "pagereplacement.h"

/**
 * �����������޲���
 **/
int main(int agrc,char *argv[])
{
	LRU lru(3);
	lru.PAGE_REPLACEMENT_TEST();
	system("pause");
	return EXIT_SUCCESS;
}