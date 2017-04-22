#pragma once
class Hex
{
	unsigned char m_hex0 : 4;
	unsigned char m_hex1 : 4;


	void printDecade(int decade);
	void editDecade(int value);

 public: 
	void intShow(); //выводим все шестнадцатеричные цифры
	void intShowPos(int pos);//выводим цифру в позиции
	void Edit(int pos, int val);//изменяем цифру в позиции
	friend union Bytes;
};