#include "windows.h"
#include "pagereplacement.h"

/**
 * �����������޲���
 **/
int main(int agrc,char *argv[])
{
	PageReplacement lru(3);
	lru.PAGE_REPLACEMENT_LUR_TEST();
	system("pause");
	return EXIT_SUCCESS;
}