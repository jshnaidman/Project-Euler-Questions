#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int i,j,k;
int c;
int matrix[15][15];
int main(){
  FILE* fpraw = fopen(locRaw, "r");
  FILE* fpOUT = fopen(locOutput,"w");
  while((c = getc(fpraw)) != EOF){
    if(c == 10){
      i++;
      j=0;
    }
    if(c>47 && c<58){
      if(k%2 == 0){
        matrix[i][j] += (c-48)*10;
        k++;
      }
      else{
        matrix[i][j] += c-48;
        k++;
      }
    }
    if (c==32){
      j++;
    }
  }
  char buffer[500];
  for(i=0;i<15;i++){
    int first = 1;
    sprintf(buffer,"{");
    int n = 1;
    for(j=0;j<15;j++){
      if(matrix[i][j]){
        if(first){
          n += sprintf(&buffer[n],"%d", matrix[i][j]);
          first = 0;
        }
        else{
          n += sprintf(&buffer[n],", %d", matrix[i][j]);
        }
        printf("%d ", matrix[i][j]);
      }
      else {
        n += sprintf(&buffer[n],"},");
        break;
      }
    }
    printf("\n");
    fputs(buffer,fpOUT);
  }
}
