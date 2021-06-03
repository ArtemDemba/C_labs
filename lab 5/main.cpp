#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
	Node(int _data)
	{
		data = _data;
		next = NULL;
	}
};
class lst
{
public:
	Node* first;
	lst()
	{
		first = NULL;
	}
	bool is_empty()
	{
		if (first == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}	
	void push_front(int _data)
	{
		Node* p = new Node(_data);
		Node* temp = first;
		if (first == NULL)
		{
			first = p;
		}
		else
		{
			p->next = first;
			first = p;
		}
	}
	void push_back(int _data)
	{
		if (first == NULL)
		{
			first = new Node(_data);
		}	
		else
		{
			Node* current = this->first;
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = new Node(_data);
		}		
	}
	void pop_front()
	{
		if (first == NULL)
		{
			return;
		}
		else
		{
			Node* p = first;
			first = first->next;
			delete p;
		}
	}
	void Print()
	{
		if (is_empty())
		{
			return;
		}
		else
		{
			Node* p = first;
			while (p != NULL)
			{
				cout << p->data << ' ';
				p = p->next;
			}
			cout << endl;
		}
	}
	void Clean()
	{
		while (first != NULL)
		{
			pop_front();
		}
	}	
};
lst Invert(lst l)
{
	lst tempList;
	Node* temp = l.first;
	while (l.first != NULL)
	{
		tempList.push_front(l.first->data);
		l.pop_front();
	}
	return tempList;
}
int main()
{
	lst l;
	l.push_back(5);
	l.push_back(10);
	l.push_front(0);
	l.push_back(20);	
	l.Print();
	Invert(l).Print();
}

