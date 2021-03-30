#include <assert.h>
#include "main.h"

void test()
{
	assert(PowerOf2(17) == 4);
	assert(PowerOf2(128) == 7);
	assert(PowerOf2(1) == 0);
	assert(PowerOf2(2) == 1);
	assert(checkM(19) == 19);
	assert(checkM(1) == 1);
}

#undef main
int main_()
{
	test();
	return 0;
}