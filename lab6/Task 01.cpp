#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
};

class list
{
private:
	node* head;

public:
	list()
	{
		head = NULL;
	}
	void createNode(int value)
	{
		node* curr = head;
		node* temp = new node;
		temp->data = value;
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = temp;
		}
	}
	void display() const
	{
		node* curr = head;

		while (curr != NULL)
		{
			cout << curr->data << endl;
			curr = curr->next;
		}
	}
};

int main()
{
	list l;

	l.createNode(10);
	l.createNode(20);
	l.createNode(30);

	l.display();

	return 0;
}