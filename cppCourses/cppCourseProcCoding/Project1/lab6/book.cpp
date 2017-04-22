#include "book.h"
#include <string.h>
#include <stdio.h>

char* categoryArr[sizeOfCat] = { "fantasy","novel","science" };

void printBook(const Book &book) {
	printf(" name:%s\n author:%s\n year:%d\n category:%s\n price:%7.2f\n", book.name, book.author, book.year, categoryArr[book.category], book.price);
}



//Замечание: неплохо заложить в такую функцию возможность проверки
//корректности введенного значения, например, год издания не может быть
//меьше, чем... (год появления письменности), категорию ползователь
//должен выбирать из существующих, цена не может быть отрицательной...


void initBook(Book &book,char* name,char* author,int year,double price, bookCategory Category){

	strcpy_s(book.name, 30, name);
	
	strcpy_s(book.author, 30, author);

	book.year = year;

	book.price = price;

	book.category = Category;

}



void scanBook(Book &book) {

	printf("Enter name: \n");
	scanf("%29s", &book.name);
	fflush(stdin);

	printf("Enter author:\n");
	scanf("%29s", &book.author);
	fflush(stdin);

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

