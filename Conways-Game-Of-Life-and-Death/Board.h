#ifndef _BOARD_H_
#define _BOARD_H_

#include "RandomNG.h"

class Board{
private:
	static int _ARRAY_WDH;
	static int _ARRAY_HGT;
	bool **_state;

	//Used privatly in method gnNxtSt
	int cntNghbrs(int x, int y);

	void setSt(int x, int y, bool state);

	bool Board::getSt(int x, int y);

public:
	//construct a blank state
	Board::Board(int wth, int hgt);

	//deallocate state
	Board::~Board();

	void Board::initBoard(RandomNG rng);

	//return a new state based on THIS
	Board Board::gnNxtSt();

	//test if equal
	bool Board::isEqv(Board other);

	//print as text
	void Board::prntSt();

	int Board::testCount(int i, int j);
};

#endif