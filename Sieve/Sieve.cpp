/*
Preston Engstrom
5228549
COSC 4f00

PROJECT:
Dancing Silly Coffin

GIT:
https://github.com/PrestonEn/Dancing-Silly-Coffin.git

DESCRIPTION:
Implementation of Sieve or Erathostenes
*/

#include <iostream>
#include <vector>

int main(){
	std::vector<bool> sieve; 
	//in the range of 0-30000, interested only in >2
	sieve.resize(30000); 

	//iterator to initialize all members to true
	for (std::vector<bool>::iterator it = sieve.begin(); it != sieve.end(); ++it){
		*it = true;
	}




}

