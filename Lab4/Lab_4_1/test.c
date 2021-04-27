#include <assert.h>
#include "header.h"
int main_()
{
	char test1[] = "123";
	char test2[] = "";
	char test3[] = "123456789";
	assert(SizeStr(test1) == 3);
	assert(SizeStr(test2) == 0);
	assert(SizeStr(test3) == 9);
}

