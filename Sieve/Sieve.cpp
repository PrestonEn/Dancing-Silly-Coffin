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
#include <fstream>
using std::cout;
using std::setw;


int main(){
	std::ofstream myfile;
	myfile.open("primes.tsv");
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
	int line = 7;
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
			if (line != 0){
				myfile << setw(10) << std::left << pos << "\t";
				line--;
			}
			else{
				myfile << setw(10) << std::left << pos;
				myfile << setw(0) << std::left << "\n";
				line = 7;
			}
			while (pos * multi <= 30000){
				sieve[pos*multi] = true;
				multi++;
			}
		}
		pos++;
	}

	myfile << "\n\n\n";
	line = 2;
	int pair = 1;
	for (int i = 0; i <count-1; i++){
		for (int j = i + 1; j < count; j ++){
			if (primes[j] - primes[i] == 2){
				if (line != 0){
					//cout << setw(18) << std::left << pair << ":(" << primes[i] << ", " << primes[j] << ")\t";
					myfile << setw(18) <<  std::left << pair << ":(" << primes[i] << ", " << primes[j] << ")\t";
					line--;
					pair++;
				}
				else{
					//cout << std::left << setw(18) << pair << ":(" << primes[i] << "," << primes[j] << ")";
					//cout << setw(0) << std::left  << "\n";
					myfile << setw(18) << std::left  << pair << ":(" << primes[i] << "," << primes[j] << ")";
					myfile << setw(0) << std::left  << "\n";
					line = 2;
					pair++;
				}
				break;
			}
		}
	}

	myfile.close();
	getchar();

}

