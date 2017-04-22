#pragma once
enum Color {Red,Green,Blue,Yellow};

class Shape {

    protected:

	Color color;


public:

	Shape();

	virtual ~Shape();

	Shape(Color color);

	Shape(const Shape& other);

	void SetColor(Color color);

	Color getColor();


//	virtual void Inflate(int) = 0;

	virtual void Inflate(int);

	virtual void WhereAmI() const;



};