#include<stdio.h>
#include<stdlib.h>
#include<Time.h>
clock_t start,end;  //this is a lazy answer based on previously written code
double time_Seconds;
int minutes;
double seconds;
unsigned int i;
unsigned int j;
unsigned long maxNum;
unsigned long long sum = 0;
unsigned int isPrime(unsigned long long n,unsigned long *arrOfPrimes, unsigned int *numberOfPrimes){
  for (i=1;i<(*numberOfPrimes);i++){ //starts at 1 to exclude 1, since every number is divisible by 1
    if ((n%(*(arrOfPrimes+i)))==0){  // If the number passed is divisible by a previous prime, it is not a prime
      return 0;
    }
  }
  //if reaches here, it is a prime
  return 1;
}

void findPrimes(unsigned long maxNum, unsigned long *arrayOfPrimes, unsigned int *primeCount){
  j = *(arrayOfPrimes + *primeCount -1);
  do{
    j++;
    if (isPrime(j,arrayOfPrimes,primeCount)){  //if it is a prime, add it to my array of primes and increase the # of primes variable by 1
      *(arrayOfPrimes + (*primeCount)) = j;
      (*primeCount)++;
      printf("%d\n", j);
    }
  } while(j<maxNum-1);
}
int main(){
  start = clock();
  printf("Enter the upper limit for the generation of prime numbers\n");
  scanf("%lu",&maxNum);
  unsigned long *primesArr= malloc((1e6)*sizeof(unsigned long));
  *primesArr = 1;
  *(primesArr+1) = 2;
  unsigned int numOfPrimes = 2;
  findPrimes(maxNum,primesArr,&numOfPrimes);
  for(i=0;i<numOfPrimes;i++){
    sum += *(i + primesArr);
  }
  printf("Sum: %llu\n", sum); // Project Euler doesn't count 1 as prime so - 1 from answer
  end = clock();
  time_Seconds = (double)(end - start)/CLOCKS_PER_SEC;
  minutes = (int)time_Seconds/60;
  seconds = time_Seconds - 60*minutes;
  printf("execution Time: %d minutes and %f seconds \n",minutes,seconds);
  return 0;
}
