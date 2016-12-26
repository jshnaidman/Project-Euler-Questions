#include<stdio.h>
#include<stdlib.h>
#include<Time.h>
#include<math.h>

long nums[100][50];
int i,j;
long sum;
char c;
char* text = "/Users/jshnaidman/OneDrive/Programming/Project Euler/11-20/Q13.txt";
int main(){
  FILE* fp = fopen(text,"r");
  while((c = getc(fp)) != EOF){
    if (c>47 && c<58){
      nums[i][j] = (int) c-48;
      j++;
      if(j>49){
        i++;
        j=0;
      }
    }
  }
  for(i=0;i<100;i++){
   long num = 0;
    for(j=0;j<13;j++){
      num += (long)(nums[i][j]*pow(10,12-j));
      printf("nums: %f\n", (nums[i][12-j])*pow(10,12-j));
    }
    sum += num;
  }
  while(sum>1e10){
    sum /= 10;
  }
  printf("sum: %ld\n",sum);
}
