#include <iostream>
#include <string>
using namespace std;

template <typename T>
int searchTarget(T arr[], int size, T target)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == target)
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	const int size = 5;
	int arr[size] = { 20,45,62,82,10 };
	int target = 82;

	cout << " Array is : ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	int index = searchTarget(arr, size, target);

	cout << " Value found at index : " << index << endl;

	string array[size] = { "apple", "ball","yellow", "zinc","grey" };
	string value = "yellow";

	cout << " Array is : ";
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	int ind = searchTarget(array, size, value);

	cout << " Value found at index : " << ind << endl;

	return 0;
}