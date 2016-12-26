#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int result;
int temp1,temp2,temp3;
int l = 15;
int Matrix[15][15] = {
  {75},
  {95, 64},
  {17, 47, 82},
  {18, 35, 87, 10},
  {20, 4, 82, 47, 65},
  {19, 1, 23, 75, 3, 34},
  {88, 2, 77, 73, 7, 63, 67},
  {99, 65, 4, 28, 6, 16, 70, 92},
  {41, 41, 26, 56, 83, 40, 80, 70, 33},
  {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
  {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
  {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
  {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
  {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
  {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}
};
int largestSum[15][15];
// simple recursive solution, will try Problem 67 at some other point
int findLargestSum(unsigned int i,unsigned int j){
  if((i+1)<l && j<l && j<=i){
    temp2 = Matrix[i][j] + findLargestSum(i+1,j);
    if (temp2>largestSum[i][j]){
      largestSum[i][j] = temp2;
    }
  }
  if((i+1)<l && (j+1)<l && j<=i){
    temp3 = Matrix[i][j] + findLargestSum(i+1,j+1);
    if (temp3>largestSum[i][j]){
      largestSum[i][j] = temp3;
    }
  }
  if(!largestSum[i][j]){
    largestSum[i][j] = Matrix[i][j];
  }
  return largestSum[i][j];
}
int main(){
  result = findLargestSum(0,0);
  printf("%d\n", result);
}
