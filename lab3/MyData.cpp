#include "MyData.h"
#include <iostream>


std::ostream& operator<<(std::ostream& os, const MyData& data) {
	os << data.m_age << " " << data.m_job << " " << data.m_salary << " " << ((data.m_sex) ? "MALE" : "FEMALE") << std::endl;
	return os;
};

