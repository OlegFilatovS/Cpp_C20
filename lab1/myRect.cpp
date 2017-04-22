#include "myRect.h"
#include <iostream>

Rect::Rect(int left, int right, int top, int bottom)
{

	m_left = left; m_right = right; m_top = top; m_bottom = bottom;
	Norm();
}

Rect::Rect()
{
	m_left = 0; m_right = 0; m_top = 0; m_bottom = 0;
}

Rect::Rect(const Rect & other)
{
	m_left = other.m_left;
	m_right = other.m_right;
	m_top = other.m_top;
	m_bottom = other.m_bottom;
}

Rect::~Rect() {
	//__asm nop
	std::cout << "Default constructor called, params of object is" << std::endl;
	std::cout << this->m_bottom << " " << this->m_left << " " << this->m_bottom << " " << this->m_top << std::endl;

}

void Rect::Norm()
{
	int tmp ;

	if (m_left > m_right)
	{
		tmp = m_left;
		m_left = m_right;
		m_right = tmp;
	}

	if (m_top > m_bottom)
	{
		tmp = m_bottom;
		m_bottom = m_top;
		m_top = tmp;
	}
}

void Rect::InflateRect(int dx_l, int dx_r, int dy_t, int dy_b)
{
	m_left -= dx_l;
	m_right += dx_r;
	m_top -= dy_t;
	m_bottom += dy_b;
	Norm();
}

void Rect::InflateRect(int dx, int dy)
{
	Rect::InflateRect(dx,dx,dy,dy);
}

void Rect::SetAll(int m_left, int m_right, int m_top, int m_bottom)
{
	this->m_left = m_left;
	this->m_right = m_right;
	this->m_top = m_top;
	this->m_bottom = m_bottom;

	Norm();
}

void Rect::GetAll(int& m_left, int& m_right, int& m_top, int& m_bottom) const
{
	m_left =this-> m_left;
	m_right = this-> m_right;
	m_top = this-> m_top;
	m_bottom = this-> m_bottom;
}



Rect BoundingRect(Rect firstRectangle, Rect secondRectangle) {

	//Rect returningRect;

	int fRectLeft, fRectRight, fRectTop, fRectBottom;

	firstRectangle.GetAll(fRectLeft, fRectRight, fRectTop, fRectBottom);

	int sRectLeft, sRectRight, sRectTop, sRectBottom;

	secondRectangle.GetAll(sRectLeft, sRectRight, sRectTop, sRectBottom);

	int rRectLeft, rRectRight, rRectTop, rRectBottom;

	(fRectLeft > sRectLeft) ? (rRectLeft = sRectLeft) : (rRectLeft = fRectLeft);
	(fRectRight > sRectRight) ? (rRectRight = fRectRight) : (rRectRight = sRectRight);
	(fRectTop > sRectTop) ? (rRectTop = sRectLeft) : (rRectTop = fRectLeft);
	(fRectBottom > sRectBottom) ? (rRectBottom = fRectLeft) : (rRectBottom = sRectLeft);

//	returningRect.SetAll(rRectLeft, rRectRight, rRectTop, rRectBottom);


	//return returningRect;
	return Rect(rRectLeft, rRectRight, rRectTop, rRectBottom);
}

Rect BoundingRect2(const Rect& firstRectangle,const Rect& secondRectangle) {

	

	int fRectLeft, fRectRight, fRectTop, fRectBottom;

	firstRectangle.GetAll(fRectLeft, fRectRight, fRectTop, fRectBottom); // с константным обьектом может работать только константый метод

	int sRectLeft, sRectRight, sRectTop, sRectBottom;

	secondRectangle.GetAll(sRectLeft, sRectRight, sRectTop, sRectBottom);

	int rRectLeft, rRectRight, rRectTop, rRectBottom;

	(fRectLeft > sRectLeft) ? (rRectLeft = sRectLeft) : (rRectLeft = fRectLeft);
	(fRectRight > sRectRight) ? (rRectRight = fRectRight) : (rRectRight = sRectRight);
	(fRectTop > sRectTop) ? (rRectTop = sRectLeft) : (rRectTop = fRectLeft);
	(fRectBottom > sRectBottom) ? (rRectBottom = fRectLeft) : (rRectBottom = sRectLeft);



	return Rect(rRectLeft, rRectRight, rRectTop, rRectBottom);
}

Rect Rect::BoundingRect3(const Rect& firstRectangle, const Rect& secondRectangle) {

	int fRectLeft, fRectRight, fRectTop, fRectBottom;

	firstRectangle.GetAll(fRectLeft, fRectRight, fRectTop, fRectBottom); // с константным обьектом может работать только константый метод

	int sRectLeft, sRectRight, sRectTop, sRectBottom;

	secondRectangle.GetAll(sRectLeft, sRectRight, sRectTop, sRectBottom);

	int rRectLeft, rRectRight, rRectTop, rRectBottom;

	(fRectLeft > sRectLeft) ? (rRectLeft = sRectLeft) : (rRectLeft = fRectLeft);
	(fRectRight > sRectRight) ? (rRectRight = fRectRight) : (rRectRight = sRectRight);
	(fRectTop > sRectTop) ? (rRectTop = sRectLeft) : (rRectTop = fRectLeft);
	(fRectBottom > sRectBottom) ? (rRectBottom = fRectLeft) : (rRectBottom = sRectLeft);



	return Rect(rRectLeft, rRectRight, rRectTop, rRectBottom);
}
