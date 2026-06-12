#include <iostream>
using namespace std;

int Count(const char str[], int& length)
{
	if (str[length] == '\0')
	{
		return 0;
	}
	length++;

	return Count(str, length);
}
bool isPalindrome(const char str[], int start, int end)
{
	if (start >= end)
	{
		return true;
	}
	if (str[start] != str[end])
	{
		return false;
	}

	return isPalindrome(str, start + 1, end - 1);
}

int main()
{
	char str[50] = "madam";
	int length = 0;

	Count(str, length);

	bool palindrome= isPalindrome(str, 0, length - 1);

	if (palindrome == true)
	{
		cout << " String is Palindrome !! " << endl;
	}
	else
	{
		cout << " String is not Palindrome !! " << endl;
	}

	return 0;
}