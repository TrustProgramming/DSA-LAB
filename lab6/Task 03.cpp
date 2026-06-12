#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class List
{
private:
    Node* head;

public:
    List()
    {
        head = NULL;
    }

    void insertAtPosition(int value, int pos)
    {
        Node* temp = new Node;

        if (pos == 1)
        {
            temp->next = head;
            head = temp;
            return;
        }

        Node* curr = head;
        for (int i = 1; i < pos - 1 && curr != NULL; i++)
        {
            curr = curr->next;
        }

        if (curr == NULL)
        {
            cout << "Invalid position\n";
            return;
        }

        temp->next = curr->next;
        curr->next = temp;
    }

    void deleteAtPosition(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (pos == 1)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        for (int i = 1; i < pos - 1 && curr->next != NULL; i++)
        {
            curr = curr->next;
        }

        if (curr->next == NULL)
        {
            cout << "Invalid position\n";
            return;
        }

        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }

    void search(int key)
    {
        Node* curr = head;
        int pos = 1;

        while (curr != NULL)
        {
            if (curr->data == key)
            {
                cout << "Element found at position " << pos << endl;
                return;
            }
            curr = curr->next;
            pos++;
        }

        cout << "Element not found\n";
    }

    void countNodes()
    {
        int count = 0;
        Node* curr = head;

        while (curr != NULL)
        {
            count++;
            curr = curr->next;
        }

        cout << "Total nodes: " << count << endl;
    }

    // Display list
    void display()
    {
        Node* curr = head;

        if (curr == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        while (curr != NULL)
        {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    List l;
    int choice, value, pos;

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at position\n";
        cout << "2. Delete at position\n";
        cout << "3. Search element\n";
        cout << "4. Count nodes\n";
        cout << "5. Display list\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value and position: ";
            cin >> value >> pos;
            l.insertAtPosition(value, pos);
            break;

        case 2:
            cout << "Enter position: ";
            cin >> pos;
            l.deleteAtPosition(pos);
            break;

        case 3:
            cout << "Enter element to search: ";
            cin >> value;
            l.search(value);
            break;

        case 4:
            l.countNodes();
            break;

        case 5:
            l.display();
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}