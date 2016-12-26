#include<stdio.h>
#include<stdlib.h>
unsigned int maxPrimeCount; // find primes up till and including this num
unsigned int i;
unsigned int j;
unsigned int isPrime(unsigned long long n,unsigned long *arrOfPrimes, unsigned int *numberOfPrimes){
  for (i=1;i<(*numberOfPrimes);i++){ //starts at 1 to exclude 1, since every number is divisible by 1
    if ((n%(*(arrOfPrimes+i)))==0){  // If the number passed is divisible by a previous prime, it is not a prime
      return 0;
    }
  }
  //if reaches here, it is a prime
  return 1;
}

void findPrimes(unsigned int maxPrimeCount, unsigned long *arrayOfPrimes, unsigned int *primeCount){
  j = *(arrayOfPrimes + *primeCount -1);
  while(*primeCount <= maxPrimeCount){
    j++;
    if (isPrime(j,arrayOfPrimes,primeCount)){  //if it is a prime, add it to my array of primes and increase the # of primes variable by 1
      *(arrayOfPrimes + (*primeCount)) = j;
      (*primeCount)++;
      printf("%d\n", j);
    }
  }
}
int main(){
  printf("Enter the # of primes you wish to generate\n");
  scanf("%d",&maxPrimeCount);
  unsigned long *primesArr= malloc((maxPrimeCount)*sizeof(unsigned long));
  *primesArr = 1;
  *(primesArr+1) = 2;
  unsigned int numOfPrimes = 2;
  findPrimes(maxPrimeCount,primesArr,&numOfPrimes);
  for(i=0;i<numOfPrimes;i++){
    printf("%lu\n", primesArr[i]);
  }
  return 0;
}
