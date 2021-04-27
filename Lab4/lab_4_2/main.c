#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "main.h"
double Avg(FILE* file)
{
	int count = 0, a = 0;
	double avg = 0;
	do
	{
		fscanf(file, "%d", &a);			//scanning like numbers
		if (a >= 0)
		{
			count++;
			avg += a;
		}
		if (feof(file))
		{
			break;
		}
	} while (1);
	avg /= count;
	return avg;
}
int main()
{
	char name[] = "Avarage.txt";			
	FILE* file = fopen(name, "r");
	if (!fopen(name, "r"))				//checking for opening
	{
		puts("Error...");
		fclose(name);
		return 0;
	}
	else
	{
		printf("%.3lf", Avg(file));
		fclose(name);
		return 0;
	}
}
