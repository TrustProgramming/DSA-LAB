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

class QueueUsingStacks
{
private:
    Stack s1, s2;

public:

    void enqueue(int x)
    {
        s1.push(x);
    }

    void dequeue()
    {
        if (s1.isEmpty() && s2.isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        if (s2.isEmpty())
        {
            while (!s1.isEmpty())
            {
                s2.push(s1.peek());
                s1.pop();
            }
        }
        cout << "Removed: " << s2.peek() << endl;
        s2.pop();
    }

    void front()
    {
        if (s1.isEmpty() && s2.isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        if (s2.isEmpty())
        {
            while (!s1.isEmpty())
            {
                s2.push(s1.peek());
                s1.pop();
            }
        }

        cout << "Front: " << s2.peek() << endl;
    }

    void display()
    {
        Stack temp1=s1;
        Stack temp2=s2;

        cout << "Queue elements: ";

        while (!temp2.isEmpty())
        {
            cout << temp2.peek()<<" ";
            temp2.pop();
        }

        Stack temp;
        while (!temp1.isEmpty())
        {
            temp.push(temp1.peek());
            temp1.pop();
        }

        while (!temp.isEmpty())
        {
            cout << temp.peek() << " ";
            temp.pop();
        }

        cout << endl;
    }
};

int main()
{
    QueueUsingStacks q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();

    return 0;
}