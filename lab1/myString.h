#pragma once
class MyString
{
    char* m_pStr;	//������-���� ������

public:
	
	//MyString();

	MyString(const char* string);

	MyString(const MyString& other);

	const char* GetString();

	~MyString();

	void SetNewString(const char* string);
};
