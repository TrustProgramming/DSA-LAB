#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
	node* prev;
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
	void createNode(int val)
	{
		node* temp = new node;
		temp->data = val;
		temp->next = NULL;
		temp->prev = NULL;

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
			temp->prev = curr;
			curr = temp;
		}
	}
	void insertAtHead(int val)
	{
		node* temp = new node;
		temp->data = val;
		temp->next = NULL;
		temp->prev = NULL;

		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			head->prev = temp;
			temp->next = head;
			head = temp;
		}
	}
	void insertAtPosition(int val, int pos)
	{
		if (head == NULL)
		{
			cout << " Linked List is empty ! " << endl;
			return;
		}

		node* curr = head;

		node* temp = new node;
		temp->data = val;
		temp->next = NULL;
		temp->prev = NULL;

		for (int i = 1; i < pos; i++)
		{
			curr = curr->next;
		}

		curr->prev->next = temp;
		temp->prev = curr->prev;
		temp->next = curr;
		curr->prev = temp;
	}
	void deleteByValue(int val)
	{
		if (head == NULL)
		{
			cout << " Linked List is empty ! " << endl;
			return;
		}

		node* curr = head;

		while (curr != NULL)
		{
			node* temp = curr;

			if (curr->data == val)
			{
				if (curr == head)
				{
					head = head->next;
					head->prev = NULL;
					curr = head;
					delete temp;
				}
				if (curr->next == NULL)
				{
					curr = curr->prev;
					curr->next = NULL;
					delete temp;
				}
				else
				{
					curr->prev->next = curr->next;
					curr->next->prev = curr->prev;
					curr = curr->next;
					delete temp;
				}
			}
			else
			{
				curr = curr->next;
			}
		}
	}
	void displayForward() const
	{
		if (head == NULL)
		{
			cout << " Linked List is empty ! " << endl;
			return;
		}

		node* curr = head;

		cout << " Forward Direction : ";
		while (curr != NULL)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
	}
	void displayBackward() const
	{
		if (head == NULL)
		{
			cout << " Linked List is empty ! " << endl;
			return;
		}

		node* curr = head;

		while (curr->next != NULL)
		{
			curr = curr->next;
		}

		cout << " Forward Direction : ";
		while (curr != NULL)
		{
			cout << curr->data << " ";
			curr = curr->prev;
		}
	}
};

int main()
{
	list obj;

	obj.createNode(20);
	obj.createNode(30);
	obj.createNode(50);
	obj.displayForward();
	cout << endl;

	obj.insertAtHead(10);
	obj.displayForward();
	cout << endl;

	obj.insertAtPosition(40, 4);
	obj.displayForward();
	cout << endl;

	obj.deleteByValue(40);
	obj.displayForward();
	cout << endl;

	obj.displayForward();
	obj.displayBackward();
	cout << endl;

	return 0;
}