#pragma once
#include "MyString.h"
#include <iostream>
enum Sex { MALE, FMALE };

class MyData {

	Sex m_sex;
	size_t m_age;
	MyString m_job;
	float  m_salary;

public:  

	MyData():m_sex(MALE), m_age(0), m_job("Homeless"), m_salary(0) {}
	MyData(Sex s, size_t age, const char* job, float sal):m_sex(s), m_age(age), m_job(job), m_salary(sal) {}

	friend std::ostream& operator<<(std::ostream& os, const MyData& d);

	//MyData(const MyData&  d);
	//MyData & operator=(const MyData& d);
	//
	//
	//MyData(MyData&& d);
	//MyData & operator=(MyData&& d);

	

};