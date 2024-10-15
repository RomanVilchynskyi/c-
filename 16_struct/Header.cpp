#include "Header.h"

void printBook(const Book& book, const string text)
{
	cout << "\n\n =============================== " << text << " =============================\n";
	cout << "\t\t Title     :: " << book.name << endl;
	cout << "\t\t Author    :: " << book.author << endl;
	cout << "\t\t Publisher :: " << book.publisher << endl;
	cout << "\t\t Genre     :: " << book.genre << endl;
}

void printBooks(const Book* library, const int& size)
{
	for (size_t i = 0; i < size; i++)
	{
		printBook(library[i], "Book #" + to_string(i + 1));
	}
}

void editBook(Book& book)
{
	cout << "\t\t Enter Title     :: "; cin.getline(book.name, SIZE);
	cout << "\t\t Enter Author    :: "; cin.getline(book.author, SIZE);
	cout << "\t\t Enter Publisher :: "; cin.getline(book.publisher, SIZE);
	cout << "\t\t Enter Genre     :: "; cin.getline(book.genre, SIZE);
}

char* toLoweCase(const char* line)
{
	char* str = new char[strlen(line) + 1];
	for (size_t i = 0; i < strlen(line); i++)
	{
		str[i] = tolower(line[i]);
	}
	str[strlen(line)] = '\0';

	return str;
}

int findByAuthor(const Book* library, const int& size, const char* author, int start)
{

	for (size_t i = start; i < size; i++)
	{
		if (strcmp(toLoweCase(library[i].author), toLoweCase(author)) == 0)
			return i;
	}

	return -1;
}

int findByTitle(const Book* library, const int& size, const char* name, int start)
{
	for (size_t i = start; i < size; i++)
	{
		if (strcmp(toLoweCase(library[i].name), toLoweCase(name)) == 0)
			return i;
	}

	return -1;
}

void sortByTitle(Book* library, const int& size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (strcmp(toLoweCase(library[j].name), toLoweCase(library[j + 1].name)) > 0)
				swap(library[j], library[j + 1]);
		}
	}
}

void sortByAuthor(Book* library, const int& size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (strcmp(toLoweCase(library[j].author), toLoweCase(library[j + 1].author)) > 0)
				swap(library[j], library[j + 1]);
		}
	}
}

void sortByPublisher(Book* library, const int& size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (strcmp(toLoweCase(library[j].publisher), toLoweCase(library[j + 1].publisher)) > 0)
				swap(library[j], library[j + 1]);
		}
	}
}

void pushback(Book*& library, int& size, const Book& value)
{
	Book* tmp = new Book[size + 1]; 
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = library[i]; 
	}
	tmp[size] = value;  
	size++; 
	delete[] library; 
	library = tmp;  
}
