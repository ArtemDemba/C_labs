#include <stdio.h>
#include <string.h>
#include <malloc.h>
int SizeStr(char* str)					//size of string
{
	return strlen(str);
}
char Foo(char* str);
int* Dels(char* str)
{
	int letter[26] = { 0 };			//array for info about uniqueness letters
	int Delimiters[20] = { 0 };		//array for info about delimiters
	int count = 0;
	for (int i = 0; i < SizeStr(str); i++)
	{
		if (letter[str[i] - 97] != 1 && str[i] != ' ')
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
	return Delimiters;
}
int main()
{
	int max = 100;
	char* str = (char*)malloc(max * sizeof(char));
	gets_s(str, max);
	int count = 0;
	if (!str)
	{
		printf("No memory...\n");
		return;
	}
	else
	{
		for (int i = 0; i < SizeStr(str); i++)
		{
			if (letter[str[i] - 97] != 1 && str[i] != ' ')
			{
				printf("%c", str[i]);
				letter[str[i] - 97]++;
			}
		}
		printf("\n");
		for (int i = 0; i < count; i++)
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
		if (str[SizeStr(str) - 1] == str[Delimiters[count - 1] + 1])
		{
			for (int i = Delimiters[count - 1]; i < SizeStr(str); i++)
			{
				printf("%c", str[i]);
			}
		}
	}
	return 0;
}