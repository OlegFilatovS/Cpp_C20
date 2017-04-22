#include "other.h"
#include <string.h>
#include <stdio.h>
///////////////////////////////////////////////////

char* categoryArr[sizeOfCat] = { "fantasy","novel","science" };

double sum(double x, double y) {
	return x + y;
}

double sub(double x, double y) {
	return x - y;
}

double mul(double x, double y) {
	return x * y;
}

double div(double x, double y) {
	return x / y;
}

void Sort(char* pcFirst, int nNumber, int size,
	void(*Swap)(void*, void*), int(*Compare)(void*, void*))
{
	int i;
	for (i = 1; i<nNumber; i++)
		for (int j = nNumber - 1; j >= i; j--)
		{
			char* pCurrent = pcFirst + j*size;
			char* pPrevious = pcFirst + (j - 1)*size;
			if ((*Compare)(pPrevious, pCurrent) > 0)//требуетс€
													//переставить
				(*Swap)(pPrevious, pCurrent);
		}
}

void SwapInt(void* p1, void* p2){

		int tmp;

		tmp = *static_cast<int*>(p1);

		*static_cast<int*>(p1) = *static_cast<int*>(p2);

		*static_cast<int*>(p2) = tmp;


}

int CmpInt(void* p1, void* p2)
{
	int nResult = 0;

	if ((*static_cast<int*>(p1)) > (*static_cast<int*>(p2))) nResult = 1;
	else if ((*static_cast<int*>(p1)) < (*static_cast<int*>(p2)))  nResult = -1;

	return nResult;
}

void SwapDouble(void* p1, void* p2) {

	double tmp;

	tmp = *static_cast<double*>(p1);

	*static_cast<double*>(p1) = *static_cast<double*>(p2);

	*static_cast<double*>(p2) = tmp;


}

int CmpDouble(void* p1, void* p2)
{
	int nResult = 0;

	if ((*static_cast<double*>(p1)) > (*static_cast<double*>(p2))) nResult = 1;
	else if ((*static_cast<double*>(p1)) < (*static_cast<double*>(p2)))  nResult = -1;

	return nResult;
}


void SwapStr(void* p1, void* p2) {


	char **c1 = static_cast<char**>(p1);
	char **c2 = static_cast<char**>(p2);

	char *temp = *c1;
	*c1 = *c2;
	*c2 = temp;


}

int CmpStr(void* p1, void* p2)
{

	const char** firstString = static_cast<const char**>(p1);
	const char** secondString = static_cast<const char**>(p2);

	if (strcmp(*firstString, *secondString) > 0) return 1;

	if (strcmp(*firstString, *secondString) < 0) return -1;


	return 0;
}

const char* GetString1() {
	return "String1";
}

const char* GetString2() {
	return "String2";
}

const char* GetString3() {
	return "String3";
}

const char* GetString4() {
	return "String4";
}


void printBook(const Book &book) {
	printf(" name:%s\n author:%s\n year:%d\n category:%s\n price:%7.2f\n" ,book.name, book.author, book.year, categoryArr[book.category], book.price);
}



//«амечание: неплохо заложить в такую функцию возможность проверки
//корректности введенного значени€, например, год издани€ не может быть
//меьше, чем... (год по€влени€ письменности), категорию ползователь
//должен выбирать из существующих, цена не может быть отрицательной...

void scanBook(Book &book) {

	printf("Enter name: \n");
	scanf("%29s", &book.name);
	fflush(stdin);

	printf("Enter author:\n");
	scanf("%29s", &book.author);
	//fflush(stdin);
	fseek(stdin, 0, 0);

	printf("Enter year:\n");
	while (true) {
		scanf("%d", &book.year);
		if (book.year < -5000 || book.year > 2100)
			printf("Enter another year:\n");
		else break;
	}

	printf("Enter price:\n");
	while (true) {
		scanf("%lf", &book.price);
		if (book.price < 0)
			printf("Enter another price:\n");
		else break;
	}


	int catId = 0;

	printf("\n");

	while (true)
	{
		printf("Choose category: [0...%d]\n> ", sizeOfCat - 1);

		scanf("%d", &catId);
		fflush(stdin);

		if (catId < 0 || catId > sizeOfCat - 1) {

			printf("You've entered wrong category");
		}
		else {

			book.category = static_cast<bookCategory>(catId);
			break;
		}
	}

	


}