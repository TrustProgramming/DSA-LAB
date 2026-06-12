#include <iostream>
using namespace std;

class Stack
{
private:
    int arr[100];
    int top;

public:
    Stack() 
    { 
        top = -1;
    }

    void push(int x)
    {
        arr[++top] = x;
    }

    void pop()
    {
        top--;
    }

    int peek()
    {
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

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

    void enqueue(int x)
    {
        arr[++rear] = x;
    }

    int dequeue()
    {
        return arr[front++];
    }

    int getFront()
    {
        return arr[front];
    }

    bool isEmpty()
    {
        return front > rear;
    }

    int size()
    {
        return rear-front+1;
    }

    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void reverseK(Queue& q, int k)
{
    if (k<=1||q.isEmpty())
    {
       return;
    }
    int n = q.size();
    if (k > n)
    {
        k = n;
    }
    Stack s;

    for (int i = 0; i < k; i++)
    {
        s.push(q.dequeue());
    }

    while (!s.isEmpty())
    {
        q.enqueue(s.peek());
        s.pop();
    }

    for (int i = 0; i < n - k; i++)
    {
        q.enqueue(q.dequeue());
    }
}

int main()
{
    Queue q;
    int n, x, k;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.enqueue(x);
    }

    cout << "Enter K: ";
    cin >> k;

    cout << "Original Queue: ";
    q.display();

    reverseK(q, k);

    cout << "Modified Queue: ";
    q.display();

    return 0;
}