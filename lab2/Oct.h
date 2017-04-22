#pragma once

class Oct
{
	unsigned char m_oct0 : 3;
	unsigned char m_oct1 : 3;
	unsigned char m_oct2 : 2;

	public:

	void intShow();//выводим все восьмеричные цифры
	void intShowPos(int pos);//выводим цифру в позиции
	void Edit(int pos, int val);//изменяем цифру в позиции
	friend union Bytes;
};
