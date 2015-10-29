#pragma once


#include "RandomNG.h"
class Board{
private:
	static int ARRAY_WDH;
	static int ARRAY_HGT;
	bool **state;

	//Never need to publicly access,
	//only used in update
	int countNeighbours(int x, int y);


public:
	Board(int c, int r);
	~Board();

	void initBoard(RandomNG rng);
	//updateBoard uses count neighbours
	Board updateBoard();


};