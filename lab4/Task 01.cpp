#include <iostream>
using namespace std;

template <typename T>
class AbstractStack
{
public:
	virtual void push(T value) = 0;
	virtual T pop() = 0;
	virtual T top() const = 0;
	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;
	virtual ~AbstractStack() {}
};

template <typename T>
class MyStack : public AbstractStack<T>
{
private:
	T* arr;
	int size;
	int topindex;
public:
	MyStack(int s)
	{
		topindex = -1;
		size = s;
		arr = new T[size];
	}
	void push(T value) override
	{
		if (isFull())
		{
			cout << " Array is Full !! " << endl;
			return ;
		}
		else
		{
			topindex++;
			arr[topindex] = value;
		}
	}
	T pop() override
	{
		if (isEmpty())
		{
			cout << " Array is Empty !! " << endl;
		}
		return arr[topindex--];
	}
	T top() const override
	{
		if (isEmpty())
		{
			cout << " Array is Empty !! " << endl;
		}
		return arr[topindex];
	}
	bool isEmpty() const override
	{
		if (topindex == -1)
		{
			return true;
		}
		return false;
	}
	bool isFull() const override
	{
		if (topindex == size - 1)
		{
			return true;
		}
		return false;
	}
};

int main()
{
	int s;
	int choice, value;

	cout << " Enter the size of Array : ";
	cin >> s;

	MyStack<int> s1(s);

	do
	{
		cout << "\n--- Stack Menu ---\n";
		cout << "1. Push " << endl;
		cout << "2. Pop " << endl;
		cout << "3. Top " << endl;
		cout << "4. Check if Empty " << endl;
		cout << "5. Check if Full " << endl;
		cout << "6. Exit " << endl;
		cout << "Enter choice: ";
		cin >> choice;

		if (choice == 1)
		{
			cout << " Enter value to push : ";
			cin >> value;
			s1.push(value);
		}
		else if (choice == 2)
		{
			s1.pop();
		}
		else if (choice == 3)
		{
			s1.top();
		}
		else if (choice == 4)
		{
			s1.isEmpty();
		}
		else if (choice == 5)
		{
			s1.isFull();
		}
		else if (choice == 6)
		{
			cout << " Exiting Program......" << endl;
		}
		else
		{
			cout << " Invalid choice !! " << endl;
		}
	} while (choice != 6);

	return 0;
}