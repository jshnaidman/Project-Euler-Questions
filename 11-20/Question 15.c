#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
unsigned long paths;
int started;
void countPaths(int i, int j){ //comitted to recursion, turned out slow
  if (i<20){
    countPaths(i+1,j);
  }
  if(j<20){
    countPaths(i,j+1);
  }
  if(i == 20 && j == 20){
    paths++;
  }
}
int main(){
  countPaths(0,0);
  printf("paths:%lu\n", paths);
}
