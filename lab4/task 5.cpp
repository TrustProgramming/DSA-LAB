#include <iostream>
using namespace std;

class Queue
{
private:
    string arr[100];
    int front, rear;

public:
    Queue()
    {
        front = 0;
        rear = -1;
    }

    void enqueue(string doc)
    {
        if (rear == 99) {
            cout<<"Print queue is full\n";
            return;
        }

        arr[++rear] = doc;
        cout << "Document \""<<doc<<"\" added to queue\n";
    }

    void dequeue() 
    {
        if (isEmpty())
        {
            cout << "No documents to print\n";
            return;
        }

        cout << "Printing: " << arr[front] << endl;
        front++;
    }

    void getFront() {
        if (isEmpty()) {
            cout << "No documents in queue\n";
            return;
        }

        cout << "Next document: " << arr[front] << endl;
    }

    bool isEmpty()
    {
        return front > rear;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "No pending print jobs\n";
            return;
        }

        cout << "Print Queue: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    int choice;
    string doc;

    do
    {

        cout << "\n1. Add Document\n";
        cout << "2. Print Document\n";
        cout << "3. View Next Document\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter document name: ";
            cin >> doc;
            q.enqueue(doc);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.getFront();
            break;

        case 4:
            q.display();
            break;

        case 5:
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}