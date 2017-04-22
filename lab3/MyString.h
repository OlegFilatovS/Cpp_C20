#pragma once
#include <iostream>
#include <string>

class MyString
{
	char* m_pStr;	//строка-член класса

public:

	MyString();

	explicit MyString(const char* string);

	MyString(const MyString& other);

	const char* GetString();

	~MyString();
	MyString& operator = (const char* other);
	MyString& operator = (const MyString& other);
	MyString& operator = (MyString&& other);

	MyString(MyString&& other);

	friend std::ostream& operator<<(std::ostream& os, const MyString& str);

	MyString operator + (const MyString& str)const;

	MyString& operator += (const MyString& str);

	bool IsEmpty();

	void SetNewString(const char* string);
};
