/*
Preston Engstrom
5228549
COSC 4f00

PROJECT:
Dancing Silly Coffin

GIT:
https://github.com/PrestonEn/Dancing-Silly-Coffin.git

DESCRIPTION:
Approximation engine for pi using random floating point pairs
*/
#include <iostream>
#include "point.cpp"
#include "RandomNG.cpp"
using namespace std;

int main(){

	RandomNG rng = RandomNG(10000, 5000, 5);
	Point center = Point(0.5, 0.5);
	Point dist = Point(0.6, 0.6);
	center.dist(dist);

	getchar();
}

