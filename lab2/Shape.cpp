#include "Shape.h"
#include <iostream>


Shape::Shape() {

	color = Red;

}

Shape::~Shape() {

	std::cout << "Im shape destructor" << std::endl;

}

Shape::Shape(const Shape& other) {

	this->color = other.color;

}

Shape::Shape(Color color) {

	this->color = color;

}

void Shape::SetColor(Color color) {

	this->color = color;

}

void Shape::Inflate(int some) {


}

Color Shape::getColor() {

	return color;
}

void Shape::WhereAmI() const {

	std::cout << "Im in Shape class" << std::endl;

}