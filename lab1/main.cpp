#include "myRect.h"
#include "myString.h"
#include <iostream>
#include "barrel.h"

#define stop __asm nop

int main()

{


//������� 1.���������� ������. �������� ���������� ������.
//����� ������� ������.
//�������� �������� Class View - (����� �� ������� ����� ������� �
//������ - ������� Rect � MyString)
//�������� �������� �� ����������� ����� �� ���� ������ ������ - ���
//���������� ������������ ������� � ������� ����� ������.

//����� ����������� ���������� ��� �������� ���������� ������?
{
	Rect rect; // default
	stop
}

//1a. �������� � ���������� ����������� � ����������� ���
//������������� ���������� ������. �������� ��������� ������ Rect
//� ������� ������������ � �����������. ���� ���������� ������
//������ � ���������� ���������, ��������� - ���� ��� ��
//�������? ��������� ���������� ������.
//�������� ������� � ������ ������ �� �����, ����������:
//� ����� ������ ���������� ����� ������������(������?)?

//���������: ������, ��� ������������ ������ ������ ����� ���������
//� �������� ���������� ����� ��������! ��������:
{
	Rect rect1(4, 3, 2, 1);


	//stop
}

//1�. ��� ��������������� ������� ����������� ������������ ��� ����������
//������������� ������������� ���������� ������, ��������, �����
{
	Rect rect2;
	stop
}

//1�. ��������, ���������� � �������� ����� ������ InflateRect(),
//������� ����������� ������� �������������� �� �������� ����������
//(��������� ������� �� ������ - ������ ������� �� ���� ��������).
//���������: �������� � ���������� ������ ����� �� ������ "�������",
//�� � � ������� Wizard-a Class View. ��� �����: �������� ��������
//ClassView ���� �������, �������� �������� ����� Rect � �������
//������ ������ ���� - � ����������� ����������� ���� ��������
//Add/Add Member Function... � ������� ����������� ���������� ������
//"����� ��������" Wizard-� ��� �������� � ���������� �����.
{

Rect rect3(4, 3, 2, 1);

rect3.InflateRect(1,2,1,0);

stop
}


//������� 2.���������� ������������� � ������� ������.
//����������� �����������.

//2�.�������� � ���������� ����������� ����������� � ������ Rect.
//�������� ������� �� �����, ����������, �����
//����������� ���������� ��� �������� r1,r2,r3 � r4?
//���� ����� ���������� ��������� ��������?
Rect r1;                // Rect();
Rect r2(1, 2, 3, 4);       // Rect(int m_left, int m_right, int m_top, int m_bottom);
Rect r3 = r1;           // default copy?
Rect r4(r2);            // Rect(const Rect & other);
stop


//2�. �������� � ���������� � ������ Rect ����� InflateRect(),
//������� ��������� ��� ���������, �� ��������� ������ 1, � 
//���������� ������� �������������� �� �� �������� ����������.
//��� ����� �������� ���������� ������� InflateRect()?

r1.InflateRect(1, 1);
r2.InflateRect(2, 2);
//����� �� ������� InflateRect() ���������� � ������ �� ���� �������?
r3.InflateRect(2, 2, 2, 2);  // InflateRect(int dx_l, int dx_r, int dy_t, int dy_b)
r3.InflateRect(3, 3);      // InflateRect(int dx, int dy)
r3.InflateRect(5);        // InflateRect(int dx, int dy)
r3.InflateRect();         // InflateRect(int dx, int dy)
stop


//������� 3.������������� �������. ������������. 
{
	Rect r;
//���������������� ��������� ������. ��������� ������
//�����������

//int tmp = r.m_left; //  private ������������ m_left �� ���������



//������� � ����� Rect ����� void SetAll(...),
//������� ����������� ���������� ������ ������������
//��������. �������� ��������� �����, ��������� ������������. 

r.SetAll(5,6,7,8);

//������� � ����� Rect ������ ����� GetAll(...),
//������� "�������" �������� private-���������� ������.
//�������� ��������� �����, ��������� ������������. 

int input_left = 0, input_right = 0, input_top = 0, input_bottom = 0;
r.GetAll(input_left, input_right, input_top, input_bottom);
stop
}


//������� 4.�������� ���������� ������ � �������� ���������
//�������. ����������� ������� ������ �� ��������. ��������
//�������� � ������������ ����������� ��� �������� ��������
//�� �����, ����������: � ����� ������ ���������� ���������
//� ������������ �����������. 
//�������� ���������� ������� 
// Rect BoundingRect(Rect, Rect);
//������� ��������� ��� ������� ������ Rect �� �������� �
//���������� ������ ������ Rect, ������� �������� ���������������,
//� ������� ������� �������� ��������������. ��� ����������
//�������� ���������� � ����������� ������� ������?

//���������*: ������ ���� �� ������ ��� ����, ��� �������������
//����� ��������� "�����������������", �� ���� m_left>m_right ���/�
//m_top>m_bottom

{

	Rect r1(1, 2, 3, 4), r2(5, 6, 7, 8), r3;

	r3= BoundingRect(r1, r2);          // �������� ���������� �������������� � �������������� ���������� �����������

	stop

		//������� 4�. �������� �������� �� ������.
		//�������� ���������� ������� BoundingRect2, ������� ��������� �� ��
		//������, �������� ��������� �� ������
		//���������� �� ������������ ��� �������� ����������?


	r3 = BoundingRect2(r1, r2);             // ������������ ����������� ��� �������� ���������� �� ���������� 
		stop

}



			//������� 4�.���������� �� �� ������ (BoundingRect) ������� ������


	r3 = r3.BoundingRect3(r1,r2);



		//������� 5. ����� ���������� ������������ � �����������.
		//�������� � ����������
		//����� ���������� ������. ��������� �������� �
		//������������ (�������������) � �����������. ����������: ����� ���
		//������� �� �������� ���������� �����������, � ����� - ����������?
		{
			Rect r1; //Rect()
			Rect*	pR = new Rect(1,2,1,2); //Rect(int m_left, int m_right, int m_top, int m_bottom)
			{
				Rect r2(r1); //Rect(const Rect & other)
				Rect arRect[2]; //Rect()
				for(int i=0; i<3; i++)
				{
					static Rect r3 (i,i,i,i) ;//Rect(int m_left, int m_right, int m_top, int m_bottom)
					Rect r4(*pR);//Rect(const Rect & other)
					Rect r5(i,i,i,i);//Rect(int m_left, int m_right, int m_top, int m_bottom)
				} //~Rect() r5,~Rect() r4

			}//~Rect() arRect,~Rect() r2

			delete pR; //~Rect() pR
			stop

		}//~Rect() r1


		//������� 6.����������� + ���������� = ��������������
		// ���������. ����� MyString
		// ����������� ������������ (�������������) � ����������� ����������
		//���������� ������������� � ����������� �������
		//C ������� ��������� ���������� ����� ����������
		//������ � ������������ ������ ��� ������-����� ������
		{
			MyString	str("It's my string!");
			//�������� ����� GetString(), ������� ��������� ������ � ���������� ������.
			//� ������� cout � ������ GetString() ������������ ������ ������� str
			//���������: ���������, ��� ������� ��������� ����������� ����� GetString().

			std::cout << "String is: " << str.GetString() << std::endl;

			//...
		}
		stop

		
			//6a. ���������������� ��������� ��������. ��������� - �����
			//������������ ��� �������. ���������� ��������� ��������� (���?)
				{
					MyString str1("The first string!");
					MyString str2 = str1;
				
					stop

						//6�. ���������� ����� SetNewString, ������� ����� �������� ������
						// �� �����

						str1.SetNewString("qwertyqwerty");

					stop
		}



		//������� 7.  ������ � ������� ������� ��������� ������:
		//���� ��� ����� ���������� ������. � ����� ����� � ��������� ������
		//������� ���������� ����� (96%), � ������ � ����.
		//������� �������� 1� ���������� ���������� ���������� �� ����� �����
		//� ������ ��������� ��������: �� ������ ��������
		//���������� �� ������ ����� -> ������ �� ������
		//���������� �� ������ ����� -> ������ � ������.
		//��������� ���������� ����� ��������, �� ������� ������������ ������ �
		//������ ����� ������ ������ 50%.

		//Bochka spirt(...);
		//Bochka water(...);

		Barrel barrelOfSpirt(100, 0.96);

		Barrel barrelOfWater(100, 0);
		
		stop

		int counterOfTransfusions = 0;

			while(barrelOfSpirt.getProcentageOfAlcohol() >= 0.5)
			{
				
				barrelOfSpirt.tranfusion(barrelOfWater,1); 
				barrelOfWater.tranfusion(barrelOfSpirt, 1);
				counterOfTransfusions++;
			} 
						
			std::cout << "\nTransfusion complete in: " << counterOfTransfusions << "steps" << std::endl;


			stop
		return 0;
}//~Rect() r3
//end_main
