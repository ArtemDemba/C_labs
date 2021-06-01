#ifndef LAB5_MAIN_H
#define LAB5_MAIN_H
typedef struct Node {
    int data;
    struct Node* pPrev;
    struct Node* pNext;
} node;

int push_back(struct Node** head, int data);
int getdecbits(char arr[]);
int add3(char res[], char x3[], int l1, char x1[], int l2, char d[], int l3);
#endif 