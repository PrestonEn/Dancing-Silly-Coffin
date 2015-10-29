/*
Quick implementation of neighbour check function
for an array, creating a taurus.

remove one loop to create a cylander
*/

#include <iostream>
#include "RandomNG.h"
#include "Board.h"

class Board{
private:
	static int _ARRAY_WDH;
	static int _ARRAY_HGT;
	bool **_state;

	//Used privatly in method gnNxtSt
	int cntNghbrs(int x, int y){
		int cnt = 0;
		int xP, yP;	//xPrime, yPrime, cell address relative to (x,y)

		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++){
				xP = (x + ((i%_ARRAY_WDH))) % _ARRAY_WDH;
				yP = (y + ((j%_ARRAY_HGT))) % _ARRAY_HGT;
				if (_state[xP][yP]){
					cnt++;
				}
			}
		return cnt;
	}

	bool setSt(int x, int y, bool state){
		return _state[x][y];
	}

	bool getSt(int x, int y){
		return _state[x][y];
	}

public:
	//construct a blank state
	Board::Board(int wth, int hgt){
		_ARRAY_WDH = wth;
		_ARRAY_HGT = hgt;
		//dynamically allocated bool array allows for states of arbitrary size
		_state = new bool*[wth];
		for (int i = 0; i < wth; i++)
			_state[i] = new bool[hgt];
	}

	//deallocate state
	Board::~Board(){
		for (int i = 0; i < _ARRAY_WDH; i++)
			delete[] _state[i];
		delete[] _state;
	}


	void Board::initBoard(RandomNG rng){
		for (int i = 0; i < _ARRAY_HGT; i++)
		for (int j = 0; j < _ARRAY_HGT; j++){
			if (rng.roll >= 0.6){
				_state[i][j] = 1;
			}
			else {
				_state[i][j] = 0;
			}
		}

	}

	//return a new state based on THIS
	Board Board::gnNxtSt(){
		Board nextState = Board(_ARRAY_WDH, _ARRAY_HGT);
		for (int i = 0; i < _ARRAY_HGT; i++)
		for (int j = 0; j < _ARRAY_HGT; j++){
			//if alive and 2 nghbrs, alive 
			//if dead or alive and 3 nghbrs, alive
			if (this->cntNghbrs(i, j) == 2 && this->getSt(i, j) || this->cntNghbrs(i, j) == 3){
				nextState.setSt(i, j, 1);
			}
			else{	//cell is kill
				nextState.setSt(i, j, 0);
			}
		}
		return nextState;
	}

	//test if equal
	bool Board::isEqv(Board other){
		//TODO
	}

	//print as text
	void Board::prntSt(){
		//TODO
	}

};