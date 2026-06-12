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

    void insertAtBeginning(int value)
    {
        Node* temp = new Node;
        temp->next = head;
        head = temp;
    }

    void insertAtEnd(int value)
    {
        Node* temp = new Node;

        if (head == NULL)
        {
            head = temp;
            return;
        }

        Node* curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }

        curr->next = temp;
    }

    void deleteByValue(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (head->data == value)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        while (curr->next != NULL && curr->next->data != value)
        {
            curr = curr->next;
        }

        if (curr->next == NULL)
        {
            cout << "Value not found\n";
            return;
        }

        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }

    void display() const
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node* curr = head;
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

    l.insertAtBeginning(10);
    l.insertAtBeginning(5);
    l.insertAtEnd(20);
    l.insertAtEnd(30);

    cout << "List: ";
    l.display();

    l.deleteByValue(20);
    cout << "After deleting 20: ";
    l.display();

    l.deleteByValue(5);
    cout << "After deleting 5: ";
    l.display();

    return 0;
}