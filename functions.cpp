#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "functions.hpp"

using namespace std;


int isPrimeNumber(bool* isPrime,primePotentialInt_t number) {
    int i=0;
    int n=number;

    // 0 and 1 are not prime numbers
    if (n == 0 || n == 1) {
        *isPrime = false;
    }
    else {
        for (i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                *isPrime = false;
                break;
            }
        }
    }
    if (isPrime)
        cout << n << " is a prime number\n";
    return 0;
}


int setLastPrime(primePotentialInt_t prime){
  ofstream myfile;
  myfile.open("./primes.txt", std::ios_base::app);
  if(myfile.is_open()) {
    myfile << prime ;
    cout << prime << "\n";
    myfile.close();
    return 0;
  }
  return 1;
}


void getLastPrime(primePotentialInt_t* prime)
{
    string filename = "primes.txt";
    ifstream fin;
    fin.open(filename);
    if(fin.is_open()) {
        fin.seekg(-1,ios_base::end);                // go to one spot before the EOF

        bool keepLooping = true;
        while(keepLooping) {
            char ch;
            fin.get(ch);                            // Get current byte's data

            if((int)fin.tellg() <= 1) {             // If the data was at or before the 0th byte
                fin.seekg(0);                       // The first line is the last line
                keepLooping = false;                // So stop there
            }
            else if(ch == '\n') {                   // If the data was a newline
                keepLooping = false;                // Stop at the current position.
            }
            else {                                  // If the data was neither a newline nor at the 0 byte
                fin.seekg(-2,ios_base::cur);        // Move to the front of that data, then to the front of the data before it
            }
        }

        string lastLine;            
        getline(fin,lastLine);                      // Read the current line
        cout << "Result: " << lastLine << '\n';     // Display it
        *prime=std::stoll(lastLine,NULL,10);
        fin.close();
    }
}