#include "Hex.h"
#include <iostream>

void Hex::printDecade(int decade) {


	switch (decade)
	{
	case 10:
		std::cout << 'A';
		break;
	case 11:
		std::cout << 'B';
		break;
	case 12:
		std::cout << 'C';
		break;
	case 13:
		std::cout << 'D';
		break;
	case 14:
		std::cout << 'E';
		break;
	case 15:
		std::cout << 'F';
		break;
	default:
		std::cout << decade;
		break;
	}

}

void Hex::intShow() {

	std::cout << "0x";
	printDecade(m_hex1);
	printDecade(m_hex0);

	std::cout << std::endl;


}


void Hex::intShowPos(int pos) {

	if (pos == 0 || pos == 1) {

	pos ? printDecade(m_hex1) : printDecade(m_hex0);

	}
	else {


		std::cout << "Wrong Position" << std::endl;
	}

}

void Hex::Edit(int pos, int val) {

	if (pos == 0 || pos == 1) {

		pos ? m_hex0 = val : m_hex1 = val;

		intShow();

	}
	else {


		std::cout << "Wrong Position" << std::endl;
	}

}

