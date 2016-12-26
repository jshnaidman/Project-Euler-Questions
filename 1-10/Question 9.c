#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int a,b,c;
double temp;
int found = 0;
int i;
int main(){
  a=1,b = 1;
  do{
    c=0;
    a++;
    for(i=0;i<999;i++){
      temp = sqrt(pow(a,2) + pow(b+i,2));
      if(temp == (long long) temp){
        c = (int) temp;
        if( a + b+i + c == 1000 && a<(b+i) && b<c){
          b = b+i;
          i=999;
          found = 1;
        }
      }
    }
    if (a==999){
      a = -1; b = a; c = b;
      break;
    }
  } while (found == 0);
  printf("a:%d, b:%d, c:%d\n",a,b,c);
  printf("product: %d\n",a*b*c);
}
