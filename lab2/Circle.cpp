#include "Circle.h"
#include <iostream>
#include "Rect.h"

Circle::Circle() {
	radius = 0.0;
}

Circle::Circle(int radius, int centerX, int centerY):Shape(color) {

	this->radius = radius;
	m_centerX = centerX;
	m_centerY = centerY;
}

Circle::~Circle() {

	std::cout << "Im circle destructor" << std::endl;

}

Circle::Circle(const Circle & other) :Shape(other)

{

	this->radius = other.radius;
	this->m_centerX = other.m_centerX;
	this->m_centerY = other.m_centerY;
	
}

Circle::Circle(const Rect & other) : Shape(other)

{
	int left, right, top, bottom;
	other.GetAll(left, right, top, bottom);

	m_centerX = (right - left) / 2;
	m_centerY = (bottom - top) / 2;

	radius = ((left - right) + (bottom - top))/2;



}

void Circle::setRadius(int radius) {

	this->radius = radius;
}


void Circle::Inflate(int some) {
	
	m_centerX += some;

	m_centerY += some;

	radius += some;

}


void Circle::setCenterX(int centerX) {

	m_centerX = centerX;
}

void Circle::setCenterY(int centerY) {

	m_centerY = centerY;

}

int Circle::getRadius() {

	return radius;

}

int Circle::getCenterX() {

	return m_centerX;

}

int Circle::getCenterY() {

	return m_centerY;

}


void Circle::WhereAmI() const {

	std::cout << "Im in Circle class" << std::endl;

}