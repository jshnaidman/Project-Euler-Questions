#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
// 00 is January, 11 is December
unsigned int y,m,d;
unsigned int n=1;
char* days[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
unsigned int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
unsigned int leapYear;
unsigned int numSundays;
//if it is a leap year, 01 is 29 and not 28
//how many sundays on the first of the month between
// 1 Jan 1901 to 31 Dec 2000
// 1 Jan 1901 is a Tuesday
int isLeapYear(int year){
  //returns 0 if it is not a leap year, 1 otherwise
  if(year%4==0 && year%100 != 0){
    if (year%400==0){
      return 0;
    }
    else {
      return 1;
    }
  }
  else {
    return 0;
  }
}
int main(){
  for(y=1901;y<=2000;y++){
    leapYear = isLeapYear(y);
    if(leapYear){
      daysInMonth[1]++;
    }
    for(m=0;m<12;m++){
      if (n%7 == 6){
        numSundays++;
      }
      n+= daysInMonth[m];
    }
    if(leapYear){
      daysInMonth[1]--;
    }
  }
  printf("%d\n",numSundays);
}
