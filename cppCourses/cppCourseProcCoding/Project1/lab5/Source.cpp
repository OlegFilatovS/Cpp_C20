
/*************************************************************
������������ ������� �5.
"������" ��������� ������� ����������� ����������
��������� �� �������
���������
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
	//���� "������" ��������� ������� ����������� ����������
	//������� 1. � ������� ������� scanf ����������� ��� ������������: A,B,C

	std::cout << "\nTask 1 old C stream functions: " << std::endl;

	int A, B, C;

	printf("Enter A,B,C : \n");

	scanf("%d%d%d", &A, &B, &C);



	//������� 2. �������� (�������!) ������� �������� y=A*x*x + B*x + C
	//��� ��������� x � ��������� -2 �� +2 � ����� 0.5


	printf("====================\n");
	printf("| x   |  y |\n");
	printf("--------------------\n");
	for (float i = -2.0; i < 2.1; i += 0.5)
		printf("|%4.1f | %5.2f |\n", i, A*i*i + B*i + C);
	printf("====================\n");
	stop;




	///////////////////////////////////////////////////////////////////
	//���� ��������� �� �������

	//������� 1. ��������� �� �������. "�����������".
	//�������� �������:
	//1)Sum - ��������� ��� �������� double � ���������� �����
	//���� ��������
	//2)Sub- ��������� ��� �������� double � ���������� ��������
	//���� ��������
	//3)Mul - *
	//4)Div - /
	//5)� ��� ���������� � ������� ������ ������������ ������� ����������� ����������
	//		- pow(). ��������� 1: �������� ������� ��������� � <cmath>.
	//		��������� 2: ����������� ���������� ������������� ��������� �������������
	//		��������� ���� �������, � ��� ����������� ������������ ��������� �� 
	//		double pow(double, double);

	//������������ ������������	��������� �����������:
	//���� ������������ ����� ������������ �������� ������ ������������,
	//�� ����� ������� ��� �������� � ���� ��������
	//� �� �������� ���������. ��������� ��������� ����������� ������
	//��������������� ����� ������� �� ���������.
	//������������� ����������� ����� ������������������ ����� ��������

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

		//������� 2. ��������� �� ������� � �������� ���������.
		//���� ��������� ������� ���������� ����� �������� - Sort.
		//������� ��������� ��������� ���������:
		//1) ��������� �� ������ ����������� �������
		//2) ���������� ����������� ���������
		//3) ������ �������� � ������
		//4) ��������� �� ������� ������������ ���������
		//5) ��������� �� ������� ��������� ���������

		std::cout << "\nTask 2 pointers: " << std::endl;



		//2a. �������� ������� ������������ ���� ����� �������� -
		// SwapInt, ������� ��������� ��� void ��������� � 
		//������ �������� �������

	int first = 1;

	void* fPtr = &first;

	int second = 2;

	void* SPtr = &second;

	SwapInt(fPtr,SPtr);

	stop

	//�������� ������� ��������� ���� ����� �������� -
	// CmpInt, ������� ��������� ��� void ��������� �
	//���������� int ��������� ���������: 
	//<0 - ������ ������� ������, ��� ������
	//=0 - �����
	//>0 - ������ ������� ������, ��� ������


	int res = CmpInt(fPtr, SPtr);
		

	stop

	const int nTotal = 10;

	int nAr[nTotal] = { 556,23,4,53,1,2,44,532,543,278 };//������ ��� ����������

	//������ ��������� �������

	std::cout << "\nArray before sort:" << std::endl;

	for (int i = 0; i < nTotal; i++) {

		std::cout << nAr[i] << " ";
	}


	//����� ����������

			//���������� ��������� � �������

	Sort(reinterpret_cast<char*>(&nAr[0]), nTotal, sizeof(int), SwapInt, CmpInt);

	//������ ����������� ����������


	std::cout << "\nArray after sort:" << std::endl;

	for (int i = 0; i < nTotal; i++) {

		std::cout << nAr[i] << " ";
	}

	stop


		//������� 2�. �� �������� � 8� �������� ���������������
		//������� - SwapDouble � CmpDouble � �������� ������� Sort
		//��� ���������� ������� ������������ ��������.

		std::cout << "\nTask 2b pointers: " << std::endl;

		double nArD[nTotal] = { 556.1,23.2,4.3,53.3,1.1,2.1,44.2,532.32,543.4,278.23 };//������ ��� ����������

		
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
	
	//������� 2�*. �� �������� � 8� �������� ���������������
	//������� - SwapStr � CmpStr � �������� ������� Sort
	//��� ���������� ������� ���������� �� ������.

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
	

	
	//������� 3. ������� ���������� �� �������.
	//�������� ��������� ������� ����
	std::cout << "\nTask 3 pointers: " << std::endl;
	//const char* GetString1();
	//const char* GetString2();

	//		...., ������ �� ������� ���������� ��������� �� ���� ������
	//(��������� - ����� ����� �� ������ ����� ���������� �� �������)

	//�������� � ������������������ ������ ���������� �� �������
	//GetString1,GetString2...


	myFuncType myArr[4] = { GetString1 ,GetString2 ,GetString3 ,GetString4 };


	//������� ����� �������, ������� �� ������ �������:

	int n = 2;

	//�������� �������

	const char* resOfCall = myArr[n]();


	//������������ ���������

	std::cout << "\nString from array is:" << resOfCall << std::endl;


	//////////////////////////////////////////////////////////////////////////////////////

	//����. ��������� �.	


	//������� 1. �������� ��������� BOOK, ����������� �����
	//(�����, ��������, ��� �������, ����, ����������).
	//���������: ������ ���� ����� ���� ���� ���������.
	//���������: ���������� ��������� ������������� ��������
	//� ������������ ����.


	//������� 2. �������� ������� ��������� (����������, ���������, �����������,
	//������������) ���������� (�������) ���� BOOK (��� �������������).
	//���������� - ������� ������ ������� ���������� ��� ������
	//����� ������. ��� ���������������� (��� �� ����������������) ����
	//���������. ���������: �� ���� ������� ����� ���������� ������?


	Book localBook;

	Book *dynamicBook = new Book();

	Book static staticBook;
	

	size_t sizeOfBook = sizeof(localBook); //80

	sizeOfBook = sizeof(*dynamicBook); //80

	sizeOfBook = sizeof(staticBook); //80
	
	sizeOfBook = sizeof(globalBook); //80

	stop


	//������� 3. ��������� ���� ��������� ��������.
	//���������: ���� ��� �������� ������ ������������ ������, ����������
	//������������� "������" �� ������ �� ������� �������.

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

	//������� 4. �������� �������, ��������� �� ����� ��������� �����.
	//���������: ��� ����������� ���������� ��������� BOOK � �������.
	//��� ������ �� ������� ����������� ������� ����������� ����������
	//printf

	stop

	std::cout << std::endl;
	printBook(localBook);

	std::cout << std::endl;
	printBook(*dynamicBook);



	//������� 5. �������� ������� ��� ������������ ����� ���������.
	//��� ����� ����������� ������� ����������� ���������� scanf
	//���������: ������� �������� � ����� ������� ����������� ��������
	//������������ ���������� ��������, ��������, ��� ������� �� ����� ����
	//�����, ���... (��� ��������� ������������), ��������� �����������
	//������ �������� �� ������������, ���� �� ����� ���� �������������...

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

