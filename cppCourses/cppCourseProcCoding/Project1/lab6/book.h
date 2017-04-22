#pragma once

enum bookCategory {
	fantasy,
	novel,
	science,
	sizeOfCat
};

struct Book {

	char author[30];
	char name[30];
	int year;
	double price;
	bookCategory category;

};

void printBook(const Book &book);

void scanBook(Book &b);

void initBook(Book &book, char* name, char* author, int year, double price, bookCategory Category);