#include <iostream>
#include <string>
using namespace std;

class node
{
public:
	string data;
	node* next;
};

class Queue
{
private:
	node* rear;
	node* front;

public:
	Queue()
	{
		rear = NULL;
		front = NULL;
	}
	bool isEmpty() const
	{
		if (rear == NULL)
		{
			return true;
		}
		return false;
	}
	void enqueue(string regNo)
	{
		node* temp = new node;
		temp->data = regNo;
		temp->next = NULL;

		if (isEmpty())
		{
			front = temp;
			rear = temp;

		}
		else
		{
			rear->next = temp;
			rear = temp;
		}
	}
	void dequeue()
	{
		if (isEmpty())
		{
			cout << " Queue is Empty ! " << endl;
			return;
		}
		
		node* temp = front;

		if(rear==front)
		{
			rear = NULL;
			front = NULL;
		}
		else
		{
			front = front->next;
		}
		delete temp;
	}
	void removeStudent(string reg)
	{
		node* curr = front;
		node* prev = NULL;

		while (curr != NULL)
		{
			if (reg == curr->data)
			{
				prev->next = curr->next;
				delete curr;
				break;
			}
			prev = curr;
			curr = curr->next;
		}
	}
	void frontIndex()
	{
		if (isEmpty())
		{
			cout << " Queue is Empty ! " << endl;
			return;
		}
		cout << " Top of Waiting list : " << front->data << endl;
	}
	int countStudents()
	{
		node* curr = front;
		int count = 0;

		while (curr != NULL)
		{
			curr = curr->next;
			count++;
		}
		return count;
	}
	void display() const
	{
		if (isEmpty())
		{
			cout << " Queue is Empty ! " << endl;
			return;
		}

		node* curr = front;

		while (curr != NULL)
		{
			cout << curr->data << endl;
		}
	}
};

int main()
{
	int choice;
	string reg;
	int result;
	string remove;

	Queue q;

	do
	{
		cout << "\n--- Main Menu ---\n";
		cout << "1. Add Student " << endl;
		cout << "2. Returning Book " << endl;
		cout << "3. Remove Student " << endl;
		cout << "4. Top of Waiting list " << endl;
		cout << "5. Total Students " << endl;
		cout << "6. Exit " << endl;
		cout << "Enter your choice : ";
		cin >> choice;

		if (choice == 1)
		{
			cout << "Enter registration No. : ";
			cin >> reg;
			q.enqueue(reg);
		}
		else if (choice == 2)
		{
			q.dequeue();
		}
		else if (choice == 3)
		{
			cout << "Enter registration No. : ";
			cin >> remove;
			q.removeStudent(remove);
		}
		else if (choice == 4)
		{
			q.frontIndex();
		}
		else if (choice == 5)
		{
			result = q.countStudents();
			cout << " Total Students : " << result << endl;
		}
		else if (choice == 6)
		{
			cout << "Exiting Program ..... " << endl;
		}
		else
		{
			cout << "Invalid Choice. Try Again ! " << endl;
		}
	} while (choice != 6);

	return 0;
}