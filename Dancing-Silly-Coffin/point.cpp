/*
Preston Engstrom
5228549
COSC 4f00

PROJECT:
Dancing Silly Coffin

GIT:
https://github.com/PrestonEn/Dancing-Silly-Coffin.git

DESCRIPTION:
Wrapper class of 2 floating points
*/
#include <iostream>
class Point{
	float _x;
	float _y;
public:
	Point(float x, float y){
			_x = x;
			_y = y;
	}

	float getX(){
		return this->_x;
	}

	float getY(){
		return this->_y;
	}

	void setX(float x){
		_x = x;
	}

	void setY(float y){
		_y = y;
	}

	float dist(Point other){
		float xs = _x - other._x;
		float ys = _y - other._y;
		float d = sqrt((xs*xs)+(ys*ys));
		return d;
	}

};