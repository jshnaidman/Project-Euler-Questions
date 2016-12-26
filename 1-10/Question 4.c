#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int i;
int j[] = {0,0,0};
int k;
int temp=0;
int factor1 =1;
int factor2=1;
int largestPalindrome = 1;
int* createPalindromes(){
  int* Palindromes = malloc(1000*sizeof(int));
  for(i=0;i<1000;i++){
    temp=0;
    for (k=0;k<3;k++){
      temp += j[k]%10*pow(10,k);
      temp += j[k]%10*pow(10,5-k);
    }
    *(Palindromes+i) = temp;
    j[2]++;
    if (j[2]%10 ==0){j[1]++;}
    if (j[2]%100 ==0){j[0]++;}
  }
  return Palindromes;
}
int main(){
  int* Palindromes = createPalindromes();
  for(i=0;i<1000;i++){
    printf("Current Palindrome: %d\n", *(Palindromes+i));
    for (k=2;k<999;k++){
      if (*(Palindromes+i)%k == 0 && *(Palindromes+i)/k <1000 && *(Palindromes+i)>largestPalindrome){
        factor1 = k;
        largestPalindrome = *(Palindromes+i);
        break;
      }
    }
  }
  if(factor1){
  factor2 = largestPalindrome/factor1;
  }
  printf("Largest Palindrome: %d, with factors %d and %d\n", largestPalindrome, factor1, factor2);
}
