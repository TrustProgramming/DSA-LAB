#pragma once

#include <string>
using namespace std;

class LibraryItem
{
public:
	virtual void display() = 0;
};

class Book : public LibraryItem
{
private:
	string title;
	string author;
	int pages;
public:
	Book();
	Book(string tit, string auth, int pag);

	string getTitle();
	int getPages();

	void display();

	bool operator==(const Book& b);
	bool operator<(const Book& b);
};

class Newspaper : public LibraryItem
{
private:
	string name;
	string date;
	string edition;
public:
	Newspaper();
	Newspaper(string nam, string dat, string edit);

	string getName();
	string getEdition();

	void display();

	bool operator==(const Newspaper& n);
	bool operator<(const Newspaper& n);
};

class Library
{
private:
	Book books[50];
	Newspaper newspaper[50];
	int bookCount;
	int newsCount;
public:
	Library();

	void addBooks(Book b);
	void addNewspaper(Newspaper n);
	void sortBooks();
	void sortNewspaper();

	void displayDetails();

	Book* searchBookByTitle(string title);
	Newspaper* searchNewspaperByName(string name);
};