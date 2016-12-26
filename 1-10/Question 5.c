#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// find the smallest number that can is divisible by all #s in nums
//test the largest number first and if not divisible,
// try to test rarest condition first
//start at 2520 since it is the smallest number to include all nums under 10
int i = 2520;
int j=1;
int found = 0;
int main(){
  do{
    for(j=20;j>=2;j--){
      if(i%j != 0){
        break;
      }
      if (j==2){
        found=1;
      }
    }
    i++;
  } while(found == 0);
  printf("Smallest Number: %d\n",--i);
  for(j=1;j<21;j++){
    printf("division:%f by %d\n",(float)i/j,j);
  }
}
