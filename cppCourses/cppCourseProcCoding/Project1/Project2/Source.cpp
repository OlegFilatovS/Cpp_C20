
/*************************************************************
Практическое занятие №3. Функции.
Объявление, определение, вызов.
Передача параметров. Возвращение значения.
Указатели на функции
*************************************************************/
#include <iostream>
#include <tchar.h>
#include <cstdio>
#include <cstdarg>
#include "other.h"
#include <ctime>


#define	  stop __asm nop



int _tmain()
{
	
	/////////////////////////////////////////////////////////////////////////////
	// Задание 1. Ссылки.
	//Объявите ссылку на тип double. Посредством ссылки измените значение

	double someX = 1.1;

	double& refF = someX;
	

	refF = 2.2;




	//Раскомментируйте  следующую строчку. Что следует сделать, чтобы
	//linker не выдавал ошибки при создании exe-файла. Подсказка: ref - это
	//внешняя по отношению к данному файлу ссылка!

	//extern int& ref;

	ref++;




	//Раскомментируйте следующую строку. Что следует сделать, чтобы
	//компилятор не выдавал ошибки

	const int& ref1 = 1;



	//Задан указатель:



	char c='A';
	char* pc = &c;

	//Объявите ссылку на указатель. Посредством ссылки измените

	char*& refToPtr = pc;

	//а) значение по адресу

	*refToPtr = 'B';

	//б) сам адрес

	refToPtr++;


	


	//Задание 2. Отличия при передаче параметров а) по значению,
	// б) по ссылке, в) по указателю
	//Объявите и определите три функции , которые увеличивают заданное
	//с помощью параметра значение на 1 ( а) - IncByValue(),
	// б) - IncByPointer(), в) - IncByReference() ). 
	//Проверьте правильность с помощью отладчика.
	//
	//Замечание: объявления функций принято помещать в заголовочный файл
	std::cout << std::endl;
	std::cout << "\nTask 2 " << std::endl;

	

	int val = 1;//значение этой переменной должно быть увеличено с помощью
				//каждой из функций на единицу

	int res = IncByValue(val); 



	std::cout << "\nVal value: " << val << std::endl;

	IncByPointer(&val);

	std::cout << "\nVal value: " << val << std::endl;

	IncByReference(val);


	std::cout << "\nVal value: " << val << std::endl;
	

		
	//Задание 2а. Передача параметров c помощью указателя и по ссылке.
	//Перегруженные имена функций.
	std::cout << std::endl;
	std::cout << "\nTask 2a " << std::endl;
	//Создайте функцию (функции) Swap(), которая меняет значения
	//переменных nX и nY местами.

		int	nX = 1;
		int nY = -1;

		std::cout << "\nNx before swap: " <<nX<< std::endl;
		std::cout << "\nNy before swap: " <<nY<< std::endl;


		// а)Функция должна принимать два указателя на int, оперируя с
		//которыми менять значения переменных в вызывающей программе

		Swap(&nX,&nY);	//поменяли местами значения nX и nY с
		//помощью указателей на nX и nY

		std::cout << "\nNx after first swap: " << nX << std::endl;
		std::cout << "\nNy after first swap: " << nY << std::endl;

		// б)Функция должна принимать две ссылки на int
		//Проверьте правильность с помощью приведенного ниже фрагмента.

		Swap(nX,nY);	//а теперь обратно с помощью ссылок на nX и nY

		std::cout << "\nNx after second swap: " << nX << std::endl;
		std::cout << "\nNy after second swap: " << nY << std::endl;
		



	//Задание 3. Указатели на массивы в качестве аргументов.
	//3a.Напишите два варианта функции поиска минимального элемента
	//1. во встроенном двухмерном массиве


	//2. в динамическом двухмерном массиве (обе размерности вычисляются)

	//1.Например:

		std::cout << std::endl;
		std::cout << "\nTask 3 " << std::endl;

		srand(time(0));

		int ar[N][M] = {9,8,7,6,5,6,7,1,9}; //подумайте - как и где должны быть заданы N и M
		
		int **pn = new int*[N];


		std::cout << "\nDynamic array: " << std::endl;

		for (int i = 0; i < N; ++i) {

			pn[i] = new int[M];

			for (int j = 0; j < M; ++j) {
				pn[i][j] = rand() % 10;

				std::cout << pn[i][j] << " ";
			}
			std::cout << std::endl;
		}


		std::cout << "\nStatic array: " << std::endl;

		for (int i = 0; i < N; i++) {

			for (int j = 0; j< M; j++){

			std::cout << " " << ar[i][j];

			}

			std::cout << std::endl;

		}
	
		int res = MinOfStaticArr(ar, sizeof(ar)/sizeof(int));

		int res1 = MinOfDynamicArr(pn, N,M);

		
		std::cout << std::endl;

		std::cout << "\nMinimun of dynamic array is: " << res1 << std::endl;

		std::cout << "\nMinimun of static array is: " << res << std::endl;

			
		for (int i = 0; i < M; ++i) {
			delete[] pn[i];
		}

		delete[] pn;
	

		
		//3b. Напишите функцию сравнения двух строк - MyStrCmp():
		//Функция должна принимать два указателя на сравниваемые
		//строки (возможно Вы должны указать компилятору, что функция
		//не имеет права модифицировать содержимое строк)
		//Функция должна возвращать отрицательное значение, если
		//первая строка лексиграфически меньше второй, 0 - если
		//они равны и положительное значение, если первая строка
		//больше второй.
		//Вспомните, что признаком конца строки является нулевой байт.

		std::cout << std::endl;
		std::cout << "\nTask 3b" << std::endl;


		//Создайте две строки для сравнения:


		

		const char* firstString = "Aqwerty";

		std::cout << "\nFirst string value is: " << firstString << std::endl;

		

		const char* secondString = "Bqwerty";

		std::cout << "\nSecond string value is: " << secondString << std::endl;

		//Вызовите функцию сравнения

		int resOfStrCmp = MyStrCmp(firstString, secondString);

		//Выведите результат сравнения с помощью cout:

		switch (resOfStrCmp)
		{

		case 1: {
			std::cout << "\nFirst string is bigger then second " << std::endl;
			break;	
		}

		case -1: {
			std::cout << "\nSecond string is bigger then first " << std::endl;
			break;	
		}

		default:
				std::cout << "\nStrings are equal " << std::endl;
			break;
		}


		stop

			
		//Задание 4.Ссылки в качестве параметров. Передача указателя на встроенный
		//массив в качестве пар аметра функции.

		std::cout << std::endl;
		std::cout << "\nTask 4" << std::endl;

		//Напишите две взаимодополняющие друг друга функции:
		//1.  ... DayOfYear(...)
		//- преобразует день месяца (число,месяц и год задаются в качестве параметров)
		//в порядковый день года(возвращаемое значение)


		int day = 20;

		int month = 11;

		int year = 2012;

		std::cout << "\nYear is: " << year << std::endl;
		std::cout << "\nMonth is: " << month << std::endl;
		std::cout << "\nDay of month is: " << day << std::endl;

		//В процессе вычислений Вам придется учитывать "високосный - невисокосный" год.
		//Для этого предлагается в каждую функцию в качестве одного из параметров передавать
		//данные приведенного ниже двухмерного массива nDayTab

		int nDayTab[2][12] = {
			{ 31,28,31,30,31,30,31,31,30,31,30,31 }, //невисокосный год
			{ 31,29,31,30,31,30,31,31,30,31,30,31 } };	//високосный год


		//Проверьте работоспособность обеих функций с помощью следующего фрагмента:

		//Вызов функции DayOfYear

		int dayOfYear = DayOfYear(day,month,year, nDayTab);

		std::cout << "\nDay of year is: " << dayOfYear << std::endl;

		//2. ... DayOfMonth(...) - функция преобразует порядковый день года в день месяца
		// (принимает год и порядковый день года в качестве параметров и должна сформировать
		// день месяца и номер месяца и каким-то образом сообщить эти значения вызывающей процедуре)

		int numOfMonth;

		int& rNumOfMonth = numOfMonth;

		//Проверка результата обратной функцией DayOfMonth

		int dayOfMonth = DayOfMonth(dayOfYear, year, rNumOfMonth, nDayTab);

		std::cout << "\n|After function call|Day of month is: " << dayOfMonth << "\n\n|After function call|Month is: "<< numOfMonth << std::endl;




		//Задание 5. Создайте одномерный массив (размерность вычисляется в процессе
		//выполнения программы), заполните его значениями.
		//Напишите функцию, которая добавляет в массив новое значение только при условии,
		//что такого значения в массиве еще нет. Подсказка: при этом размер
		//массива должен увеличиться!
		//Для проверки напишите функцию, которая выводит значения всех элементов на экран


		int* arrT5 = new int[N];

		for (int i = 0; i < N; i++) {

			arrT5[i] = i;

		}

		std::cout << "\nOld array is: " << std::endl;

		printArray(arrT5,N);

		int newVal = 66;

		std::cout << "\nNew array is: " << std::endl;

		int numberOfElems = (addNewValToArr(arrT5, N, newVal) ? (N + 1) : N);  ///??????????????

		printArray(arrT5, numberOfElems);

		delete[] arrT5;


		//Задание 6. Рекурсивные функции. Напишите рекурсивную функцию вычисления
		//суммы первых N натуральных чисел.


		std::cout << std::endl;
		std::cout << "\nTask 6" << std::endl;

	
		std::cout <<"\nN is :"<<N<< "\nSumm of N digit is:"<< fSumRec(N) << std::endl;

		stop
		
		
		//Задание 7а. Функции с переменным числом параметров.
		//Напишите функцию (дана заготовка VarArgs, не использующая
		// макросы), которая принимает переменное число аргументов
		// типа int и выводит на печать число принятых параметров и
		// их значения.
		// Признаком конца списка является нулевое значение.

		std::cout << std::endl;
		std::cout << "\nTask 7a" << std::endl;


		int nN1=5, nN2=11, nN3=4, nN4=7, nN5=-1;

		VarArgs(nN1,0);
		VarArgs(nN1,nN2,0);
		VarArgs(nN1,nN2,nN3,nN4,nN5,0);

		stop



		//Задание 7б. Модифицируйте функцию 5а с помощью макросов
		// va_start, va_arg, va_end

		std::cout << std::endl;
		std::cout << "\nTask 7b" << std::endl;

		VarArgsM(nN1, 0);
		VarArgsM(nN1, nN2, 0);
		VarArgsM(nN1, nN2, nN3, nN4, nN5, 0);


		system("pause");

		//Задание 8. Возвращение адреса.
		//Напишите функцию, которая находит минимальное значение в массиве,
		// таким образом, чтобы ее вызов можно было использовать слева от знака 
		// равенства: *MyMin(параметры) = 0;

		std::cout << std::endl;
		std::cout << "\nTask 8" << std::endl;


		int someArr[10] = { 1,2,3,4,5,6,7,33,22,11 };

		*MyMin(someArr, 10) = 0;


		return 0;
}//main

