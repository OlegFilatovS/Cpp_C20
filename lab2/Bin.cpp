#include "Bin.h"
#include <iostream>


void Bin::Show() {

	int arr[] = { m_bin7 ,m_bin6,m_bin5,m_bin4,m_bin3,m_bin2,m_bin1 ,m_bin0};

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {

		std::cout << arr[i];

	}

	std::cout << std::endl;
}


void Bin::ShowPos(int pos) {

	if (pos>0&&pos<7) {

		switch (pos)
		{

		case 0:
			std::cout << static_cast<int>(m_bin7);
			break;
		case 1:
			std::cout << static_cast<int>(m_bin6);
			break;
		case 2:
			std::cout << static_cast<int>(m_bin5);
			break;
		case 3:
			std::cout << static_cast<int>(m_bin4);
			break;
		case 4:
			std::cout << static_cast<int>(m_bin3);
			break;
		case 5:
			std::cout << static_cast<int>(m_bin2);
			break;
		case 6:
			std::cout << static_cast<int>(m_bin1);
			break;
		case 7:
			std::cout << static_cast<int>(m_bin0);
			break;
		}

	}
	else {

		std::cout << "Wrong Position" << std::endl;
	}

}

void Bin::Edit(int pos, int val) {

	if (pos>0 && pos<7) {

		switch (pos)
		{

		case 0:
			m_bin7 = val;
			break;
		case 1:
			m_bin7 = val;
			break;
		case 2:
			m_bin7 = val;
			break;
		case 3:
			m_bin7 = val;
			break;
		case 4:
			m_bin7 = val;
			break;
		case 5:
			m_bin7 = val;
			break;
		case 6:
			m_bin7 = val;
			break;
		case 7:
			m_bin7 = val;
			break;
		}

		Show();

	}
	else {

		std::cout << "Wrong Position" << std::endl;
	}
}