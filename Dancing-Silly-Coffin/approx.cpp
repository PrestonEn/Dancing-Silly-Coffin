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
#include <iostream> //cout
#include <iomanip>	//setw
#include <fstream>
#include "point.h"
#include "RandomNG.h"
using std::cout;
using std::setw;




int main(){

	RandomNG rng = RandomNG(10000, 5000, 5);
	Point center = Point(0.5, 0.5); //center of point, on a 1.0 by 1.0 board
	Point shot = Point(0.f, 0.f);	//init point where "shot lands"
	
	//file init

	
	int total = 32000; 		//number of total shots
	int shotsFired = 0;		//count of shots fired
	int hitCount = 0;		//shots with euclidian distance to center <= 0.5
	int field_per_line = 2;
	int count = 0;
	//Calculate an approx. of pi every 1000 shots for 32000 consecutive shots
	//using formula 4.0 * (float)N / (float)M. M is total number of #shotsFired
	//N is number of shots that hit
	//4.0 * (hits)/1000
	//4.0 * (hits)/2000 .... ect
	while (shotsFired < total)
		for (int i = 0; i < 1000; i++){
			shotsFired++;
			shot.setX(rng.roll());
			shot.setY(rng.roll());
			
			if (shot.dist(center) < 0.5f){
				hitCount++;
			}

		}
	getchar();
}

