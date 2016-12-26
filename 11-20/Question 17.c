#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int i,j,k;
int letterCount = 11; // One Thousand is 11, skip in loop
int power;
int teen; //boolean to indicate if number is a teen
int number[3];
int main(){
  // these arrays store the lettercounts
  int zeroToNineteen[20] = {0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8};
  //zero space is because zero is not written out in numbers
  int twentytoNinety[10] = {0,0,6,6,5,5,5,7,6,6}; // eg twenty, thirty.. etc
  // extra zero and one case to keep position aligned, slightly inefficient but keeps code cleaner
  for (i=1;i<=999;i++){
    k=i;
    teen = 0; // if number is a teen, skips the third digit
    // for example, nineteen and not nineteen nine
    for (j=0;j<3;j++){ // go through the number and put it into an array
      number[2-j] = k%10; //this is so i can start at the highest digit
      k /= 10;
    }
    if (number[0]){
      letterCount += 10 + zeroToNineteen[number[0]]; // hundred and = 10 letters
      if (number[1] == 0 && number[2] == 0){
        letterCount -= 3; // if it's 500 or 200, it's just five or two hundred
        //this is slightly inefficient. Would be faster to check and then based on check,
        //add 7 or 10 rather than undo, but it's also more efficient of my time to
        //write this than to fix :P
      }

    }
    if(number[1]==1){
      letterCount += zeroToNineteen[10+number[2]]; //10-19 special case
      teen = 1; // mark as true to skip next digit
    }
    else {
      letterCount += twentytoNinety[number[1]]; // twenty nine for example, -
      // is just lettercount sum of twenty and nine
    }
    if (!teen){
      letterCount += zeroToNineteen[number[2]]; //if not 11-19, add lettercount of third digit
    }
  }
  printf("%d\n",letterCount);
}
