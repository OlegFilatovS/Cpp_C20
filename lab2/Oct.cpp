#include "Oct.h"
#include <iostream>



void Oct::intShow() {

	std::cout << static_cast<int>(m_oct2) << static_cast<int>(m_oct1) << static_cast<int>(m_oct0) << std::endl;


}


void Oct::intShowPos(int pos) {

	if (pos>0 && pos<2) {

		switch (pos)
		{


		case 0:
			std::cout << static_cast<int>(m_oct2);
			break;

		case 1:
			std::cout << static_cast<int>(m_oct1);
			break;

		case 2:
			std::cout << static_cast<int>(m_oct0);
			break;
		}
		}
	else {


		std::cout << "Wrong Position" << std::endl;
	}

}

void Oct::Edit(int pos, int val) {

	if (pos == 0 || pos == 1 || pos == 2) {

		switch (pos)
		{
		case 0:
			m_oct2 = val;
			break;

		case 1:
			m_oct1 = val;
			break;

		case 2:
			m_oct0 = val;
			break;

		}

		intShow();
	}
	else {


		std::cout << "Wrong Position" << std::endl;
	}

}