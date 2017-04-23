#pragma once

#include "Pair.h"
#include <iostream>


class Base {
	Pair **pBase;  
	size_t  m_count;         
	size_t  m_capacity; 
public:

	Base() :pBase(nullptr), m_count(0), m_capacity(0) {}

	~Base();

	Base(const  Base& bd);

	Base( Base&& bd);

	Base& operator=(const Base& bd);   //оптимизированный!!! 

	Base& operator=( Base&& bd);

	MyData& operator[](const char * key);

	int deletePairForKey(const char*  key);

	friend std::ostream& operator<<(std::ostream& os, const Base &bd);

	void printValueForKey(const char*  key);


};