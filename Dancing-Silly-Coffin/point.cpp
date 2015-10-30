/*
Preston Engstrom
5228549
COSC 4f00

PROJECT:
Dancing Silly Coffin

GIT:
https://github.com/PrestonEn/Dancing-Silly-Coffin.git

DESCRIPTION:
Point in 2D space
*/
#include <iostream>
#include "point.h"

Point::Point(float x, float y):
	_x(x), _y(y)
{}

float Point::getX(){
	return this->_x;
}

float Point::getY(){
	return this->_y;
}

void Point::setX(float x){
	_x = x;
}

void Point::setY(float y){
	_y = y;
}

/*Calculate Euclidean distance from one point 
to another
*/
float Point::dist(Point other){
	float xs = _x - other._x;
	float ys = _y - other._y;
	float d = sqrt((xs*xs)+(ys*ys));
	return d;
}

