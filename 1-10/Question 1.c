#include <stdio.h>

int main(){
  int i = 0;
  int sum = 0;
  do{
    if (i%3 == 0 || i%5 ==0){
      sum+= i;
    }
    i++;
  } while(i<1000);
  printf("The sum is: %d\n", sum);
}
