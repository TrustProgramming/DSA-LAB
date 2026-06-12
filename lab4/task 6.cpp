#include <iostream>
using namespace std;

struct Package
{
    int id;
    string address;
    int startTime;
    int endTime;
};

class Queue {
private:
    Package arr[100];
    int front, rear;

public:
    Queue()
    {
        front = 0;
        rear = -1;
    }

    bool isEmpty() 
    {
        return front > rear;
    }

    void enqueue(Package p)
    {
        if (rear == 99) 
        {
            cout << "Queue is full\n";
            return;
        }

        arr[++rear] = p;
        cout << "Package " << p.id << " added\n";
    }

    void frontPackage() 
    {
        if (isEmpty())
        {
            cout << "No packages\n";
            return;
        }

        cout << "Front Package ID: " << arr[front].id << endl;
    }

    bool timeToDeliver(int currentTime)
    {
        if (isEmpty()) return false;

        if (currentTime >= arr[front].startTime &&
            currentTime <= arr[front].endTime)
        {
            return true;
        }

        return false;
    }

    void process(int currentTime)
    {
        if (isEmpty())
        {
            cout << "No packages to process\n";
            return;
        }

        while (!isEmpty() && currentTime > arr[front].endTime)
        {
            cout << "Package " << arr[front].id << " expired\n";
            front++;
        }

        if (isEmpty())
        {
            cout << "No valid packages left\n";
            return;
        }

        if (timeToDeliver(currentTime))
        {
            cout << "Delivered Package " << arr[front].id << endl;
            front++;
        }
        else {
            cout << "Too early to deliver Package " << arr[front].id << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "No packages in queue\n";
            return;
        }

        cout << "\nPackages in Queue:\n";
        for (int i = front; i <= rear; i++) {
            cout << "ID: " << arr[i].id
                << ", Address: " << arr[i].address
                << ", Time: [" << arr[i].startTime
                << "-" << arr[i].endTime << "]\n";
        }
    }
};

int main() {
    Queue q;
    int choice, currentTime;

    do {
        cout << "\n1. Add Package\n";
        cout << "2. Process Delivery\n";
        cout << "3. View Front\n";
        cout << "4. Display All\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        Package p;

        switch (choice)
        {
        case 1:
            cout << "Enter Package ID: ";
            cin >> p.id;

            cout << "Enter Address: ";
            cin >> p.address;

            cout << "Start Time: ";
            cin >> p.startTime;

            cout << "End Time: ";
            cin >> p.endTime;

            q.enqueue(p);
            break;

        case 2:
            cout << "Enter current time: ";
            cin >> currentTime;
            q.process(currentTime);
            break;

        case 3:
            q.frontPackage();
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