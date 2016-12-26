#include<stdio.h>
#include<stdlib.h>
#include<Time.h>
#include<math.h>

unsigned long link;
unsigned long start=1; //start = link at beginning
unsigned long chain;
unsigned long longestChain;
unsigned long answer;
int main(){
  while(start<1e6){
    link = start;
    chain = 0;
    while(link != 1){
      if(link%2 == 0){
        link /= 2;
      }
      else {
        link = link*3 + 1;
      }
      chain++;
    }
    if (chain>longestChain){
      longestChain = chain;
      answer = start;
      printf("answer: %lu\n",answer);
    }
    start++;
  }
  printf("%lu\n",answer);
}
