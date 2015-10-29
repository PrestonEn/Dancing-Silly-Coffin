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
#include <iomanip>	//setw
using std::cout;
using std::setw;


int main(){
	std::vector<bool> sieve;
	std::vector<int> primes;
	//in the range of 0-30000, interested only in >2
	int pos = 2;			//position in boolean array used to test as prime
	int multi;				//multiplier for sieve
	int count = 0;			//number of primes found
	int knownPrimes = 1000; //size of prime storage vector
	
	sieve.resize(30001); 
	primes.resize(knownPrimes); //estimate value of number of primes

	//iterator to initialize all members to true
	for (std::vector<bool>::iterator it = sieve.begin(); it != sieve.end(); ++it){
		*it = false;
	}

	while (pos <= 30000){
		multi = 2;
		if (sieve[pos] == false){
			//if we fill the vector of known primes, double its size
			if (count == knownPrimes - 1)
				knownPrimes = knownPrimes * 2;

			primes.resize(knownPrimes);
			primes[count] = pos;
			count++;
			sieve[pos] = true;
			cout << setw(10) << pos;
			while (pos * multi <= 30000){
				sieve[pos*multi] = true;
				multi++;
			}
		}
		pos++;
	}
	//size the vector to reflect the number of primes found


	for (int i = 0; i <count-1; i++){
		for (int j = i + 1; j < count; j ++){
			if (primes[j] - primes[i] == 2){
				cout << setw(15) << "pair(" << primes[i] << ", " << primes[j] << ")";
				break;
			}
		}
	}

	getchar();

}

