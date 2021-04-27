#include <stdio.h>
#include <string.h>
#include <malloc.h>
int SizeStr(char* str)					//size of string
{
	return strlen(str);
}
int main()
{
	int max = 100, count = 0;
	int letter[26] = { 0 };					//array for info about uniqueness letters
	int Delimiters[20] = { 0 };				//array for info about delimiters
	char* str = (char*)malloc(max * sizeof(char));
	gets_s(str, max);
	int sizeStr = SizeStr(str);
	if (!str)
	{
		printf("No memory...\n");
		return;
	}
	else
	{
		for (int i = 0; i < sizeStr; i++)
		{
			if (letter[str[i] - 97] != 1 && str[i] != ' ')	//checking for uniqueness
			{
				printf("%c", str[i]);
				letter[str[i] - 97]++;
			}
			if (str[i] == ' ')
			{
				Delimiters[count] = i;
				count++;
			}
		}
		printf("\n");
		for (int i = 0; i < count; i++)					//checking that words begin with the same letter
		{
			if (i == 0)
			{
				if (str[Delimiters[i] - 1] == str[0])
				{
					for (int j = 0; j < Delimiters[i]; j++)
					{
						printf("%c", str[j]);
					}
					printf(", ");
				}
			}
			else
			{
				if (str[Delimiters[i] - 1] == str[Delimiters[i - 1] + 1])
				{
					for (int j = Delimiters[i - 1] + 1; j < Delimiters[i]; j++)
					{
						printf("%c", str[j]);
					}
					printf(", ");
				}
			}
		}
		if (str[sizeStr - 1] == str[Delimiters[count - 1] + 1])
		{
			for (int i = Delimiters[count - 1]; i < sizeStr; i++)
			{
				printf("%c", str[i]);
			}
		}
	}
	return 0;
}