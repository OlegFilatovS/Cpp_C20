#pragma once
class MyString
{
    char* m_pStr;	//строка-член класса

public:
	
	//MyString();

	MyString(const char* string);

	MyString(const MyString& other);

	const char* GetString();

	~MyString();

	void SetNewString(const char* string);
};
