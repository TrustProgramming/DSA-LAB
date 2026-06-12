#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
};

void displayLinkedList(node* head);

class list
{
private:
	node* head;

public:
	list()
	{
		head = NULL;
	}
	void createNode(int val)
	{
		node* temp = new node;
		temp->data = val;
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			node* curr = head;

			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = temp;
		}
	}
	void display() const
	{
		if (head == NULL)
		{
			cout << " Linked List is Empty !! " << endl;
			return;
		}

		displayLinkedList(head);
	}
};

void displayLinkedList(node* head)
{
	node* curr = head;

	if (curr == NULL)
	{
		return;
	}

	cout << curr->data << " ";

	return displayLinkedList(curr->next);
}

int main()
{
	list obj;

	obj.createNode(10);
	obj.createNode(20);
	obj.createNode(30);
	obj.createNode(40);
	obj.createNode(50);

	obj.display();
}
