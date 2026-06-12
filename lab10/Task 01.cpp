#include <iostream>
using namespace std;

int sumArray(int arr[], int size)
{
	if (size == 0)
	{
		return 0;
	}

	return arr[size - 1] + sumArray(arr, size - 1);
}


int main()
{
	const int SIZE = 5;
	int arr[SIZE] = { 12,14,15,17,20 };

	int result = sumArray(arr, SIZE);

	cout << " Sum of Array is : " << result << endl;

	return 0;
}