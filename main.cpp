#include <iostream>
#include <stdlib.h>

#include "InputOutput.hpp"

using namespace std;

int isPrimeNumber(bool *isPrime, primePotentialInt_t number);

// Static def
static bool DEBUG = 1;
static string primeFolder = "./PRIMES/";

static primePotentialInt_t hachageModulo = 100000;

/**
 * @brief main function
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[]) {
  primePotentialInt_t loopIdx = 0;
  primePotentialInt_t prime = 0;
  getLastPrime(&prime);
  while (true) {
    bool isPrime = 0;
    if (!isPrimeNumber(&isPrime, prime)) {
      if (isPrime == 1) {
        if (setLastPrime(prime)) {
          cout << "Unable to save prime number " << prime << endl;
        }
      } else {
        if (DEBUG && loopIdx % hachageModulo == 0) {
          cout << "[DEBUG] Number " << prime << " is not prime \n";
        }
      }
    }
    prime++;
  }
}

int isPrimeNumber(bool *isPrime, primePotentialInt_t number) {
  primePotentialInt_t i = 0;
  primePotentialInt_t n = number;

  // 0 and 1 are not prime numbers
  if (n == 0 || n == 1) {
    *isPrime = false;
  } else {
    for (i = 2; i <= n / 2; ++i) {
      if (n % i == 0) {
        *isPrime = false;
        break;
      }
    }
  }
  if (isPrime) {
    cout << n << " is a prime number\n";
    setLastPrime(n);
  }
  return 0;
}