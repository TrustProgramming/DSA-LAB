#include <iostream>
using namespace std;

class node
{
public:
	int playerID;
	int score;
	node* next;
	node* prev;
};

class list
{
private:
	node* head;
	node* tail;

public:
	list()
	{
		head = NULL;
		tail = NULL;
	}
	void addPlayer(int id, int sc)
	{
		node* temp = new node;
		temp->playerID = id;
		temp->score = sc;
		temp->next = NULL;
		temp->prev = NULL;

		if (head == NULL && tail == NULL)
		{
			head = temp;
			tail = temp;
			head->next = head;
			head->prev = head;
		}
		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
			tail->next = head;
			head->prev = tail;
		}
	}
	void removePlayer(int id)
	{
		node* curr = head;

		do
		{
			if (curr->playerID == id)
			{
				node* temp = curr;

				if (curr == head)
				{
					head = head->next;
					tail->next = head;
					head->prev = tail;
					curr = head;
				}
				if (curr == tail)
				{
					tail = tail->prev;
					tail->next = head;
					head->prev = tail;
					curr = tail;
				}
				else
				{
					curr->prev->next = curr->next;
					curr->next->prev = curr->prev;
					curr = curr->next;
				}

				delete temp;
				return;
			}
			else
			{
				curr = curr->next;
			}

		} while (curr != head);
	}
	void display() const
	{
		node* curr = head;

		do
		{
			cout << " Player ID : " << curr->playerID << " | " << " Score : " << curr->score << endl;
			curr = curr->next;
		} while (curr != head);
	}
};

int main()
{
	list obj;

	obj.addPlayer(1, 30);
	obj.addPlayer(2, 40);
	obj.addPlayer(3, 50);
	obj.addPlayer(4, 60);
	obj.addPlayer(5, 70);
	obj.display();
	cout << endl;

	obj.removePlayer(3);
	obj.display();
	cout << endl;

	return 0;
}