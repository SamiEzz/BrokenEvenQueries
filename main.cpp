#include <iostream>
#include <stdlib.h>
#include "functions.hpp"

using namespace std;

int main() {
  primePotentialInt_t prime=0;
  getLastPrime(&prime);
  while(true){
    bool isPrime = 0;
    if(!isPrimeNumber(&isPrime,prime)){
      if(isPrime){
        if(setLastPrime(prime)){
          cout << "Unable to save prime number " << prime << endl;
        }
      }
    }
    prime++;
  }
}