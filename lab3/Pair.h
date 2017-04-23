#pragma once
#include <iostream>
#include "MyData.h"
#include "MyString.h"


class Pair {
	MyString m_key;       
	MyData   m_value; 


	Pair() :m_key("Empty"), m_value() { }

	friend std::ostream& operator<<(std::ostream& os, const Pair& pair);

	/*Pair(const Pair& other);
	Pair& operator=(const Pair& other);
	Pair(Pair&& other);
	Pair& operator=(Pair&& other);
	bool operator==(const char *k) const;
	*/

	friend class Base;
	
};