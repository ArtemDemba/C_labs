#include <stdio.h>
#include <stdlib.h>
#include "main.h"
void FromLeft(const int size, int** arr, int value, int leftBoarder, int rightBoarder, int topBoarder, int bottomBoarder)	
{
	if (value == size + 1)
	{
		return;
	}
	for (int i = leftBoarder; i <= rightBoarder; i++)
	{
		arr[topBoarder][i] = value;
		value++;
	}
	Fromtop(size, arr, value, leftBoarder, rightBoarder, topBoarder + 1, bottomBoarder);
}
void Fromtop(const int size, int** arr, int value, int leftBoarder, int rightBoarder, int topBoarder, int bottomBoarder)
{
	if (value == size + 1)
	{
		return;
	}
	for (int i = topBoarder; i <= bottomBoarder; i++)
	{
		arr[i][rightBoarder] = value;
		value++;
	}
	FromRight(size, arr, value, leftBoarder, rightBoarder - 1, topBoarder, bottomBoarder);
}
void FromRight(const int size, int** arr, int value, int leftBoarder, int rightBoarder, int topBoarder, int bottomBoarder)
{
	if (value == size + 1)
	{
		return;
	}
	for (int i = rightBoarder; i >= leftBoarder; i--)
	{
		arr[bottomBoarder][i] = value;
		value++;
	}
	FromBottom(size, arr, value, leftBoarder, rightBoarder, topBoarder, bottomBoarder - 1);
}
void FromBottom(const int size, int** arr, int value, int leftBoarder, int rightBoarder, int topBoarder, int bottomBoarder)
{
	if (value == size + 1)
	{
		return;
	}
	for (int i = bottomBoarder; i >= topBoarder; i--)
	{
		arr[i][leftBoarder] = value;
		value++;
	}
	FromLeft(size, arr, value, leftBoarder + 1, rightBoarder, topBoarder, bottomBoarder);
}
void printArray(int** arr, int cols, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int value = 1;
	int rows = 0, cols = 0;
	printf("Enter rows: ");
	scanf_s("%d\n", &rows);
	printf("Enter cols: ");
	scanf_s("%d\n", &cols);
	const int size = rows * cols;
	int** arr = (int**)malloc(rows * sizeof(int));
	for (int i = 0; i < rows; i++)
	{
		arr[i] = (int*)malloc(cols * sizeof(int));
	}
	FromLeft(size, arr, value, 0, cols - 1, 0, rows - 1);
	printArray(arr, cols, rows);
	free(arr);
	return 0;
}