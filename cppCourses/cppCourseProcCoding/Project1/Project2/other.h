#pragma once

extern int& ref;
/********************************

Vars and Const Declaration

********************************/

const size_t M = 3;            

const size_t N = 3;


/********************************

Functions Declarations

********************************/



/*Increment Values*/

int IncByValue(int a);

void IncByPointer(int* const a);

void IncByReference(int& a);


/*Swap*/

void Swap(int* const a, int* const b);

void Swap(int& a, int& b);


/*Search mininmum  in array*/


int MinOfDynamicArr(int** arr,size_t n, size_t m);

int MinOfStaticArr(int(*arr)[3], int size);

int *MyMin(int *ar, size_t size);

/*String compare*/

int MyStrCmp(const char* firstString,const char* secondString);

/*Counting of natural digit summ*/


int fSumRec(int N);

/*Counting day of year and month*/


int DayOfYear(int day, const int month, const int year, const int  arr[2][12]);

int DayOfMonth(int dayOfYear,const int year,int& rNumOfMonth, const int arr[2][12]);


/*Printing the array*/

void printArray(const int* const arr,int size);


/*Adding new value to array*/

bool addNewValToArr(int*& arr,int size, int newVal);

/*Funcs with var args*/

void VarArgs(int arg1, ...);

void VarArgsM(int arg1, ...);


