#pragma once
class Hex
{
	unsigned char m_hex0 : 4;
	unsigned char m_hex1 : 4;


	void printDecade(int decade);
	void editDecade(int value);

 public: 
	void intShow(); //������� ��� ����������������� �����
	void intShowPos(int pos);//������� ����� � �������
	void Edit(int pos, int val);//�������� ����� � �������
	friend union Bytes;
};