/*
Quick implementation of neighbour check function
for an array, creating a taurus.

remove one loop to create a cylander
*/

#include <iostream>
#include "Board.h"

using namespace std;

int Board::_ARRAY_WDH;
int Board::_ARRAY_HGT;
//Used privatly in method gnNxtSt
int Board::cntNghbrs(int x, int y){
	int cnt = 0;
	int xP, yP;	//xPrime, yPrime, cell address relative to (x,y)

	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++){

			xP = (x+((i%_ARRAY_WDH))) % _ARRAY_WDH;
			yP = (y+((j%_ARRAY_HGT))) % _ARRAY_HGT;
			if (xP == -1)
				xP = _ARRAY_WDH - 1;
			if (xP >= _ARRAY_WDH)
				xP = 0;
			if (yP == -1)
				yP = _ARRAY_HGT - 1;
			if (yP >= _ARRAY_HGT)
				xP = 0;
			//std::cout << xP << "\t" << yP << "\t" << _state[xP][yP] << "\n";
			if ( i == 0 && j == 0){
	
			}
			else if(_state[xP][yP]){
				cnt++;
			}
		}
	return cnt;
}

void Board::setSt(int x, int y, bool state){
	 //_state[x][y] = state;
}

bool Board::getSt(int x, int y){
	return _state[x][y];
}


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
	//for (int i = 0; i < _ARRAY_WDH; i++)
	//	delete[] _state[i];
	//delete[] _state;
}


void Board::initBoard(RandomNG rng){
	for (int i = 0; i < _ARRAY_WDH; i++)
	for (int j = 0; j < _ARRAY_HGT; j++){
		if (rng.roll() >= (float)0.6){
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
	for (int i = 0; i < _ARRAY_WDH; i++)
	for (int j = 0; j < _ARRAY_HGT; j++){
		//if alive and 2 nghbrs, alive 
		//if dead or alive and 3 nghbrs, alive
		if (this->cntNghbrs(i, j) == 2 && this->getSt(i, j) == 1){
			nextState._state[i][j]=1;
		}
		else if (this->cntNghbrs(i, j) == 3){
			nextState._state[i][j] = 1;
		}
		else{	//cell is kill
			nextState._state[i][j]=0;
		}
	}
	return nextState;
}

//test if equal
bool Board::isEqv(Board other){
	for (int i = 0; i < _ARRAY_WDH; i++)
	for (int j = 0; j < _ARRAY_HGT; j++){
		if (_state[i][j] != other._state[i][j])
			return 0;
	}
		return 1;
}

//print as text
void Board::prntSt(){
	for (int i = 0; i < _ARRAY_WDH; i++){
		for (int j = 0; j < _ARRAY_HGT; j++){
			if (_state[i][j]){
				cout << "|" << "X";
			}
			else{ cout << "|" << " "; }
		}
		cout << "|" << "\n";
	}
}

int Board::testCount(int i, int j){
	return cntNghbrs(i, j);
}