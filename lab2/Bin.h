#pragma once

class Bin
{
	unsigned char m_bin0 : 1; //или bool
	unsigned char m_bin1 : 1;
	unsigned char m_bin2 : 1;
	unsigned char m_bin3 : 1;
	unsigned char m_bin4 : 1;
	unsigned char m_bin5 : 1;
	unsigned char m_bin6 : 1;
	unsigned char m_bin7 : 1;

    public:

	void Show(); //выводим все двоичные цифры

	void ShowPos(int pos); //выводим цифру в позиции

	void Edit(int pos, int val); //изменяем цифру в позиции

	friend union Bytes;
	//При реализации методов предусмотрите корректность передаваемых параметров
	//Используйте потоковый вывод (std::cout)
};