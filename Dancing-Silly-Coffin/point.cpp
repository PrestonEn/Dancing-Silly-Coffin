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
	float x_;
	float y_;
public:
	Point(float x, float y){
			x_ = x;
			y_ = y;
	}

	float getX(){
		return this->x_;
	}

	float getY(){
		return this->y_;
	}

	float dist(Point other){
		float d = sqrt(pow((this->x_ + other.getX()),2) + pow((this->y_ + other.getX()),2));
		std::cout << d;
		return d;
	}

};