#include "Point.h"



Point::Point(int x, int y) : m_x(x), m_y(y) {}

Point::Point():m_x(0),m_y(0) {}

Point& Point::operator += (const Point& other) {

	m_x = other.m_x + m_x;
	m_y = other.m_y + m_y;

	return *this;
}

Point& Point::operator += (int some) {

	m_x += some;

	m_y += some;


	return *this;
}

Point Point::operator + (const Point other) {

	return Point(m_x + other.m_x, m_y + other.m_y);

}

Point Point::operator + (int some) {


	return Point(m_x + some, m_y + some);



}

Point Point::operator + ()
{
	return *this;
};

Point Point::operator - ()
{
	return Point(-m_x, -m_y);
};
