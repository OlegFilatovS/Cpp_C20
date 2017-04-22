#include <string>
#include "myString.h"
using namespace std;

// Определение конструктора.

MyString::MyString(const char* string) {

	m_pStr = new char[strlen(string) + 1];

	strcpy(m_pStr, string);

}

// Определение конструктора копирования

MyString::MyString(const MyString& other) {

	m_pStr = new char[strlen(other.m_pStr) + 1];

	strcpy(m_pStr, other.m_pStr);

}

//Getter

const char* MyString::GetString() {

	return m_pStr;

}

void MyString::SetNewString(const char* string) {

	//if (strlen(string) > strlen(m_pStr)) {

		delete[] m_pStr;

		m_pStr = new char[strlen(string) + 1];

	//	strcpy(m_pStr, string);

//	}
//	else {

		strcpy(m_pStr, string);

//	}


}


// Определение деструктора.


MyString::~MyString() {

	delete[] m_pStr;

}