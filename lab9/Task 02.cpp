#include <iostream>
#include <string>
using namespace std;

class node
{
public:
	int songID;
	string songName;
	float duration;
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
	void addSong(int id, string name, float dur)
	{
		node* temp = new node;
		temp->songID = id;
		temp->songName = name;
		temp->duration = dur;

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
	void removeSong(string name)
	{
		if (head == NULL)
		{
			cout << " Playlist is empty ! " << endl;
			return;
		}

		node* curr = head;

		while (curr != NULL)
		{
			if (curr->songName == name)
			{
				node* temp = curr;

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
	void playSong(int play)
	{
		if (head == NULL)
		{
			cout << " Playlist is empty ! " << endl;
			return;
		}

		node* curr = head;

		if (play == 1 && curr->next == NULL)
		{
			cout << " Playlist is ended. No more songs ! " << endl;
		}
		else if (play == 1 && curr->next != NULL)
		{
			curr = curr->next;

			cout << " Song ID : " << curr->songID << " | " << " Song Name : " << curr->songName
				<< " | " << " Duration : " << curr->duration << endl;
		}
		else if (play == 0 && curr == head)
		{
			cout << " No more previous songs ! " << endl;
		}
		else if (play == 0 && curr != head)
		{
			curr = curr->prev;

			cout << " Song ID : " << curr->songID << " | " << " Song Name : " << curr->songName
				<< " | " << " Duration : " << curr->duration << endl;
		}
		else
		{
			cout << " Invalid choice. Try again ! " << endl;
		}
	}
	void displayForward() const
	{
		if (head == NULL)
		{
			cout << " Playlist is empty ! " << endl;
			return;
		}

		node* curr = head;

		while (curr != NULL)
		{
			cout << " Song ID : " << curr->songID << " | " << " Song Name : " << curr->songName
				<< " | " << " Duration : " << curr->duration << endl;

			curr = curr->next;
		}
	}
	void displayBackward() const
	{
		if (head == NULL)
		{
			cout << " Playlist is empty ! " << endl;
			return;
		}

		node* curr = head;

		while (curr->next != NULL)
		{
			curr = curr->next;
		}

		while (curr != NULL)
		{
			cout << " Song ID : " << curr->songID << " | " << " Song Name : " << curr->songName
				<< " | " << " Duration : " << curr->duration << endl;

			curr = curr->prev;
		}
	}
};

int main()
{
	list obj;

	int choice, play;
	int id;
	float dur;
	string name;
	string name1;

	do
	{
		cout << " \n===== Main Menu =====\n ";
		cout << endl;
		cout << " 1. Add Song " << endl;
		cout << " 2. Delete Song " << endl;
		cout << " 3. Play next or previous ( 0 for previous, 1 for next ) " << endl;
		cout << " 4. Shuffle Playlist " << endl;
		cout << " 5. Display playlist  " << endl;
		cout << " 6. Exit " << endl;
		cout << " Enter your choice : ";
		cin >> choice;

		if (choice == 1)
		{
			cout << " Enter song ID : ";
			cin >> id;
			cout << " Enter name of song : ";
			cin >> name;
			cout << " Enter duration of song : ";
			cin >> dur;

			obj.addSong(id, name, dur);
		}
		else if (choice == 2)
		{
			cout << " Enter name of song to delete : ";
			cin >> name1;

			obj.removeSong(name1);
		}
		else if (choice == 3)
		{
			cout << " Enter your choice : ";
			cin >> play;

			obj.playSong(play);
		}
		else if (choice == 4)
		{
			obj.displayBackward();
		}
		else if (choice == 5)
		{
			obj.displayForward();
		}
		else if (choice == 6)
		{
			cout << " Exiting Program ...... " << endl;
		}
		else
		{
			cout << " Invalid choice. Try again ...... " << endl;
		}
	} while (choice != 6);

	return 0;
}