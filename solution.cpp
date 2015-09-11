/*-----------------------------------------------------------------
* Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
				   2015 Brandon Min <brandon.min@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
*---------------------------------------------------------------------*/

//Assignment 2: Sieve of Eratosthenes

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


#include <string>
using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;


int find_max(const string& infilename);



void sieve(const int size, bool primes[]);


int write_primes(const int size, 
				 bool primes[], 
				 const string& infilename, 
				 const string& outfilename);




int write_composites(const int size,
					 bool primes[],
					 const string& infilename,
					 const string& outfilename);



//------------------------------------------------------------

int main(){
	int max = find_max("input.txt");
	if (max == -1){
		cout << "ERROR in 'find_max()'" << endl;
		return 1; //error
	}

	bool * primes = (bool *)malloc(sizeof(bool)*(max + 1));

	sieve(max + 1, primes);

	int ret;

	ret = write_primes(max + 1, primes, "input.txt", "primes.txt");
	if (ret == -1){

		cout << "ERROR in 'write_primes()'" << endl;
		return 1; //error

	}



	ret = write_composites(max + 1, primes, "input.txt", "composites.txt");

	if (ret == -1){

		cout << "ERROR in 'write_composites()'" << endl;
		return 1; //error

	}


	return 0;
}


//---------------------------------------------------------------




//prototype functions
