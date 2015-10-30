#ifndef _RANDOMNG_H_
#define _RANDOMNG_H_

class RandomNG{

private:	//members are private by default
	int _seed_1;
	int _seed_2;
	int _seed_3;

public:
	RandomNG(int seed1, int seed2, int seed3);
	float roll();
};

#endif