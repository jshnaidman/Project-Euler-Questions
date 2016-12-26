#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int i,j,k;
int divisors[10000][500];
int sumOfDivisors[10000];
int amicableDivisors[3000];
int a;
int root;
int sum;
int complement;
int main(){
  for(i=2;i<10000;i++){
    if(sumOfDivisors[i]){
      continue;
    }
    root = (int) sqrt(i);
    k=1;
    sumOfDivisors[i] = 1;
    divisors[i][0] = 1;
    for(j=2;j<=root;j++){
      if(i%j == 0){
        divisors[i][k++] = i/j;
        sumOfDivisors[i] += i/j;
        if(i/j != j){
          divisors[i][k++] = j;
          sumOfDivisors[i] += j;
        }
      }
    }
    complement = sumOfDivisors[i];
    if (complement<10000 && !sumOfDivisors[complement]){
      divisors[complement][0] = 1;
      sumOfDivisors[complement] = 1;
      k=1;
      root = (int) sqrt(complement);
      for(j=2;j<=root;j++){
        if(complement%j == 0){
          divisors[complement][k++] = complement/j;
          sumOfDivisors[complement] += complement/j;
          if(complement/j != j){
            divisors[complement][k++] = j;
            sumOfDivisors[complement] += j;
          }
        }
      }
      if(i == sumOfDivisors[complement]){
        if (complement<10000){
          amicableDivisors[a++] = complement;
        }
        if(sumOfDivisors[complement]<10000){
          amicableDivisors[a++] = sumOfDivisors[complement];
        }
      }
    }
  }
  for(i=0;i<a;i++){
    sum+= amicableDivisors[i];
  }
  printf("%d\n", sum);
}
