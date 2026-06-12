#include <iostream>
using namespace std;

void maxNumber(int arr[], int size, int& max)
{
	if (size < 0)
	{
		return;
	}
	if (arr[size] > max)
	{
		max = arr[size];
	}

	return maxNumber(arr, size - 1, max);
}

int main()
{
	const int SIZE = 5;
	int arr[SIZE] = { 22,10,14,18,20 };
	int max = 0;

	maxNumber(arr, SIZE - 1, max);

	cout << " Maximum Value in the Array is : " << max << endl;

	return 0;
}