#include <iostream>
#include <string>
#include "LibraryItem.h"
using namespace std;

template <class T>
int linearSearch(T arr[], int size, T key)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}
	return -1;
}

template <class T>
int binarySearch(T arr[], int size, T key)
{
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] == key)
		{
			return mid;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return -1;
}
Book::Book()
{
	title = "\0";
	author = "\0";
	pages = 0;
}
Book::Book(string tit, string auth, int pag)
{
	title = tit;
	author = auth;
	pages = pag;
}
string Book::getTitle()
{
	return title;
}
int Book::getPages()
{
	return pages;
}
void Book::display()
{
	cout << "\n----- Book Details -----\n";
	cout << endl;
	cout << " Title : " << title << endl;
	cout << " Author : " << author << endl;
	cout << " Pages : " << pages << endl;
}
bool Book::operator==(const Book& b)
{
	return title == b.title;
}
bool Book::operator<(const Book& b)
{
	return pages < b.pages;
}
Newspaper::Newspaper()
{
	name = "\0";
	date = "\0";
	edition = "\0";
}
Newspaper::Newspaper(string nam, string dat, string edit)
{
	name = nam;
	date = dat;
	edition = edit;
}
string Newspaper::getName()
{
	return name;
}
string Newspaper::getEdition()
{
	return edition;
}
void Newspaper::display()
{
	cout << "\n----- Newspaper Details -----\n";
	cout << endl;
	cout << " Name : " << name << endl;
	cout << " Date : " << date << endl;
	cout << " Edition : " << edition << endl;
}
bool Newspaper::operator==(const Newspaper& n)
{
	return name == n.name;
}
bool Newspaper::operator<(const Newspaper& n)
{
	return edition < n.edition;
}
Library::Library()
{
	bookCount = 0;
	newsCount = 0;
}
void Library::addBooks(Book b)
{
	books[bookCount++] = b;
}
void Library::addNewspaper(Newspaper n)
{
	newspaper[newsCount++] = n;
}
void Library::sortBooks()
{
	for (int i = 0; i < bookCount; i++)
	{
		for (int j = 0; j < bookCount - i - 1; j++)
		{
			if (books[j + 1] < books[j])
			{
				Book temp = books[j];
				books[j] = books[j + 1];
				books[j + 1] = temp;
			}
		}
	}
}
void Library::sortNewspaper()
{
	for (int i = 0; i < newsCount; i++)
	{
		for (int j = 0; j < newsCount; j++)
		{
			if (newspaper[j + 1] < newspaper[j])
			{
				Newspaper temp = newspaper[j];
				newspaper[j] = newspaper[j + 1];
				newspaper[j + 1] = temp;
			}
		}
	}
}
void Library::displayDetails()
{
	cout << "\n------ Books in Library ------\n";
	for (int i = 0; i < bookCount; i++)
	{
		books[i].display();
	}

	cout << "\n------ Newspapers in Library ------\n";
	for (int i = 0; i < newsCount; i++)
	{
		newspaper[i].display();
	}
}
Book* Library::searchBookByTitle(string title)
{
	Book key(title, "", 0);

	int index = linearSearch(books, bookCount, key);

	if (index != -1)
	{
		return &books[index];
	}
	return NULL;
}
Newspaper* Library::searchNewspaperByName(string name)
{
	Newspaper key(name, "", "");

	int index = linearSearch(newspaper, newsCount, key);

	if (index != -1)
	{
		return &newspaper[index];
	}
	return NULL;
}
