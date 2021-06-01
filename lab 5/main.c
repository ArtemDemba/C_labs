#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"
#define N (64 * 1024)
struct Node* head = NULL;
int main()
{
    char array1[N], array2[N], a[4], * res, * prev_res;
    int nbits, curbits = 1;
    memset(array1, 0, sizeof(array1));
    memcpy(array2, array1, sizeof(array1));
    res = array1 + 3;
    prev_res = array2 + 3;
    while ((nbits = getdecbits(a)) > 0) {
        curbits = add3(res, prev_res - 3, curbits + 3,
            prev_res - 1, curbits + 1, a, nbits);
        memcpy(prev_res, res, curbits);
    }
    int i = 0;
    for (i = curbits - 1; i >= 0; i--)
    {
        putchar(res[i] + '0');
    }
}
int push_back(struct Node** head, int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->pPrev = NULL;
    node->pNext = NULL;
    if (*head == NULL)
    {
        *head = node;
    }
    else
    {
        struct Node* cur;
        cur = *head;
        while (cur->pNext != NULL)
        {
            cur = cur->pNext;
        }
        struct Node* temp = cur;
        cur->pNext = node;
        cur = cur->pNext;
        cur->pPrev = temp;

    }
    return 0;
}
int getdecbits(char arr[])
{
    int end = -1, a;
    if (isdigit(a = getchar())) {
        end = 0;
        a -= '0';
        push_back(&head, a);
        do {
            arr[end++] = a & 1;
        } while (a >>= 1);
    }
    return end;
}
int add3(char res[], char x3[], int l1, char x1[], int l2, char d[], int l3)
{
    int i, s = 0;
    for (i = 0; i < l3; i++) {
        s += x3[i] + x1[i] + d[i];
        res[i] = s & 1;
        s >>= 1;
    }
    for (; i < l2; i++) {
        s += x3[i] + x1[i];
        res[i] = s & 1;
        s >>= 1;
    }
    for (; i < l1 && s; i++) {
        s += x3[i];
        res[i] = s & 1;
        s >>= 1;
    }
    if (s)
        do {
            res[i++] = s & 1;
        } while (s >>= 1);
    else for (; i < l1; i++)
        res[i] = x3[i];

    return i;
}