#pragma once

class Rect {
	//int m_left = 0, m_right = 0, m_top = 0, m_bottom = 0;
	int m_left, m_right, m_top, m_bottom;

public:

	/*Constructors*/
	Rect(int m_left, int m_right, int m_top, int m_bottom);

	Rect();

	Rect(const Rect & other);

	/*Setters*/


	void SetAll(int m_left, int m_right, int m_top, int m_bottom);
	
	/*Getters*/

	void GetAll(int& m_left, int& m_right, int& m_top, int& m_bottom) const;

	/*Others*/

	void Norm();

	void InflateRect(int dx_l, int dx_r, int dy_t, int dy_b);

	void InflateRect(int dx = 1, int dy = 1);

	Rect BoundingRect3(const Rect& firstRectangle, const Rect& secondRectangle);


	/*Destructor*/

	~Rect();



};

/*Global funcs*/

Rect BoundingRect(Rect firstRectangle,Rect secondRectangle);


Rect BoundingRect2(const Rect& firstRectangle, const Rect& secondRectangle);



