#include <iostream>
#include <string>
using namespace std;

template <typename T>
void sorting(T arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = i;

		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}

		swap(arr[i], arr[min]);
	}
}

int main()
{
	const int size = 5;
	int arr[size] = { 2,9,7,8,4 };

	cout << " Original Array is : ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	sorting(arr, size);

	cout << " Sorted Array is : ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	string array[size] = { "banana", "apple", "zebra", "yellow", "pink" };

	cout << " Original Array is : ";
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	sorting(array, size);

	cout << " Sorted Array is : ";
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	return 0;
}