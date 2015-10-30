/*
Preston Engstrom
5228549
COSC 4f00
PROJECT:
Dancing Silly Coffin
GIT:
https://github.com/PrestonEn/Dancing-Silly-Coffin.git
DESCRIPTION:
Class to implement a random number generator, using a constant seed.
In the intrest of modularity and reuse in part 3 of this assignment,
it is defined as a standalone class.
*/

#include <iostream>
#include "RandomNG.h"
using namespace std;


RandomNG::RandomNG(int seed1, int seed2, int seed3) :
	_seed_1(seed1), _seed_2(seed2), _seed_3(seed3)
{}

float RandomNG::roll(){
	float tmp;
	_seed_1 = 171 * (_seed_1 % 177) - 2 * (_seed_1 / 177);
	if (_seed_1  < 0) _seed_1 += 30269;

	_seed_2 = 172 * (_seed_2 % 176) - 35 * (_seed_2 / 176);
	if (_seed_2 < 0) _seed_2 += 30307;

	_seed_3 = 170 * (_seed_3 % 178) - 63 * (_seed_3 / 178);
	if (_seed_3 < 0) _seed_3 += 30323;

	tmp = _seed_1 / 30269.f + _seed_2 / 30307.f + _seed_3 / 30323.f;
	//cout << tmp - (int)tmp << endl;
	return tmp - (int)tmp;
}
