#include "windows.h"
#include "pagereplacement.h"

/**
 * 主函数：仅限测试
 **/
int main(int agrc,char *argv[])
{
	PageReplacement lru(3);
	lru.PAGE_REPLACEMENT_LUR_TEST();
	system("pause");
	return EXIT_SUCCESS;
}