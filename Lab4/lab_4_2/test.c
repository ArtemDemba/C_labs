#include <assert.h>
#include <stdio.h>
#include"main.h"
#define _CRT_SECURE_NO_WARNINGS
int main_()
{
	char t1[] = "test1.txt";
	char t2[] = "test2.txt";
	char t3[] = "test3.txt";
	FILE* test1 = fopen(t1, "r");
	FILE* test2 = fopen(t2, "r");
	FILE* test3 = fopen(t3, "r");
	assert(Avg(test1) == 2.400);
	assert(Avg(test2) == 6.000);
	assert(Avg(test3) == 1.500);
	fclose(t1);
	fclose(t2);
	fclose(t3);
	return 0;
}