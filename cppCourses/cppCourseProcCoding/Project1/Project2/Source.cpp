
/*************************************************************
������������ ������� �3. �������.
����������, �����������, �����.
�������� ����������. ����������� ��������.
��������� �� �������
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
	// ������� 1. ������.
	//�������� ������ �� ��� double. ����������� ������ �������� ��������

	double someX = 1.1;

	double& refF = someX;
	

	refF = 2.2;




	//����������������  ��������� �������. ��� ������� �������, �����
	//linker �� ������� ������ ��� �������� exe-�����. ���������: ref - ���
	//������� �� ��������� � ������� ����� ������!

	//extern int& ref;

	ref++;




	//���������������� ��������� ������. ��� ������� �������, �����
	//���������� �� ������� ������

	const int& ref1 = 1;



	//����� ���������:



	char c='A';
	char* pc = &c;

	//�������� ������ �� ���������. ����������� ������ ��������

	char*& refToPtr = pc;

	//�) �������� �� ������

	*refToPtr = 'B';

	//�) ��� �����

	refToPtr++;


	


	//������� 2. ������� ��� �������� ���������� �) �� ��������,
	// �) �� ������, �) �� ���������
	//�������� � ���������� ��� ������� , ������� ����������� ��������
	//� ������� ��������� �������� �� 1 ( �) - IncByValue(),
	// �) - IncByPointer(), �) - IncByReference() ). 
	//��������� ������������ � ������� ���������.
	//
	//���������: ���������� ������� ������� �������� � ������������ ����
	std::cout << std::endl;
	std::cout << "\nTask 2 " << std::endl;

	

	int val = 1;//�������� ���� ���������� ������ ���� ��������� � �������
				//������ �� ������� �� �������

	int res = IncByValue(val); 



	std::cout << "\nVal value: " << val << std::endl;

	IncByPointer(&val);

	std::cout << "\nVal value: " << val << std::endl;

	IncByReference(val);


	std::cout << "\nVal value: " << val << std::endl;
	

		
	//������� 2�. �������� ���������� c ������� ��������� � �� ������.
	//������������� ����� �������.
	std::cout << std::endl;
	std::cout << "\nTask 2a " << std::endl;
	//�������� ������� (�������) Swap(), ������� ������ ��������
	//���������� nX � nY �������.

		int	nX = 1;
		int nY = -1;

		std::cout << "\nNx before swap: " <<nX<< std::endl;
		std::cout << "\nNy before swap: " <<nY<< std::endl;


		// �)������� ������ ��������� ��� ��������� �� int, �������� �
		//�������� ������ �������� ���������� � ���������� ���������

		Swap(&nX,&nY);	//�������� ������� �������� nX � nY �
		//������� ���������� �� nX � nY

		std::cout << "\nNx after first swap: " << nX << std::endl;
		std::cout << "\nNy after first swap: " << nY << std::endl;

		// �)������� ������ ��������� ��� ������ �� int
		//��������� ������������ � ������� ������������ ���� ���������.

		Swap(nX,nY);	//� ������ ������� � ������� ������ �� nX � nY

		std::cout << "\nNx after second swap: " << nX << std::endl;
		std::cout << "\nNy after second swap: " << nY << std::endl;
		



	//������� 3. ��������� �� ������� � �������� ����������.
	//3a.�������� ��� �������� ������� ������ ������������ ��������
	//1. �� ���������� ���������� �������


	//2. � ������������ ���������� ������� (��� ����������� �����������)

	//1.��������:

		std::cout << std::endl;
		std::cout << "\nTask 3 " << std::endl;

		srand(time(0));

		int ar[N][M] = {9,8,7,6,5,6,7,1,9}; //��������� - ��� � ��� ������ ���� ������ N � M
		
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
	

		
		//3b. �������� ������� ��������� ���� ����� - MyStrCmp():
		//������� ������ ��������� ��� ��������� �� ������������
		//������ (�������� �� ������ ������� �����������, ��� �������
		//�� ����� ����� �������������� ���������� �����)
		//������� ������ ���������� ������������� ��������, ����
		//������ ������ ��������������� ������ ������, 0 - ����
		//��� ����� � ������������� ��������, ���� ������ ������
		//������ ������.
		//���������, ��� ��������� ����� ������ �������� ������� ����.

		std::cout << std::endl;
		std::cout << "\nTask 3b" << std::endl;


		//�������� ��� ������ ��� ���������:


		

		const char* firstString = "Aqwerty";

		std::cout << "\nFirst string value is: " << firstString << std::endl;

		

		const char* secondString = "Bqwerty";

		std::cout << "\nSecond string value is: " << secondString << std::endl;

		//�������� ������� ���������

		int resOfStrCmp = MyStrCmp(firstString, secondString);

		//�������� ��������� ��������� � ������� cout:

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

			
		//������� 4.������ � �������� ����������. �������� ��������� �� ����������
		//������ � �������� ��� ������ �������.

		std::cout << std::endl;
		std::cout << "\nTask 4" << std::endl;

		//�������� ��� ����������������� ���� ����� �������:
		//1.  ... DayOfYear(...)
		//- ����������� ���� ������ (�����,����� � ��� �������� � �������� ����������)
		//� ���������� ���� ����(������������ ��������)


		int day = 20;

		int month = 11;

		int year = 2012;

		std::cout << "\nYear is: " << year << std::endl;
		std::cout << "\nMonth is: " << month << std::endl;
		std::cout << "\nDay of month is: " << day << std::endl;

		//� �������� ���������� ��� �������� ��������� "���������� - ������������" ���.
		//��� ����� ������������ � ������ ������� � �������� ������ �� ���������� ����������
		//������ ������������ ���� ����������� ������� nDayTab

		int nDayTab[2][12] = {
			{ 31,28,31,30,31,30,31,31,30,31,30,31 }, //������������ ���
			{ 31,29,31,30,31,30,31,31,30,31,30,31 } };	//���������� ���


		//��������� ����������������� ����� ������� � ������� ���������� ���������:

		//����� ������� DayOfYear

		int dayOfYear = DayOfYear(day,month,year, nDayTab);

		std::cout << "\nDay of year is: " << dayOfYear << std::endl;

		//2. ... DayOfMonth(...) - ������� ����������� ���������� ���� ���� � ���� ������
		// (��������� ��� � ���������� ���� ���� � �������� ���������� � ������ ������������
		// ���� ������ � ����� ������ � �����-�� ������� �������� ��� �������� ���������� ���������)

		int numOfMonth;

		int& rNumOfMonth = numOfMonth;

		//�������� ���������� �������� �������� DayOfMonth

		int dayOfMonth = DayOfMonth(dayOfYear, year, rNumOfMonth, nDayTab);

		std::cout << "\n|After function call|Day of month is: " << dayOfMonth << "\n\n|After function call|Month is: "<< numOfMonth << std::endl;




		//������� 5. �������� ���������� ������ (����������� ����������� � ��������
		//���������� ���������), ��������� ��� ����������.
		//�������� �������, ������� ��������� � ������ ����� �������� ������ ��� �������,
		//��� ������ �������� � ������� ��� ���. ���������: ��� ���� ������
		//������� ������ �����������!
		//��� �������� �������� �������, ������� ������� �������� ���� ��������� �� �����


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


		//������� 6. ����������� �������. �������� ����������� ������� ����������
		//����� ������ N ����������� �����.


		std::cout << std::endl;
		std::cout << "\nTask 6" << std::endl;

	
		std::cout <<"\nN is :"<<N<< "\nSumm of N digit is:"<< fSumRec(N) << std::endl;

		stop
		
		
		//������� 7�. ������� � ���������� ������ ����������.
		//�������� ������� (���� ��������� VarArgs, �� ������������
		// �������), ������� ��������� ���������� ����� ����������
		// ���� int � ������� �� ������ ����� �������� ���������� �
		// �� ��������.
		// ��������� ����� ������ �������� ������� ��������.

		std::cout << std::endl;
		std::cout << "\nTask 7a" << std::endl;


		int nN1=5, nN2=11, nN3=4, nN4=7, nN5=-1;

		VarArgs(nN1,0);
		VarArgs(nN1,nN2,0);
		VarArgs(nN1,nN2,nN3,nN4,nN5,0);

		stop



		//������� 7�. ������������� ������� 5� � ������� ��������
		// va_start, va_arg, va_end

		std::cout << std::endl;
		std::cout << "\nTask 7b" << std::endl;

		VarArgsM(nN1, 0);
		VarArgsM(nN1, nN2, 0);
		VarArgsM(nN1, nN2, nN3, nN4, nN5, 0);


		system("pause");

		//������� 8. ����������� ������.
		//�������� �������, ������� ������� ����������� �������� � �������,
		// ����� �������, ����� �� ����� ����� ���� ������������ ����� �� ����� 
		// ���������: *MyMin(���������) = 0;

		std::cout << std::endl;
		std::cout << "\nTask 8" << std::endl;


		int someArr[10] = { 1,2,3,4,5,6,7,33,22,11 };

		*MyMin(someArr, 10) = 0;


		return 0;
}//main

