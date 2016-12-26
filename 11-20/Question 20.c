#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
unsigned int i,j,k;
unsigned int sum;
unsigned int n[250];
int main(){
  n[0] = 1;
  for(i=1;i<=100;i++){
    n[0]*=i;
    n[1] = n[1]*i + n[0]/10;
    for(j=2;j<250;j++){
      n[j] = n[j]*i + n[j-1]%100/10 + n[j-2]/100;
      n[j-2] = n[j-2]%10;
    }
  }
  for(i=0;i<250;i++){
    sum += n[i];
    printf("%d\n", n[i]);
  }
  printf("sum: %u\n",sum);
}
