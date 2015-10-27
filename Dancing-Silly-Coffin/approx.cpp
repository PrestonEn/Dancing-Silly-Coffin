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
	Point center = Point(0.5, 0.5); //center of point, on a 1.0 by 1.0 board
	Point shot = Point(0.f, 0.f);	//init point where "shot lands"
	
	
	int total = 32000; 		//number of total shots
	int hitCount = 0;		//shots with euclidian distance to center <= 0.5
	float dist;				//temp var for holding dist of shot

	//Calculate an approx. of pi every 1000 shots for 32000 consecutive shots
	//using formula 4.0 * (float)N / (float)M. M is total number of #shotsfired
	//N is number of shots that hit
	//4.0 * (hits)/1000
	//4.0 * (hits)/2000 .... ect
	while (total >= 0){
		hitCount = 0;
		for (int i = 0; i < 1000; i++){
			shot.setX(rng.roll());
			shot.setY(rng.roll());

		}
	}


	getchar();
}

