#pragma once

class Oct
{
	unsigned char m_oct0 : 3;
	unsigned char m_oct1 : 3;
	unsigned char m_oct2 : 2;

	public:

	void intShow();//������� ��� ������������ �����
	void intShowPos(int pos);//������� ����� � �������
	void Edit(int pos, int val);//�������� ����� � �������
	friend union Bytes;
};
