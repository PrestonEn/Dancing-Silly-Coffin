#include <iostream>
#include "Board.h"
#include "RandomNG.h"

int main(){
	RandomNG rng = RandomNG::RandomNG(10,50,1000);
	Board *test = new Board(20, 20);
	test->initBoard(rng);
	int count = 20;
	while (count != 0){
		test->prntSt();
		std::cout << "\n";
		(*test) = test->gnNxtSt();
		std::cout << "\n";
		count--;
		std::cout << "Press Enter To Evolve State" << "\n";
		getchar();
	}

	getchar();
}
