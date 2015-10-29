#pragma once


class Point{
private:
	float _x;
	float _y;

public:
	Point(float x, float y);
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);

	/*Calculate Euclidean distance from one point
	to another
	*/
	float dist(Point other);

};