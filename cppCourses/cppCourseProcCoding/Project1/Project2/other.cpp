#include "other.h"
#include <iostream>
#include <cstdarg>
///////////////////////////////////////////////////

int x = 1;

int& ref = x;


int IncByValue(int a) {

	a++;

	return a;
}


void IncByPointer(int* const a) {

	(*a)++;
}


void IncByReference(int& a) {

	a++;
}


void Swap(int* const a, int* const b) {


	*a = *a + *b;

	*b = *a - *b;

	*a = *a - *b;

}


void Swap(int& a, int& b) { // только для целых

	a = a^b;

	b = a^b;

	a = a^b;


}


int MinOfDynamicArr(int** arr, size_t n,size_t m) {

	int Min = arr[0][0];

	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j){

			if (arr[i][j] < Min)

				Min = arr[i][j];

			}
		}

	return Min;

}

int MinOfStaticArr(int(*arr)[3], int size) {

	int Min = arr[0][0];

	int* pTmp = arr[0] + 1;


	for (int i=0; i < size-1; i++){
	
		if (Min > *pTmp) Min = *pTmp;

		pTmp++;
	
	}


	return Min;


}


int MyStrCmp(const char* firstString,const char* secondString) {

	int comparationRes = 0;
	int count = 0;

	while (firstString[count] || secondString[count]) {

		if (firstString[count] > secondString[count]) {

			comparationRes = -1;
			break;
		}
			
		else if (firstString[count] < secondString[count])  {

			comparationRes = 1;
			break;

		 }
			
		 else  comparationRes = 0;

		 count++;

	}

	return comparationRes;
}


int DayOfYear(int day, const int month, const int year, const int  arr[2][12])
{
	bool isLeapYear = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));

	for (int j = 0; j < month - 1; ++j)
	{
		day += arr[isLeapYear][j];
	}

	return (day);
}


int DayOfMonth(int dayOfYear, const int year, int& rNumOfMonth, const int arr[2][12]) {

	bool isLeapYear = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));

	int Num = 1;

	for (int i = 0; dayOfYear > arr[isLeapYear][i]; i++)
	{
		dayOfYear -= arr[isLeapYear][i];
		Num++;
	}

	rNumOfMonth = Num;

	return dayOfYear;

}


int fSumRec(int N) {

	if (N <= 0) return 0;

	else {

		return fSumRec(N - 1) + N;
	}


}

bool isArrHaveDuplicate(int* const arr, int size, int duplicate)
{

	for (int i = 0; i < size; i++) {

		if (duplicate == arr[i]) return true;

		}

	return false;
	
}

void reAlloc(int*& arr, int oldSize) {


	int* newArr = new int[oldSize * 2];

	for (int i = 0; i < oldSize; i++) {
		
		newArr[i] = arr[i];
	}

	delete[] arr;

	arr = newArr;

	

}

bool addNewValToArr(int*& arr, int size, int newVal) {

	if (!isArrHaveDuplicate(arr, size, newVal)) {

		reAlloc(arr, size);

		arr[size] = newVal;

		return true;
	}

	return false;

}



	void printArray(const int* const arr, int size) {

	for (int i = 0; i < size; i++) {


	std::cout << " " << arr[i];

}

	std::cout << std::endl;

}


//Подсказка-заготовка для задания 7а
//Без использования макросов

void VarArgs(int arg1,...)
{
int number = 0;	//счетчик элементов

int* p = &arg1;
//Объявите указатель на int и инициализируйте его адресом
//первого аргумента

//Пока не достигнут конец списка:
// а) печать значения очередного аргумента
// б) модификация указателя (он должен указывать на
//следующий аргумент списка)
// в) увеличить счетчик элементов

std::cout << "\nArgs in funtion: " << std::endl;

while (*p) {

	std::cout << *p << " ";

	p++;

	number++;

}

//Печать числа элементов

std::cout <<"\nNumber of args in funtion: "<< number << " "<<std::endl;

}


void VarArgsM(int arg1, ...) {

	int number = 0;	

	int i = arg1;

	va_list p;

	va_start(p,arg1);

	std::cout << "\nArgs in funtion: " << std::endl;

	while (i) {

		i = va_arg(p, int);

		std::cout << i << " ";

		number++;

	}

	std::cout << "\nNumber of args in funtion: " << number << " " << std::endl;


}


int *MyMin(const int *ar, size_t size) {

	int minIndex = 0;

	for (size_t i = 1; i < size; ++i) {

		if (ar[minIndex] > ar[i])
			minIndex = i;

	}

	return const_cast<int*>(&ar[minIndex]);
}



