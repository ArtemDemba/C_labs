#include "main.h"
#include <iostream>
using namespace std;
string Letters(string str)
{
    int len = str.length(), vowel = 0, consonants = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
            || str[i] == 'y')
        {
            vowel++;
        }
        else
        {
            consonants++;
        }
    }
    if (vowel > consonants)
    {
        return "More vowels";
    }
    else if (vowel < consonants)    
    {
        return "More consonants";
    }
    else
    {
        return "Vowels = consonants";
    }
}
class Node
{
public:
	int data;
	Node* left, * right;
public:
	Node(char _data)
	{
		data = _data;
		left = NULL;
		right = NULL;
	}
};
class Tree
{
public:
	Node* root = NULL;
private:
    void insert(Node* n, int d)
    {
        if (d < n->data)
        {
            if (n->left)
                insert(n->left, d);
            else
                n->left = new Node(d);
        }
        else if (d > n->data)
        {
            if (n->right)
                insert(n->right, d);
            else
                n->right = new Node(d);
        }
    }
    
public:
    void insert(int d)
    {
        if (root == NULL)
        {
            root = new Node(d);
        }
        else
        {
            insert(root, d);
        }
    }  
    void Print(Node* _root)
    {
        if (_root->left)
        {
            Print(_root->left);
        }
        cout << (char)_root->data << ' ';
        if (_root->right)
        {
            Print(_root->right);
        }
    }
};
int main()
{
    Tree tree;
    int len;
	string st;
	cin >> st;
    len = st.length();
    for (int i = 0; i < len; i++)
    {
        tree.insert(st[i]);
    }
    tree.Print(tree.root);
    cout << endl;
    cout << Letters(st) << endl;
}