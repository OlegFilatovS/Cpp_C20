#pragma once

//Прототипы используемых в данном задании функций:

void Sort(char* pcFirst, int nNumber, int size,

	void(*Swap)(void*, void*), int(*Compare)(void*, void*));

void SwapInt(void* p1, void* p2);

int CmpInt(void* p1, void* p2);

void SwapDouble(void* p1, void* p2);

int CmpDouble(void* p1, void* p2);

void SwapStr(void* p1, void* p2);

int CmpStr(void* p1, void* p2);

double sum(double x, double y);

double sub(double x, double y);

double mul(double x, double y);

double div(double x, double y);


const char* GetString1();

const char* GetString2();

const char* GetString3();

const char* GetString4();


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