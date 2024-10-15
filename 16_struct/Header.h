#pragma once
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::swap;
using std::to_string;

const short SIZE = 50;
struct Book
{
	char name[SIZE]{};
	char author[SIZE]{};
	char publisher[SIZE]{};
	char genre[SIZE]{};
};

void printBook(const Book& book, const string text = "");
void printBooks(const Book* library, const int& size);
void editBook(Book& book);
char* toLoweCase(const char* line);
int findByAuthor(const Book* library, const int& size, const char* author, int start = 0);
int findByTitle(const Book* library, const int& size, const char* name, int start = 0);
void sortByTitle(Book* library, const int& size); 
void sortByAuthor(Book* library, const int& size); 
void sortByPublisher(Book* library, const int& size);
void pushback(Book*& library, int& size, Book& value);