#include <iostream>
using namespace std;

class Queue
{
private:
    int arr[100];
    int front, rear;

public:
    Queue()
    {
        front = 0;
        rear = -1;
    }

    void enqueue(int ticket_id) 
    {
        if (rear == 99)
        {
            cout << "Queue is full\n";
            return;
        }

        if (ticket_id<1000|| ticket_id>9999)
        {
            cout << "Invalid Ticket ID (must be 4 digits)\n";
            return;
        }

        arr[++rear] = ticket_id;
        cout << "Ticket " << ticket_id << " added\n";
    }


    void dequeue() {
        if (isEmpty()) {
            cout << "No tickets to resolve\n";
            return;
        }

        cout << "Resolved Ticket: " << arr[front] << endl;
        front++;
    }

    void getFront() 
    {
        if (isEmpty()) 
        {
            cout << "No pending tickets\n";
            return;
        }

        cout << "Next Ticket: " <<arr[front] << endl;
    }

    bool isEmpty() 
    {
        return front > rear;
    }

    void display()
    {
        if (isEmpty()) 
        {
            cout << "No pending tickets\n";
            return;
        }

        cout << "Pending Tickets: ";
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
    int choice, ticket;

    do
    {
        cout << "\n1. Add Ticket\n";
        cout << "2. Resolve Ticket\n";
        cout << "3. View Next Ticket\n";
        cout << "4. Display Tickets\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter 4-digit Ticket ID: ";
            cin >> ticket;
            q.enqueue(ticket);
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