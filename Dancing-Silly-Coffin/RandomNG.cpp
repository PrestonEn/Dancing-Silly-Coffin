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
using namespace std;

class RandomNG{

//member definitions
//private:	members are private by default
	int seed_1_;
	int seed_2_;
	int seed_3_;

public:
	RandomNG(int seed1, int seed2, int seed3){
		seed_1_ = seed1;
		seed_2_ = seed2;
		seed_3_ = seed3;
	}
	

	float RandomNG::roll(){
		float tmp;
		this->seed_1_ = 171 * (this->seed_1_ % 177) - 2 * (this->seed_1_ / 177);
		if (this->seed_1_  < 0){ this->seed_1_ += 30269; }

		this->seed_2_ = 172 * (this->seed_2_ % 176) - 35 * (this->seed_2_ / 176);
		if (this->seed_2_ < 0){ this->seed_2_ += 30307; }

		this->seed_3_ = 170 * (this->seed_3_ % 178) - 63 * (this->seed_3_ / 178);
		if (this->seed_3_ < 0){ this->seed_3_ += 30323; }

		tmp = this->seed_1_ / 30269.0 + this->seed_2_ / 30307.0 + this->seed_3_ / 30323.0;
		cout << tmp - (int)tmp << endl;
		return tmp - (int)tmp;
	}
};


