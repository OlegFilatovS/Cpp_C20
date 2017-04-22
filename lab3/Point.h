#pragma once

class  Point
{
	int m_x, m_y;


public:

	 Point();
	
	 Point(int x, int y);


	 Point& operator += (const Point& other);

	 Point& operator += (int some);

	 Point operator + (const Point other);

	 Point operator + (int some);

	 Point Point::operator + ();

	 Point Point::operator - ();



	 friend Point operator-(Point& pt, int some);

	 friend Point operator+(int some, Point& pt);

	 friend Point operator-(Point& pt1, Point& pt2);
		


};

