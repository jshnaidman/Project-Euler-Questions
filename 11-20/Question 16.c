#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int i,j,k;
int number[500];
int sum;
int main(){
  number[0] = 2;
  for (i=1;i<1000;i++){
    number[0] = 2*number[0];
    for (j=1;j<500;j++){
      number[j] = 2*number[j] + number[j-1]/10;
      number[j-1] = number[j-1]%10;
    }
  }
  for(i=0;i<500;i++){
    sum += number[i];
    printf("i:%d, digit: %d\n", i,number[i]);
  }
  printf("%d\n", sum);
}
