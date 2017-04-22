#include <string>
#include "myString.h"
using namespace std;

// Определение конструктора.


MyString::MyString() {

	//m_pStr = nullptr;

	m_pStr = new char[1];
	m_pStr[0] = 0;
}


bool MyString::IsEmpty() {

	return m_pStr == nullptr;

}

MyString& MyString::operator = (const MyString& other) {


	if (this != &other) {


		m_pStr = new char[strlen(other.m_pStr) + 1];

		strcpy(m_pStr, other.m_pStr);

	}

	return *this;


}

MyString& MyString::operator = (const char* other) {

	
	m_pStr = new char[strlen(other) + 1];

	strcpy(m_pStr, other);

	return *this;

}


MyString& MyString::operator = (MyString&& other) {


	if (this != &other) {


		m_pStr = other.m_pStr;

		other.m_pStr = nullptr;

	}

	return *this;


}



MyString::MyString(const char* string) {

	m_pStr = new char[strlen(string) + 1];

	strcpy(m_pStr, string);

}

// Определение конструктора копирования

MyString::MyString(const MyString& other) {

	m_pStr = new char[strlen(other.m_pStr) + 1];

	strcpy(m_pStr, other.m_pStr);

}

MyString::MyString(MyString&& other) {

	m_pStr = other.m_pStr;

	other.m_pStr = nullptr;

}

//Getter

const char* MyString::GetString() {

	return m_pStr;

}

void MyString::SetNewString(const char* string) {



		delete[] m_pStr;

		m_pStr = new char[strlen(string) + 1];

	

	strcpy(m_pStr, string);

	//	}


}


// Определение деструктора.


MyString::~MyString() {

	delete[] m_pStr;

}