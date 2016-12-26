#include<stdio.h>
#include<stdlib.h>
#include<Time.h>
#include<math.h>
int i,j,k;
int divisors[500]; //if divisors[499] then it's finished
long sum;
int sqrts;
int main(){
  do{
    i++;
    sum += i;
    sqrts = sqrt(sum);
    do{
      j++;
      if(sum%j ==0){
        divisors[k] = sum/j;
        if(divisors[k] != j){
          divisors[k+1] = j;
          k+=2;
        }
        else k++;
      }
    } while(j<=sqrts);
    j=0;
    k=0;
  } while(!divisors[499]);
  printf("Triangle Number is: %ld\n", sum);
}
