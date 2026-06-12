#include <iostream>
using namespace std;

class node
{
public:
	int data;
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
	void addPatient(int id)
	{
		node* temp = new node;
		temp->data = id;
		temp->next = NULL;

		if (rear == NULL)
		{
			rear = temp;
			front = temp;
		}
		else
		{
			rear->next = temp;
			rear = temp;
		}
	}
	void removePatient()
	{
		if (isEmpty())
		{
			cout << " Queue is Empty ! " << endl;
			return;
		}

		node* temp = front;
		front = front->next;

		if (front == NULL)
		{
			rear = NULL;
		}
		delete temp;
	}
	void cancelAppointment(int val)
	{
		node* curr = front;
		node* prev;

		while (curr->next != NULL)
		{
			prev = curr;
			curr = curr->next;

			if (val == curr->data)
			{
				prev->next = curr->next;
				delete curr;
			}
		}
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
			curr = curr->next;
		}
	}
	int countPatient()
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
};

int main()
{
	Queue q;

	int choice;
	int id;
	int val;

	do
	{
		cout << "\n--- Main Menu ---\n";
		cout << "1. Add Patient " << endl;
		cout << "2. Remove Patient " << endl;
		cout << "3. Cancel Appointment " << endl;
		cout << "4. Display IDs " << endl;
		cout << "5. Patient Count " << endl;
		cout << "6. Exit " << endl;
		cout << "Enter your choice : " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter ID of Patient : ";
			cin >> id;
			q.addPatient(id);
			break;

		case 2:
			q.removePatient();
			break;

		case 3:
			cout << "Enter ID to cancel appointment : ";
			cin >> val;
			q.cancelAppointment(val);
			break;

		case 4:
			q.display();
			break;

		case 5:
			int res = q.countPatient();
			cout << "Total Patients : " << res << endl;
			break;

		case 6:
			cout << "Exiting Program ...... " << endl;
			break;

		default:
			cout << "Invalid Choice. Try Again !! " << endl;
		}
	} while (choice != 6);

	return 0;
}