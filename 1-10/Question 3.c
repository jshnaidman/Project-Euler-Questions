#include <stdio.h>
#include <math.h>

const unsigned long long Number = 600851475143;
unsigned long i;
unsigned long theRemainder;
unsigned long temp;
unsigned long largestNum;
unsigned long findLargestPrime(unsigned long long n){
// after sqrt n there's no point in checking.
  for(i=2;i<=(sqrt(n));i++){
    theRemainder = (n%i);
    if(theRemainder == 0){ //if remainder is 0, it's a prime since smallest factor after 1 is a prime
      temp = findLargestPrime(n/i); // n/i may have larger primes since it is not a prime. This will return its largest prime.
      if (temp>i){
        return temp;
      }
      else return i; //return the greater of the two primes
    }
    if (i==sqrt(n)){ // if the current n has no factors, it is a prime. This is the base case.
      return n;
    }
  }
  return 0;
}

int main(){
  largestNum = findLargestPrime(Number);
  printf("Largest Prime is: %lu\n", largestNum);
}
