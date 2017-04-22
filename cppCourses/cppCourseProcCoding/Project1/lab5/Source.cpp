
/*************************************************************
Практическое занятие №5.
"Старые" потоковые функции стандартной библиотеки
Указатели на функции
Структуры
*************************************************************/
#include <tchar.h>
#include <iostream>
//#include <cstdio>
#include "other.h"
#include <cmath>


#define	  stop __asm nop

typedef const char* (*myFuncType)(void);

Book globalBook;

int _tmain()
{
	//Тема "Старые" потоковые функции стандартной библиотеки
	//Задание 1. С помощью функции scanf сформирйуте три коэффициента: A,B,C

	std::cout << "\nTask 1 old C stream functions: " << std::endl;

	int A, B, C;

	printf("Enter A,B,C : \n");

	scanf("%d%d%d", &A, &B, &C);



	//Задание 2. Выведите (красиво!) таблицу значений y=A*x*x + B*x + C
	//при изменении x в диапазоне -2 до +2 с шагом 0.5


	printf("====================\n");
	printf("| x   |  y |\n");
	printf("--------------------\n");
	for (float i = -2.0; i < 2.1; i += 0.5)
		printf("|%4.1f | %5.2f |\n", i, A*i*i + B*i + C);
	printf("====================\n");
	stop;




	///////////////////////////////////////////////////////////////////
	//Тема Указатели на функции

	//Задание 1. Указатель на функцию. "Калькулятор".
	//Напишите функции:
	//1)Sum - принимает два значения double и возвращает сумму
	//этих значений
	//2)Sub- принимает два значения double и возвращает разность
	//этих значений
	//3)Mul - *
	//4)Div - /
	//5)а для возведения в степень можете использовать функцию стандартной библиотеки
	//		- pow(). Подсказка 1: прототип функции находится в <cmath>.
	//		Подсказка 2: стандартная библиотека предоставляет несколько перегруженных
	//		вариантов этой функции, а Вам потребуется сформировать указатель на 
	//		double pow(double, double);

	//Предоставьте пользователю	следующую возможность:
	//пока пользователь хочет пользоваться услугами Вашего калькулятора,
	//он может вводить два значения и знак операции
	//а Вы выводите результат. Результат получаете посредством вызова
	//соответствующей Вашей функции по указателю.
	//Предусмотрите возможность ввода непредусмотренного знака операции

	std::cout << "\nTask 1 pointers: " << std::endl;

	int firstArg = 0, secondArg = 0;


	char oper = 0;

	double(*func)(double, double) = nullptr;

	while (true) {

		std::cout << "\nEnter values operator value: " << std::endl;
		scanf("%d %c %d", &firstArg, &oper, &secondArg);
		fflush(stdin);


		switch (oper)
		{
		case '+':
			func = sum;
			break;
		case '-':
			func = sub;
			break;
		case '/':
			func = div;
			break;
		case '*':
			func = mul;
			break;
		case '^':
			func = pow;
			break;
		default:

			std::cout << "\nUnknown operator" << std::endl;
			break;
		}


		char yN = 0;

		bool cont = false;

		if (func) std::cout << "\nResult of operation is: " << func(firstArg, secondArg) << std::endl;


		std::cout << "\nContinue? Y/N " << std::endl;

		std::cin >> yN;

		if ((yN == 'Y') || (yN == 'y')) {

			cont = true;
		}

		else if ((yN == 'N') || (yN == 'n')) {

			cont = false;

		}
		else {
			std::cout << "\nWrong Symbol" << std::endl;
			break;
		}

		func = nullptr;

		if (!cont) break;


	}


	stop

		//Задание 2. Указатель на функцию в качестве аргумента.
		//Дана заготовка функции сортировки любых объектов - Sort.
		//Функция принимает следующие параметры:
		//1) указатель на первый сортируемый элемент
		//2) количество сортируемых элементов
		//3) размер элемента в байтах
		//4) указатель на функцию перестановки элементов
		//5) указатель на функцию сравнения элементов

		std::cout << "\nTask 2 pointers: " << std::endl;



		//2a. Напишите функцию перестановки двух целых значений -
		// SwapInt, которая принимает два void указателя и 
		//меняет значения местами

	int first = 1;

	void* fPtr = &first;

	int second = 2;

	void* SPtr = &second;

	SwapInt(fPtr,SPtr);

	stop

	//Напишите функцию сравнения двух целых значений -
	// CmpInt, которая принимает два void указателя и
	//возвращает int результат сравнения: 
	//<0 - первый элемент меньше, чем второй
	//=0 - равны
	//>0 - первый элемент больше, чем второй


	int res = CmpInt(fPtr, SPtr);
		

	stop

	const int nTotal = 10;

	int nAr[nTotal] = { 556,23,4,53,1,2,44,532,543,278 };//массив для сортировки

	//Печать исходного массива

	std::cout << "\nArray before sort:" << std::endl;

	for (int i = 0; i < nTotal; i++) {

		std::cout << nAr[i] << " ";
	}


	//Вызов сортировки

			//количество элементов в массиве

	Sort(reinterpret_cast<char*>(&nAr[0]), nTotal, sizeof(int), SwapInt, CmpInt);

	//Печать результатов сортировки


	std::cout << "\nArray after sort:" << std::endl;

	for (int i = 0; i < nTotal; i++) {

		std::cout << nAr[i] << " ";
	}

	stop


		//Задание 2б. По аналогии с 8а создайте вспомогательные
		//функции - SwapDouble и CmpDouble и вызовите функцию Sort
		//для сортировки массива вещественных значений.

		std::cout << "\nTask 2b pointers: " << std::endl;

		double nArD[nTotal] = { 556.1,23.2,4.3,53.3,1.1,2.1,44.2,532.32,543.4,278.23 };//массив для сортировки

		
		std::cout << "\nArray before sort:" << std::endl;

		for (int i = 0; i < nTotal; i++) {

			std::cout << nArD[i] << " ";
		}

		std::cout << std::endl;

		Sort(reinterpret_cast<char*>(&nArD[0]), nTotal, sizeof(double), SwapDouble, CmpDouble);


		std::cout << "\nArray after sort:" << std::endl;

		for (int i = 0; i < nTotal; i++) {

			std::cout << nArD[i] << " ";
		}

		std::cout << std::endl;
	
	//Задание 2в*. По аналогии с 8а создайте вспомогательные
	//функции - SwapStr и CmpStr и вызовите функцию Sort
	//для сортировки массива указателей на строки.

		std::cout << "\nTask 2v pointers: " << std::endl;

	char* arStr[nTotal] = {"QQQ", "SDF", "ABC","fds","fdsfsd","asdfv","bvv","dsad","ewqew","zzzeq"};

	char* fS = "qwerty";

	void* fSp = &fS;

	char* sS = "asdfgh";

	void* SSp = &sS;

	SwapStr(fSp, SSp);

	stop

	std::cout << "\nArray before sort:" << std::endl;


	for (int i = 0; i < nTotal; i++) {

	std::cout << arStr[i] << " ";
	}

	std::cout << std::endl;

	Sort(reinterpret_cast<char*>(&arStr[0]), nTotal, sizeof(char*), SwapStr, CmpStr);

	
	std::cout << "\nArray after sort:" << std::endl;

	for (int i = 0; i < nTotal; i++) {

	std::cout << arStr[i] << " ";
	}

	std::cout << std::endl;

	stop
	

	
	//Задание 3. Массивы указателей на функцию.
	//Напишите несколько функций вида
	std::cout << "\nTask 3 pointers: " << std::endl;
	//const char* GetString1();
	//const char* GetString2();

	//		...., каждая из функций возвращает указатель на свою строку
	//(подумайте - какой адрес Вы имеете право возвращать из функции)

	//Объявите и проинициализируйте массив указателей на функции
	//GetString1,GetString2...


	myFuncType myArr[4] = { GetString1 ,GetString2 ,GetString3 ,GetString4 };


	//Введите номер функции, которую Вы хотите вызвать:

	int n = 2;

	//Вызовите функцию

	const char* resOfCall = myArr[n]();


	//Распечатайте результат

	std::cout << "\nString from array is:" << resOfCall << std::endl;


	//////////////////////////////////////////////////////////////////////////////////////

	//Тема. Структуры С.	


	//Задание 1. Объявите структуру BOOK, описывающую книгу
	//(автор, заглавие, год издания, цена, категория…).
	//Подумайте: какого типа могут быть поля структуры.
	//Подсказка: объявление структуры рекомендуется выносить
	//в заголовочный файл.


	//Задание 2. Создайте разными способами (глобальный, локальный, статический,
	//динамический) экземпляры (объекты) типа BOOK (без инициализации).
	//Определите - сколько памяти отводит компилятор под каждый
	//такой объект. Как инициализируются (или не инициализируются) поля
	//структуры. Подумайте: от чего зависит объем выделяемой памяти?


	Book localBook;

	Book *dynamicBook = new Book();

	Book static staticBook;
	

	size_t sizeOfBook = sizeof(localBook); //80

	sizeOfBook = sizeof(*dynamicBook); //80

	sizeOfBook = sizeof(staticBook); //80
	
	sizeOfBook = sizeof(globalBook); //80

	stop


	//Задание 3. Заполните поля созданных объектов.
	//Замечание: если для хранения строки используется массив, необходимо
	//предусмотреть "защиту" от выхода за границы массива.

	strcpy_s(localBook.author, 30, "Pushkin");
	strcpy_s(localBook.name, 30, "Onegin");
	localBook.year = 1832;
	localBook.price = 2000.00;
	localBook.category = novel;

	strcpy_s(dynamicBook->author, 30, "Tolkien");
	strcpy_s(dynamicBook->name, 30, "Lord of the Rings");
	dynamicBook->year = 1937;
	dynamicBook->price = 750.32;
	dynamicBook->category = fantasy;
	stop;

	//Задание 4. Напишите функцию, выводящую на экран реквизиты книги.
	//Подумайте: как эффективнее передавать экземпляр BOOK в функцию.
	//Для вывода на консоль используйте функцию стандартной библиотеки
	//printf

	stop

	std::cout << std::endl;
	printBook(localBook);

	std::cout << std::endl;
	printBook(*dynamicBook);



	//Задание 5. Напишите функцию для формирования полей структуры.
	//Для ввода используйте функцию стандартной библиотеки scanf
	//Замечание: неплохо заложить в такую функцию возможность проверки
	//корректности введенного значения, например, год издания не может быть
	//меьше, чем... (год появления письменности), категорию ползователь
	//должен выбирать из существующих, цена не может быть отрицательной...

	std::cout << std::endl;
	scanBook(localBook);

	std::cout << std::endl;
	printBook(localBook);

	std::cout << std::endl;
	scanBook(*dynamicBook);

	std::cout << std::endl;
	printBook(*dynamicBook);


	return 0;

}//main

