#include "Pair.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Pair& pair) {
	os << pair.m_key << pair.m_value;
	return os;
};
