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
	static int ARRAY_WDH;
	static int ARRAY_HGT;
	bool **array2D;
public:
	Board::Board(){

	}

	

	int countAdj(int x, int y){
		//check surrounding cells of array, where the 
		//array is a tuarus
		for (int i = -1; i < 2; i++){
			for (int j = -1; j < 2; j++){
				std::cout << (x + ((i%ARRAY_WDH))) % ARRAY_WDH;
				std::cout << (y + ((j%ARRAY_HGT))) % ARRAY_HGT;
				//get array values
			}
			std::cout << "\n";
		}
		return 0;
	}

};