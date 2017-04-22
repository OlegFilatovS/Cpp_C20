// Темы:
// Простое наследование. Виртуальные функции. Абстрактные классы.
// Битовые поля.


#include <tchar.h>
#define	  stop __asm nop
#include "MyString.h"
#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Bytes.h"


MyString summOfparams(char* somestring ...) {
	
	//	Внутри MyString констр move копирования	

	char **cp = &somestring;            

	int len = 0;

	while (*cp) { len += strlen(*cp); cp++; }

	cp = &somestring;

	char *str = new char[len+1];

	str[0] = 0;


	while (*cp)
	{
		strcat(str, *cp);

		cp++;                  
	}

	MyString strMs(str);

	delete[] str;
	
	return strMs;
}


int _tmain(int argc, _TCHAR* argv[])
{
	//Задание 1.Массив объектов класса.
	{
		/*Объявите и проинициализируйте массив ar из объектов
		типа MyString. */

		const int N = 5;

		//MyString str1 = "some string1";
		//MyString str2 = "some string2";
		//MyString str3 = "some string3";

		//MyString strArr1[N] = { str1,str2,str3 };
		MyString strArr1[N] = { MyString("some"),MyString("some2"),MyString("some23") };

		/*Проверка - печать строк-членов класса*/

		for (int i = 0; i < N; i++) {

		//	if (!strArr1[i].IsEmpty()){

			std::cout << strArr1[i].GetString() << std::endl;
			
		}
		//	Замените размер const int N=5; , не изменяя список инициализаторов.


		std::cout << std::endl;

	}
	stop


		//Задание 2.Массив указателей на объекты класса.
	{
		//Объявите и проинициализируйте массив arPtr из N
		//указателей на объекты типа MyString.
		const int N=5;



		stop		

		MyString *str1 = new MyString("some string1");
		MyString *str2 = new MyString("some string2");
		MyString *str3 = new MyString("some string3");

		

		MyString* strArr1[N] = { str1,str2,str3 };
		
		for (int i = 0; i < N; i++) {

			if (strArr1[i] != nullptr) {

				std::cout << strArr1[i]->GetString() << std::endl;
			}
		}
		
		delete str1;
		delete str2;
		delete str3;

		//Печать строк-членов класса

		//Замените размер const int N=5; , не изменяя список инициализаторов.

	}
		stop


		//Задание 3.Простое наследование.Аргументы конструктора,
		// передаваемые в базовый класс.

		//Создайте иерархию классов:
		//базовый класс Shape (который описывает любую фигуру)
		//и два производных класса Rect и Circle.

		//Подумайте: какие данные и методы нужно ввести в базовый
		//и производные классы (например, любую фигуру можно сделать
		//цветной => в базовом классе можно ввести переменную, которая
		//будет определять цвет фигуры.
		//Подсказка: для хранения цвета объявите перечисление (RED,GREEN,BLUE...);
	{
		Shape *shape = new Shape();

		shape->SetColor(Green);


		//В конструкторах производных классов предусмотрите передачу
		//параметра-цвета конструктору базового класса.
		//При создании и уничтожении объекта производного типа определите
		//последовательность вызовов конструкторов и деструкторов базового
		//и производного классов


		Rect *rect = new Rect();

		rect->SetColor(Red);

		Rect *rect2 = rect;
		
	//	rect2->getColor();

		Circle *circle = new Circle(); //первым идет вызов конструктора базового класса,потом потомка. Деструкторы наоборот.

// circle->getColor();

		delete circle;


	}



		stop
		//////////////////////////////////////////////////////////////////////
	
		//Задание 4.Виртуальные функции.

		//4а) Модифицируйте классы Shape,Rect и Circle:
		//добавьте в каждый класс public метод void WhereAmI().
		//Реализация каждой функции должна выводить сообщение
		//следующего вида "Now I am in class Shape(Rect или Circle)".
		//Выполните приведенный фрагмент, объясните результат.
		{

		Shape *shape = new Shape();

		shape->WhereAmI();

		Rect *rect = new Rect();

		rect->WhereAmI();

		Circle *circle = new Circle(); 

		circle->WhereAmI();

		stop
	
	
	
		}
		//4б) Сделайте метод WhereAmI() виртуальным.
		//Снова выполните приведенный фрагмент, объясните разницу.
			
	{

		stop

		Shape s;
		Rect r;
		Circle c;

		//Метод какого класса вызывается в следующих строчках???
		s.WhereAmI();	//	Shape
		r.WhereAmI();	//	Rect
		c.WhereAmI();	//	Circle
		stop


		Shape* pShape = &s;
		Shape* pRect = &r;
		Shape* pCircle = &c;

		pShape->WhereAmI();	//	shape
		pRect->WhereAmI();	//	rect	
		pCircle->WhereAmI(); //	Circle
		stop


		//Заполните ... согласно комментариям

		Shape& rShape = *pShape; //псевдоним s
		Shape& rRect = *pRect; //псевдоним r
		Shape& rCircle = *pCircle; //псевдоним c

		rShape.WhereAmI();	//вызов посредством rShape	Shape
		rRect.WhereAmI();	//вызов посредством	rRect	Rect
		rCircle.WhereAmI(); //вызов посредством rCircle	Circle
		stop
		}
		

		//////////////////////////////////////////////////////////////////////
		
		//Задание 5.Виртуальные деструкторы.
		//Модифицируйте классы:
		//a) введите соответствующие
		// деструкторы (без ключевого слова virtual).
		//Реализация каждого деструктора
		//должна выводить сообщение следующего вида
		// "Now I am in Shape's destructor!" или
		// "Now I am in Rect's destructor!"
		//Выполните фрагмент. Объясните результат.


		{

			std::cout << "task 5" << std::endl;

			stop

			Shape *shape = new Shape();
			Rect *rect = new Rect();
			Circle *circle = new Circle();

			delete shape; //shape destr
			delete rect; // rect destr  shape destr
			delete circle; // circle destr shape destr
					

			stop;
		
		}



		// b) Добавьте в объявление деструкторов ключевое слово virtual
		// Выполните фрагмент.Объясните разницу.

		{
			std::cout << std::endl;

			std::cout << "task 5b" << std::endl;

			stop

			Shape *shape = new Shape();
			Rect *rect = new Rect();
			Circle *circle = new Circle();

			delete shape; //shape destr
			delete rect; // rect destr  shape destr
			delete circle; // circle destr shape destr


			stop;

		}

		//Подумайте: какие конструкторы вызываются в следующей строке?
		//Если в разработанных классов каких-то конструкторов
		//не хватает - реализуйте
		//Если Вы считаете, что в приведенном фрагменте чего-то
		//не хватает - добавьте

		std::cout << std::endl;

		std::cout << "task 5c" << std::endl;

		Rect r(1,2,3,4);  //здесь задать вопрос про color в конструктор базового класса

        Shape* ar[]={new Shape(r), new Rect(r), new Circle(r), new Circle() };

		for (int i = 0; i < 4; i++) {

			//ar[i]->WhereAmI();

			delete ar[i];

		}

		//Вызовите для каждого элемента массива метод WhereAmI()


		stop
		

		
		//Задание 6*. В чем заключается отличие 1) и 2)
		{


		std::cout << std::endl;

		std::cout << "task 6" << std::endl;

		Shape* pShapes = new Rect[10];//1)       
		Rect* pRects = new Rect[10];//2) 


		//Попробуйте вызвать метод WhereAmI() для каждого элемента обоих массивов -
		//в чем заключается проблема???

		for (int i = 0; i < 9; i++) {

			static_cast<Shape>(pShapes[i]).WhereAmI();
			pRects[i].WhereAmI();

		}

		stop

		//Освободите динамически захваченную память

		delete[] pShapes;
		delete[] pRects;
		}


		//////////////////////////////////////////////////////////////////////
		
		//Задание 7.Виртуальные функции и оператор разрешения области видимости.

		{
		std::cout << std::endl;

		std::cout << "task 7" << std::endl;

		Rect r(1,2,3,4);
		Shape* p = &r;
		p->WhereAmI();// Rect
		


		//4a Оператор разрешения области видимости.
		//Посредством объекта r и указателя p вызовите виртуальную функцию
		//WhereAmI()класса Shape

		p->Shape::WhereAmI(); //shape


		stop
		}


		//////////////////////////////////////////////////////////////////////
		
		//Задание 8.Чисто виртуальные функции.
		//Введите в базовый класс метод void Inflate(int); Подумайте:
		//можно ли реализовать такой метод для базового класса? => как его нужно объявить.
		//Реализуйте этот метод для производных классов.
		{
		Rect r(1,2,3,4);
		Shape* p = &r;
		p->Inflate(5); //вызовится метод Rect, в Shape нет смысла реализовывать - чисто виртуальный
		Circle c(1,2,3);
		p = &c;
		p->Inflate(5);//вызовится метод Circle
		}
		
		stop

			//////////////////////////////////////////////////////////////////////
			//Задание 9. Создайте глобальную функцию, которая будет принимать любое
			//количество указателей на строки, а возвращать объект MyString,
			//в котором строка будет конкатенацией параметров

			std::cout << std::endl;

		std::cout << "task 9" << std::endl;

			std::cout << summOfparams("qwerty", "qwerty1", "qwerty2", "qwerty3",0).GetString() << std::endl;



			stop

		////////////////////////////////////////////////////////////////////////
		
		//Задание 10.Объединения (union) C++. Битовые поля.
		//1.
		//Создайте следующие классы для различных представлений значений байта:
		//Bin - для двоичного представления
		//Hex - для шестнадцатерчного представления
		//Oct - для восьмеричного представления.
		//Подсказка 1: - для удобства используйте битовые поля.
		//Подсказка 2: - конструкторов в таких вспомогательных классах быть не должно,
		//так как все они будут членами объединения (union).
		//2.
		//В каждом классе введите метод Show, который должен выводить значение в
		//соответствующем виде
		//3.
		//Посредством объединения MyByte предоставьте пользователю возможность манипулировать
		//одним и тем же значением по-разному:
		//а) выводить: десятичное, шестнадцатеричное, восьмеричное, двоичное значение байта
		//          а также символ, соответствующий хранимому значению (если есть соответствие);
		//б) выводить отдельные (указанные посредством параметра) шестнадцатеричные,
		//			восьмеричные, двоичные цифры;
		//в) изменять отдельные двоичные, восьмеричные или шестнадцатеричные цифры;

			std::cout << std::endl;

			std::cout << "task 10" << std::endl;


		Bytes byte(10);

		std::cout << std::endl;
		std::cout << "Hex" << std::endl;
		std::cout << std::endl;
		byte.ShowHex();
		std::cout << std::endl;
		byte.ShowBin();
		std::cout << std::endl;
		byte.ShowOct();
		std::cout << std::endl;
		byte.ShowHexPos(1);
		std::cout << std::endl;
		std::cout << std::endl;
		byte.EditHex(0,11);

		std::cout << std::endl;

		std::cout << "Bin" << std::endl;
		std::cout << std::endl;
		
		std::cout << std::endl;
		byte.EditBin(5, 0);
		std::cout << std::endl;
		byte.ShowBinPos(3);
		std::cout << std::endl;

		std::cout << std::endl;
		std::cout << "Oct" << std::endl;
		std::cout << std::endl;
		
		std::cout << std::endl;
		byte.EditOct(2, 7);
		std::cout << std::endl;
		byte.ShowBinPos(1);
		std::cout << std::endl;


		stop
		//...


		return 0;
}//endmain

