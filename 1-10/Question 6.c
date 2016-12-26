#include <stdio.h>
#include <math.h>
#include <stdlib.h>
unsigned long long sumOfSquare;
unsigned long long squareOfSum;
int i;
unsigned long long j;
int main(){
  for (i=1;i<=100;i++){
    squareOfSum += i;
    sumOfSquare += i*i;
  }
  squareOfSum= squareOfSum*squareOfSum;
  j = squareOfSum - sumOfSquare;
  printf("%llu\n",j);
}
