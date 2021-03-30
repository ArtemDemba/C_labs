#include <stdio.h>
#include <math.h>
#include <assert.h>
int checkM(int m)		//проверка на правильность ввода
{
	while (m <= 0)
	{
		printf("Incorrect input. Try again: ");
		scanf_s("%d", &m);
	}
	return m;
}
int PowerOf2(int value)
{
	int power = 0, tempPower = 0;
	while (pow(2, power) <= value)		//определение максимальной степени 2 в числе
	{
		power++;
	}
	return power - 1;
}
int main()
{
	int m = 0, maxPower = 0, tempValue = 0;
	printf("Input m: ");
	scanf_s("%d", &m);
	checkM(m);
	maxPower = PowerOf2(m);
	for (int i = 0; i <= maxPower + 1; i++)
	{
		if (pow(2, i) - 1 <= m)
		{
			if (i == 0)
			{
				tempValue = pow(2, i);
				printf("%d\t", tempValue);
				printf("1\n");
			}
			else if (i == 1)
			{
				continue;
			}
			else
			{
				tempValue = pow(2, i) - 1;
				printf("%d\t", tempValue);
				for (int j = 0; j < i; j++)
				{
					printf("1");
				}
				printf("\n");
			}
		}
		else
		{
			return;
		}
	}
}