#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//What is the sum of the digits of the number 2^1000?
//create array of 1000 digits
//create 2nd array for carrys. Store at n-1 index in loop
//multiply and manage carryAr outs to each index after multiplication
//create general multiplication method and use for loop to do 2^1000
//after storing it in array, add up all indexes.
// might want to create method to parse ints into arrays
int c;
size_t size;
int* multiplicandLength; // length
int multiplierLength;
int i,j,k; //standard
int two[1] = {2};
int temp;
void largeMultiplication (int* multiplicand, int* multiplier, int* multiplicandLength, int multiplierLength){
  //size of int is 4. max size after multiplication is 2x number of digits
  // of the maximum between multiplier and multiplicand.
  if (multiplierLength>*multiplicandLength){
    size = (size_t) (multiplierLength*8); // 2*4 = 8
  }
  else {size = (size_t) ((*multiplicandLength)*8 + 4);}
  int* answer = malloc(size);
  printf("size: %zu\n", size);
  memset(answer, 0, size);
  printf("size of multiplicand: %d, size of multiplier: %d\n", *multiplicandLength,multiplierLength);
  printf("size of answer: %d\n",(int) (sizeof(answer)/sizeof(*answer))); //printing for debug
  for(i=0;i<(*multiplicandLength);i++){
    for(j=0;j<multiplierLength;j++){ 
      temp = multiplier[j]*multiplicand[i];
      c=0;
      while (temp>0){
        answer[i+j+c] += temp%10;
        temp = temp/10;
        c++;
      }
    }
  }
  i=0; j=0;
  for(i=0;(size_t)i<(size/4);i++){
    c=1;
    temp = answer[i]/10;
    printf("temp: %d\n", temp);
    answer[i] = answer[i]%10;
    printf("i: %d, answer: %d\n", i, answer[i]);
    while(temp>0){
      printf("GOT HERE\n");
      answer[i+c] += temp%10;
      printf("i+c: %d, Answer at i+c: %d\n",i+c,answer[i+c]);
      temp = temp/10;
      c++;
    }
  }
  *multiplicandLength = i-1; //changes productLength to new length
  int* temp = multiplicand;
  free(temp);
  multiplicand = answer;
  printf("GOT HERE!!\n");
}
int main(){
  int* product = malloc(2*sizeof(int));
  memset(product, 0, 2*sizeof(int));
  product[0] = 9;
  int productLength = 1;
  printf("size of product: %lu\n", (sizeof(product)/sizeof(*product)));
  largeMultiplication(product,two,&productLength,1);
  printf("test!!");
  while(product[k]){
    k++;
  }
  char* str;
  char strTemp[1];
  for(k=k;k>=0;k--){
    strTemp[0] = (char)(product[k]+48);
    str = strcat(str,strTemp);
  }
}
