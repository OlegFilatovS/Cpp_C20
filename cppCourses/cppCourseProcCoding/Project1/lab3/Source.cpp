/*************************************************************
Практическое занятие №3. Встроенные массивы.
Динамическое выделение памяти.
Простейшие алгоритмы сортировки и поиска.
Сложные указатели.
Ссылки.
*************************************************************/


#define	  stop __asm nop
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


using namespace std;

enum DirectionOfSort {Down,Up};

void printArr(const int* const arr, size_t sizeOfArr) {

	for (int i = 0; i < sizeOfArr; i++) {

		cout << arr[i] << " ";
	}

	cout << endl;

 }

void selectionSort(int* const arr, size_t sizeOfArr, DirectionOfSort direction) {

	for (int i = 0; i < sizeOfArr - 1; ++i) {

		int elemForSort = i;

		for (int j = i + 1; j < sizeOfArr; ++j) {

			if (direction == Down) {
				if (arr[j] > arr[elemForSort]) elemForSort = j;
			}
			else {
				if (arr[j] < arr[elemForSort]) elemForSort = j;
			}

		}

		int tmp = arr[elemForSort];
		arr[elemForSort] = arr[i];
		arr[i] = tmp;

	}
}

char asterisk_or_space() {

	int num = rand() % 2;

	switch (num){

	case 0: return '_';


	case 1: return '*';


	default: return '_';

	}
}


int main()
{

	///////////////////////////////////////////////////////////////
	//			Встроенные массивы                               //
	///////////////////////////////////////////////////////////////

	//Задание 1. Объявите трехмерный N*M*K массив и сформируйте указанные
	//значения элементов следующим образом:
	//а) проинициализируйте массив при объявлении


	const int N = 2;
	const int M = 2;
	const int K = 2;


	int arr3dInit[N][M][K] = { {1,2,3,4},{5,6,7,8} };



	//б)* объявите неинициализированный массив и присвойте значения элементам
	//	с помощью кода
	//					 |--------|
	//				   / |3  3  3 |
	//    			 |---------|3 |
	//			   / | 2  2  2 |3 |
	//			  |---------|2 |__|
	//			  | 1  1  1 |2 | /
	//			  | 1  1  1 |__|
	//			  | 1  1  1 | /
	//			  |_________|
	//Средствами отладчика проверьте правильность Вашего решения.

	const int A = 3;
	const int B = 3;
	const int C = 3;

	int arr3d[A][B][C];

	for (int i = 0; i < A; i++) {
		for (int j = 0; j < B; j++) {
			for (int k = 0; k < C; k++) {

				arr3d[i][j][k] = i + 1;

			}
		}
	}
	// arr3d 0x0032f884 {0x0032f884 {0x0032f884 {1, 1, 1}, 0x0032f890 {1, 1, 1}, 0x0032f89c {1, 1, 1}}, 0x0032f8a8 {...}, ...}


	//в) найдите сумму элементов массива

	int sumOfArr = 0;

	for (int i = 0; i < A; i++) {
		for (int j = 0; j < B; j++) {
			for (int k = 0; k < C; k++) {

				sumOfArr += arr3d[i][j][k];

			}
		}
	}

	int *p = &arr3d[0][0][0];
	int sumOfArrByPtr = 0;

	for (int i = 0; i < sizeof(arr3d) / sizeof(int); i++) {

		sumOfArrByPtr += *p;
		p++;

	}
	cout << "\nTask 1 ";
	cout << "\n" << endl;

	cout << "Summ of arr in case one: " << sumOfArr;
	cout << "\nSumm of arr in case two (using ptr): " << sumOfArrByPtr << endl;

	stop


		//г) проинициализируйте массив при определении:
		//					 |--------|
		//				   / |3  0  0 |
		//    			 |---------|0 |
		//			   / | 2  0  0 |0 |
		//			  |---------|0 |__|
		//			  | 1  0  0 |0 | /
		//			  | 0  0  0 |__|
		//			  | 0  0  0 | /
		//			  |_________|


		int arr321[3][3][3] = { {1},{2},{3} };

	stop


		//д)* Инициализация массивов строковыми литералами:
		//Объявите и проинициализируйте строковыми литералами два массива:
		//двухмерный массив и массив указателей. Поясните разницу в использовании
		//элементов таких массивов.

		char ar1[][6] = { "One","Two","Three" }; // ar1 == адрес начала двумерного массива 3х6 , &{(O,n,e,0,0,0),(T,w,o,0,0,0),(T,h,r,e,e,0)} 

const char* ar[] = { "One","Two","Three" }; // ar == адрес начала на массив из 3ех указателей &{O,n,e,0},&{T,w,o,0},&{T,h,r,e,e,0}
	ar1[1][1] = 'F';
	//ar[1][1] = 'F';  //Access violation writing  !!!!!
	///////////////////////////////////////////////////////////////
	//			Динамическое выделение памяти                    //
	///////////////////////////////////////////////////////////////
	//Задание2. Создайте динамический двухмерный массив с размерностями,
	//вычисляемыми в процессе выполнения программы - N*M.
	//Задайте значения элементов помощью генератора случайных чисел.
	//Найдите  сумму элементов.
	//Подсказка 1: для генерации случайных чисел используйте функцию
	//стандартной библиотеки - rand() (<cstdlib>)
	//Подсказка 2: На самом деле те значения, которые создаются генератором случайных
	//чисел являются «псевдослучайными», то есть при двух последовательных запусках
	//приложения Вы получаете две одинаковые последовательности значений.
	//Для того чтобы генерируемые "случайные" значения были разными при каждом 
	//запуске приложения используйте функции стандартной библиотеки srand() (<cstdlib>)
	//и time() (<ctime>).
	//Функция srand() осуществляет «привязку» начала генерации к указанному в качестве параметра значению.
	//Функция time() задает эту точку отсчета, считывая текущее время

	//srand( time( 0 ) );

	{

		srand(time(0));

		size_t N, M;

		cout << "\nTask 2 " << endl;


		cout << "\nEnter the number of strings: ";
		cin >> N;

		cout << "\nEnter the number of elements: ";
		cin >> M;


		int* pn = new int[N*M];

		int** pp = new int*[N];

		int* endOfArr = pn + (N*M);

		int sum = 0;

		cout << "\nValues of 2d arr is: " << endl;

		for (int* iter = pn; iter < endOfArr; ++iter) {

			int randValue = rand() % 10;

			*iter = randValue;

			sum += *iter;

			cout << randValue << " ";

		}

		cout << "\n";

		cout << "\nSumm of 2d arr is: " << sum << endl;


		//Задание2а. В сформированном массиве отсортируйте каждую строку по
		//убыванию значений. Используйте сортировку "выбором"

		cout << "\nTask 2a" << endl;

		int elemsOfArr = N*M;

		int tmp = 0;

		for (int i = 0; i < N; i++) {

			pp[i] = pn + i * M;
		}

		cout << "\nSorted array looks like this: " << endl;

		for (int i = 0; i < N;i++){
		selectionSort(pp[i], N, Down);
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << pp[i][j] << " ";
			}
			cout << endl;
		}

		cout << endl;

		stop;

		delete[]pn;

		delete[]pp;

		stop


	}


	//Задание2б. Объявите одномерный массив размерностью N.
	//Сформируйте значение i-ого элемента одномерного массива  
	//равным среднему значению элементов i-ой строки
	//двухмерного массива





	{

		srand(time(0));

		size_t N, M;

		N = 3;
		M = 3;


		int**Arr2d = new int*[N];

		int*arr = new int[N];

		for (int i = 0; i < N; i++) {


			Arr2d[i] = new int[M];

		}

		cout << "\n";

		cout << "Task 2b" << endl;

		cout << "\n";

		cout << "2d array values: " << endl;

		for (int i = 0; i < N; ++i) {

			int sumOfElemesInString = 0;

			for (int j = 0; j < M; ++j) {

				int randValue = rand() % 10;

				Arr2d[i][j] = randValue;

				sumOfElemesInString += randValue;

				cout << randValue << " ";
			}

			arr[i] = (sumOfElemesInString / M);

			cout << "\n";
		}

		cout << "\n\n";


		cout << "1d array values: " << endl;

		printArr(arr, N);

		stop

			delete[]arr;

		for (int i = 0; i < N; i++)
		{
			delete Arr2d[i];
		}

		delete[] Arr2d;


	}


	/////////////////////////////////////////////////////////////////////
	//Задание 3. а) Напишите фрагмент кода, который вводит NN целых чисел с помощью
	//потока ввода в объявленный Вами встроенный одномерный массив, каждый раз
	//упорядочивая полученное значение по возрастанию


	{
		cout << "\nTask 3a " << endl;

		const size_t NN = 4;

		int arrForFill[NN];

		for (int i = 0; i < NN; ++i) {

			cout << "\nEnter digit integer: ";

			cin >> arrForFill[i];

		selectionSort(arrForFill, i + 1, Up);

		}

		cout << "\nSorted Array: " << endl;

		printArr(arrForFill, NN);

	}


	//б) Простой поиск.
	//Модифицируйте предыдущее задание следующим образом:очередное значение
	//вводится в массив только при условии, что там еще такого нет (то есть 
	//дубли игнорируются

	{
		cout << "\nTask 3b " << endl;

		const size_t NN = 4;

		int arrForFill[NN] = { 0 };

		int current = 0;

		bool duplicateFound = 0;

		for (int i = 0; i < NN; ++i) {

			cout << "\nEnter digit integer: ";

			cin >> current;

			for (int j = 0; j <= i; ++j) {

				if (current == arrForFill[j]) {

					cout << "Duplicate entered" << endl;

					duplicateFound = 1;
					break;
				}
			}

			if (!duplicateFound) arrForFill[i] = current;

			duplicateFound = 0;

			selectionSort(arrForFill, i + 1, Up);

		}

		cout << "\nSorted Array: " << endl;
		printArr(arrForFill, NN);

	}



	///////////////////////////////////////////////////////////////////////////
	//Задание 4*.С помощью данной заготовки напишите программу,
	//которая:
	//вводит строки с клавиатуры с помощью cin>>...
	//в объявленный Вами двухмерный встроенный массив 5*80 элементов типа char;
	//признаком конца ввода является символ * (то есть строка - "*") или
	//заполнение массива (больше свободных строк нет);
	//сортировка строк в алфавитном порядке. Пояснение: крайне
	//не рекомендуется для сортировки сложных объектов физически
	//перемещать их в памяти. Намного эффективнее завести массив
	//указателей на соответствующие строки и перемещать только
	//указатели.

	//Подсказка: для лексиграфического сравнения строк пользуйтесь
	//функцией стандартной библиотеки strcmp(...), заголовочный файл <string>.


	//Определите необходимые значения как константы
	{

		cout << "\nTask 4 " << endl;

		const char* STOP_STRING = "*";	//признак "прекратить ввод"

		const size_t M = 80;	//максимальный размер одной строки
		const size_t N = 10;	//максимальное количество строк в массиве

		//Объявите двухмерный массив с именем cBuffer типа char и
		// размерностью N*M

		char cBuffer[N][M];

		char tempString[M];

		//Объявите массив (с именем cPointers) указателей на строки
		//размерностью N

		char* cPointers[N];


		int memCount = 0;

		//Цикл ввода строк:

		for (int i = 0; i < N; i++) {

			//а) выведите приглашение для ввода

			cout << "\nPlease enter some strings: " << endl;

			cin >> tempString;

			//б) пока не введена строка STOP_STRING или не заполнен весь массив

			if (!(strcmp(tempString, STOP_STRING)) || (strlen(tempString) > (M + 1))) break; //если введена строка - признак окончания, то выйти из цикла

			//ввод строки в массив cBuffer:

			memCount++;

			strcpy(cBuffer[i], tempString);

		}


		//Выдать диагностику о том, что прием строк завершен.

		cout << "\nEnd of printing in to array" << endl;


		//Присвойте элементу массива cPointers с индексом nIndex
		//указатель на строку с номером nIndex в массиве cBuffer

		for (int i = 0; i < memCount; i++) {

			 

				cPointers[i] = cBuffer[i];

			
		}


		//Bubble sort:

		for (int i = 0; i < memCount - 1; i++) {
			for (int j = 0; j < memCount -i-1; j++) {
				if (strcmp(cPointers[j], cPointers[j+1]) == 1) {
					char* temp = cPointers[j];
					cPointers[j] = cPointers[j+1];
					cPointers[j+1] = temp;
				}
			}
		}

		cout << "\nSorted array: " << endl;

		for (int i = 0; i < memCount; i++) {
			cout << cPointers[i] << endl;
		}

	}
stop

	//Задание 5*. Реализуйте задание №4, используя не встроенные,
	//а динамические массивы (массив?). Так как строки могут быть разной длины,
	//эффективным решением было бы отводить под каждую строку ровно столько байтов,
	//сколько требуется для ее хранения.
	//При этом необходимые параметры (количество строк
	// сформируйте с помощью потока ввода
	{

		cout << "\nTask 5 " << endl;

		const int nStringNumber = 10;
		const int stringLimit = 80;
		const char* STOP_STRING = "*";	//признак "прекратить ввод"

		char** m_str_array = new char*[nStringNumber];


		char tempString[stringLimit] = { '\0' };

		int memCount = 0;


		for (int i = 0; i < nStringNumber; i++) {   //loop for entering strings


			cout << "\nPlease enter some strings: " << endl;  //entering the strings

			cin >> tempString;


			if (!(strcmp(tempString, STOP_STRING)) || (strlen(tempString) > (stringLimit + 1))) break;  //if * or end of stringLimit break

			int str_size = strlen(tempString)+1;

			m_str_array[i] = new char[str_size]; // allocating space for new string

			memCount++;

			strcpy(m_str_array[i], tempString);

		}


		// sorting an array

		for (int i = 0; i < memCount - 1; i++) {
			for (int j = 0; j < memCount - i - 1; j++) {
				if (strcmp(m_str_array[j], m_str_array[j + 1]) == 1) {
					char* temp = m_str_array[j];
					m_str_array[j] = m_str_array[j + 1];
					m_str_array[j + 1] = temp;
				}
			}
		}

		cout << "\nSorted array: " << endl;

		for (int i = 0; i < memCount; i++) {
			cout << m_str_array[i] << endl;
		}


		//Освобождение занятой памяти:

		for (int i = 0; i < memCount; i++) {
			delete m_str_array[i];
		}

		delete[] m_str_array;
		stop


	}

		//Задание 6*. Объявление и использование указателей на многомерные
		// массивы. Проинициализируйте трехмерный массив
		//double dArray[4][3][3] так, как показано на рисунке и напишите фрагмент
		//кода, который меняет местами значения элементов четных
		//и нечетных слоев:
		//	было:			     |--------|
		//  				   / |4  4  4 |
		//					 |--------|	4 |
		//				   / |3  3  3 |	4 |
		//    			 |---------|3 |   |
		//			   / | 2  2  2 |3 | /
		//			  |---------|2 |__|
		//			  | 1  1  1 |2 | /
		//			  | 1  1  1 |__|
		//			  | 1  1  1 | /
		//			  |_________|

		//	стало:			     |--------|
		//  				   / |3  3  3 |
		//					 |--------|	3 |
		//				   / |4  4  4 |	3 |
		//    			 |---------|4 |   |
		//			   / | 1  1  1 |4 | /
		//			  |---------|1 |__|
		//			  | 2  2  2 |1 | /
		//			  | 2  2  2 |__|
		//			  | 2  2  2 | /
		//			  |_________|



		{
			cout << "\nTask 6 " << endl;

			const int layers = 4;
			const int strings = 3;
			const int elems = 3;

			double dArray[layers][strings][elems] = { 0 };

			for (int i = 0; i < layers; i++) {
				for (int j = 0; j < strings; j++) {
					for (int k = 0; k < elems; k++) {

						dArray[i][j][k] = i + 1;

					}
				}
			}


			cout << "\nArray before swapping layers:" << endl;
			cout << endl;

			for (int i = 0; i < layers; i++) {

				for (int j = 0; j < strings; j++) {

					for (int k = 0; k < elems; k++) {

						cout << dArray[i][j][k] << " ";
					}
					cout << endl;
				}
				cout << endl;
			}
	
			
			double tmp = 0;

			for (int i=0; i < layers ;i++){
			
				double(*Arr2Ptr)[elems] = dArray[i];
				double(*Arr2PtrNext)[elems] = dArray[i+1];

				if (i%2 == 0){

				for (int j = 0; j < strings; j++) {

						for (int k = 0; k < elems; k++) {
						
						tmp = Arr2PtrNext[k][j];

						Arr2PtrNext[k][j] = Arr2Ptr[k][j];

						Arr2Ptr[k][j] = tmp;

														}
											}
			
									}
			}
			
	

					cout << "\nArray after swapping layers:" << endl;
					cout << endl;
					for (int i = 0; i < layers; i++) {

						for (int j = 0; j < strings; j++) {

							for (int k = 0; k < elems; k++) {

								cout << dArray[i][j][k] << " ";
							}
							cout << endl;
						}
					cout << endl;
					}

		}

		///////////////////////////////////////////////////////////////////////////
		//Задание 7а. Объявите двухмерный встроенный массив элементов типа char.
		//Сформируйте значения элементов массива с помощью генератора случайных
		//чисел таким образом, чтобы в массиве были только символы '*' и '_'
		{
			cout << "\nTask 7a" << endl;

			srand(time(0));

			const int row = 5;
			const int col = 5;
			int asteriskCounter = 0;

			char ch_array[row][col];

			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {

					ch_array[i][j] = asterisk_or_space();

				}
			}

			cout << "\nUnsorted array with * & _: " << endl;

			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					cout << ch_array[i][j] << " ";
							}
						cout << endl;
						}

				//В каждой строке "сдвиньте звездочки" в начало строки, например:
				//было - '*' '_' '_' '*' '*' '_' '*' '_' '*' '_'
				//стало: '*' '*' '*' '*' '*' '_' '_' '_' '_' '_'
				//и распечатайте массив по строкам - "постройте распределение"

				int currentPos = 0;

				for (int i = 0; i < row; i++) {

					for (int j = 0; j < col; j++) {

						if (ch_array[i][j] == '*') {

							int tmp = ch_array[i][currentPos];

							ch_array[i][currentPos] = ch_array[i][j];

							ch_array[i][j] = tmp;

							currentPos++;
						}

					}

					currentPos = 0;
				}


				cout << "\nSorted array with * & _: " << endl;

				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						cout << ch_array[i][j] << " ";
					}
					cout << endl;
				}

				cout << endl;

			
		}
stop
		// 7б. Модифицируйте предыдущее задание следующим способом:
		//После заполнения массива с помощью генератора случайных чисел
		//"сдвиньте" звездочки по столбцам вниз и распечатайте полученное
		//"распределение"

		{
			cout << "\nTask 7b" << endl;

			srand(time(0));

			const int row = 4;
			const int col = 4;
			int asteriskCounter = 0;

			char ch_array[row][col];

			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {

					ch_array[i][j] = asterisk_or_space();

				}
			}

			cout << "\nUnsorted array with * & _: " << endl;

			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					cout << ch_array[i][j] << " ";
				}
				cout << endl;
			}

		

			for (int i = 0; i < row - 1; i++) {

				for (int j = 0; j < col; j++) {

					if (ch_array[i][j] == '*') {

						int tmp = ch_array[i+1][j];

						ch_array[i+1][j] = ch_array[i][j];

						ch_array[i][j] = tmp;



						
					}
				}
			}

			cout << "\nSorted array with * & _: " << endl;

			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					cout << ch_array[i][j] << " ";
				}
				cout << endl;
			}



		}

		system("pause");


		return 0;
	
}