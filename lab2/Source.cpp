// ����:
// ������� ������������. ����������� �������. ����������� ������.
// ������� ����.


#include <tchar.h>
#define	  stop __asm nop
#include "MyString.h"
#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Bytes.h"


MyString summOfparams(char* somestring ...) {
	
	//	������ MyString ������ move �����������	

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
	//������� 1.������ �������� ������.
	{
		/*�������� � ������������������ ������ ar �� ��������
		���� MyString. */

		const int N = 5;

		//MyString str1 = "some string1";
		//MyString str2 = "some string2";
		//MyString str3 = "some string3";

		//MyString strArr1[N] = { str1,str2,str3 };
		MyString strArr1[N] = { MyString("some"),MyString("some2"),MyString("some23") };

		/*�������� - ������ �����-������ ������*/

		for (int i = 0; i < N; i++) {

		//	if (!strArr1[i].IsEmpty()){

			std::cout << strArr1[i].GetString() << std::endl;
			
		}
		//	�������� ������ const int N=5; , �� ������� ������ ���������������.


		std::cout << std::endl;

	}
	stop


		//������� 2.������ ���������� �� ������� ������.
	{
		//�������� � ������������������ ������ arPtr �� N
		//���������� �� ������� ���� MyString.
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

		//������ �����-������ ������

		//�������� ������ const int N=5; , �� ������� ������ ���������������.

	}
		stop


		//������� 3.������� ������������.��������� ������������,
		// ������������ � ������� �����.

		//�������� �������� �������:
		//������� ����� Shape (������� ��������� ����� ������)
		//� ��� ����������� ������ Rect � Circle.

		//���������: ����� ������ � ������ ����� ������ � �������
		//� ����������� ������ (��������, ����� ������ ����� �������
		//������� => � ������� ������ ����� ������ ����������, �������
		//����� ���������� ���� ������.
		//���������: ��� �������� ����� �������� ������������ (RED,GREEN,BLUE...);
	{
		Shape *shape = new Shape();

		shape->SetColor(Green);


		//� ������������� ����������� ������� ������������� ��������
		//���������-����� ������������ �������� ������.
		//��� �������� � ����������� ������� ������������ ���� ����������
		//������������������ ������� ������������� � ������������ ��������
		//� ������������ �������


		Rect *rect = new Rect();

		rect->SetColor(Red);

		Rect *rect2 = rect;
		
	//	rect2->getColor();

		Circle *circle = new Circle(); //������ ���� ����� ������������ �������� ������,����� �������. ����������� ��������.

// circle->getColor();

		delete circle;


	}



		stop
		//////////////////////////////////////////////////////////////////////
	
		//������� 4.����������� �������.

		//4�) ������������� ������ Shape,Rect � Circle:
		//�������� � ������ ����� public ����� void WhereAmI().
		//���������� ������ ������� ������ �������� ���������
		//���������� ���� "Now I am in class Shape(Rect ��� Circle)".
		//��������� ����������� ��������, ��������� ���������.
		{

		Shape *shape = new Shape();

		shape->WhereAmI();

		Rect *rect = new Rect();

		rect->WhereAmI();

		Circle *circle = new Circle(); 

		circle->WhereAmI();

		stop
	
	
	
		}
		//4�) �������� ����� WhereAmI() �����������.
		//����� ��������� ����������� ��������, ��������� �������.
			
	{

		stop

		Shape s;
		Rect r;
		Circle c;

		//����� ������ ������ ���������� � ��������� ��������???
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


		//��������� ... �������� ������������

		Shape& rShape = *pShape; //��������� s
		Shape& rRect = *pRect; //��������� r
		Shape& rCircle = *pCircle; //��������� c

		rShape.WhereAmI();	//����� ����������� rShape	Shape
		rRect.WhereAmI();	//����� �����������	rRect	Rect
		rCircle.WhereAmI(); //����� ����������� rCircle	Circle
		stop
		}
		

		//////////////////////////////////////////////////////////////////////
		
		//������� 5.����������� �����������.
		//������������� ������:
		//a) ������� ���������������
		// ����������� (��� ��������� ����� virtual).
		//���������� ������� �����������
		//������ �������� ��������� ���������� ����
		// "Now I am in Shape's destructor!" ���
		// "Now I am in Rect's destructor!"
		//��������� ��������. ��������� ���������.


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



		// b) �������� � ���������� ������������ �������� ����� virtual
		// ��������� ��������.��������� �������.

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

		//���������: ����� ������������ ���������� � ��������� ������?
		//���� � ������������� ������� �����-�� �������������
		//�� ������� - ����������
		//���� �� ��������, ��� � ����������� ��������� ����-��
		//�� ������� - ��������

		std::cout << std::endl;

		std::cout << "task 5c" << std::endl;

		Rect r(1,2,3,4);  //����� ������ ������ ��� color � ����������� �������� ������

        Shape* ar[]={new Shape(r), new Rect(r), new Circle(r), new Circle() };

		for (int i = 0; i < 4; i++) {

			//ar[i]->WhereAmI();

			delete ar[i];

		}

		//�������� ��� ������� �������� ������� ����� WhereAmI()


		stop
		

		
		//������� 6*. � ��� ����������� ������� 1) � 2)
		{


		std::cout << std::endl;

		std::cout << "task 6" << std::endl;

		Shape* pShapes = new Rect[10];//1)       
		Rect* pRects = new Rect[10];//2) 


		//���������� ������� ����� WhereAmI() ��� ������� �������� ����� �������� -
		//� ��� ����������� ��������???

		for (int i = 0; i < 9; i++) {

			static_cast<Shape>(pShapes[i]).WhereAmI();
			pRects[i].WhereAmI();

		}

		stop

		//���������� ����������� ����������� ������

		delete[] pShapes;
		delete[] pRects;
		}


		//////////////////////////////////////////////////////////////////////
		
		//������� 7.����������� ������� � �������� ���������� ������� ���������.

		{
		std::cout << std::endl;

		std::cout << "task 7" << std::endl;

		Rect r(1,2,3,4);
		Shape* p = &r;
		p->WhereAmI();// Rect
		


		//4a �������� ���������� ������� ���������.
		//����������� ������� r � ��������� p �������� ����������� �������
		//WhereAmI()������ Shape

		p->Shape::WhereAmI(); //shape


		stop
		}


		//////////////////////////////////////////////////////////////////////
		
		//������� 8.����� ����������� �������.
		//������� � ������� ����� ����� void Inflate(int); ���������:
		//����� �� ����������� ����� ����� ��� �������� ������? => ��� ��� ����� ��������.
		//���������� ���� ����� ��� ����������� �������.
		{
		Rect r(1,2,3,4);
		Shape* p = &r;
		p->Inflate(5); //��������� ����� Rect, � Shape ��� ������ ������������� - ����� �����������
		Circle c(1,2,3);
		p = &c;
		p->Inflate(5);//��������� ����� Circle
		}
		
		stop

			//////////////////////////////////////////////////////////////////////
			//������� 9. �������� ���������� �������, ������� ����� ��������� �����
			//���������� ���������� �� ������, � ���������� ������ MyString,
			//� ������� ������ ����� ������������� ����������

			std::cout << std::endl;

		std::cout << "task 9" << std::endl;

			std::cout << summOfparams("qwerty", "qwerty1", "qwerty2", "qwerty3",0).GetString() << std::endl;



			stop

		////////////////////////////////////////////////////////////////////////
		
		//������� 10.����������� (union) C++. ������� ����.
		//1.
		//�������� ��������� ������ ��� ��������� ������������� �������� �����:
		//Bin - ��� ��������� �������������
		//Hex - ��� ����������������� �������������
		//Oct - ��� ������������� �������������.
		//��������� 1: - ��� �������� ����������� ������� ����.
		//��������� 2: - ������������� � ����� ��������������� ������� ���� �� ������,
		//��� ��� ��� ��� ����� ������� ����������� (union).
		//2.
		//� ������ ������ ������� ����� Show, ������� ������ �������� �������� �
		//��������������� ����
		//3.
		//����������� ����������� MyByte ������������ ������������ ����������� ��������������
		//����� � ��� �� ��������� ��-�������:
		//�) ��������: ����������, �����������������, ������������, �������� �������� �����
		//          � ����� ������, ��������������� ��������� �������� (���� ���� ������������);
		//�) �������� ��������� (��������� ����������� ���������) �����������������,
		//			������������, �������� �����;
		//�) �������� ��������� ��������, ������������ ��� ����������������� �����;

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

