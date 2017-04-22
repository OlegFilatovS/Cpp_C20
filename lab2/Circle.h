#pragma once

#include "Shape.h"
#include "Rect.h"

class Circle :public Shape {

	int m_centerX, m_centerY, radius;




public:

	//Constructors

	Circle();

	Circle(int radius,int centerX,int centerY);

	Circle(const Circle & other);

	Circle(const Rect & other);

	virtual ~Circle();

	//Setters

	void setRadius(int radius);

	void setCenterX(int centerX);

	void setCenterY(int centerY);


	// Getters


	int getRadius();

	int getCenterX();

	int getCenterY();

	// Others

	void WhereAmI() const override;

	void Inflate(int some) override;


};