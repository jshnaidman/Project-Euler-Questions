#include<stdio.h>
#include<stdlib.h>
#include<Time.h>
//program to parse 20x20 matrix for largest product of 4 in diagonally,horizontally, and vertically.
// 4 parses however diagonals are split into two for efficiency
clock_t start,end;
double time_Seconds;
int minutes;
double seconds;
int i,j,k; //indexes
int largestProduct;
char* inputNumbers =
"08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08\
49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00\
81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65\
52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91\
22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80\
24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50\
32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70\
67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21\
24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72\
21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95\
78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92\
16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57\
86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58\
19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40\
04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66\
88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69\
04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36\
20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16\
20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54\
01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48";
int numArray[20][20]; //store all these numbers
int main(){
  // parse through the giant string and initialize numArray
  for(j=0;j<20;j++){
    for (i=0; i<20; i++){
      do{
        if (*(inputNumbers+k) >47 && *(inputNumbers+k) < 58 && \
        *(inputNumbers+k+1) >47 && *(inputNumbers+k+1) < 58){
          numArray[j][i] = (int)((*(inputNumbers+k)-48)*10 + *(inputNumbers+k+1)-48);
          k+=2;
          break;
        }
        k++;
      } while(*(inputNumbers+k) != 0);
    }
  }
  //this is where we check the largest products of 4
  // if the product is larger than largest product, it becomes largest product
  for (i=0;i<20;i++){
    int horizontalProduct[5]; // last entry is for product of first 4 ints
    int verticalProduct[5];
    int diagonalProduct1t[5]; // slices like this: /, top part
    int diagonalProduct1b[5]; //bottom part
    int diagonalProduct2t[5]; // slices like this: \, top part
    int diagonalProduct2b[5]; // bottom part
    for(j=0;j<20;j++){
      if(j<17){ //make sure j is not greater than 17 so that  j+k does not exceed matrix
        //multiplies vertical and horizontal product
        horizontalProduct[4] = 1;
        verticalProduct[4] = 1;
        for(k=0;k<4;k++){
          horizontalProduct[k] = numArray[i][j+k];
          verticalProduct[k] = numArray[j+k][i];
          horizontalProduct[4] *= horizontalProduct[k];
          verticalProduct[4] *= verticalProduct[k];
        }
        //check horizontal and then vertical product
        if (horizontalProduct[4]>largestProduct){
          largestProduct = horizontalProduct[4];
        }
        if (verticalProduct[4]>largestProduct){
          largestProduct = verticalProduct[4];
        }
      }
      if(i>2){ // diagonals, 4 different slices
        if (j<=i){
          if(j>2){
            diagonalProduct1t[4] = 1;
            diagonalProduct2t[4] = 1;
            for(k=0;k<4;k++){
              diagonalProduct1t[k] = numArray[j+k][i-j-k];
              diagonalProduct2t[k] = numArray[j+k][19-i+j+k];
              diagonalProduct1t[4] *= diagonalProduct1t[k];
              diagonalProduct2t[4] *= diagonalProduct2t[k];
            }
            if(i<19){
              diagonalProduct1b[4] = 1;
              diagonalProduct2b[4] = 1;
              for(k=0;k<4;k++){
                diagonalProduct1b[k] = numArray[19-i+j+k][19-j-k];
                diagonalProduct2b[k] = numArray[19-i+j+k][j+k];
                diagonalProduct1b[4] *= diagonalProduct1b[k];
                diagonalProduct2b[4] *= diagonalProduct2b[k];
              }
            }
            if(diagonalProduct1t[4]>largestProduct){
              largestProduct = diagonalProduct1t[4];
            }
            if(diagonalProduct1b[4]>largestProduct && i<19){
              largestProduct = diagonalProduct1b[4];
            }
            if(diagonalProduct2t[4]>largestProduct){
              largestProduct = diagonalProduct2t[4];
            }
            if(diagonalProduct2b[4]>largestProduct && i<19){
              largestProduct = diagonalProduct2b[4];
            }
          }
        }
      }
    }
  }
  printf("Largest Product: %d\n", largestProduct);
  end = clock();
  time_Seconds = (double)(end - start)/CLOCKS_PER_SEC;
  minutes = (int)time_Seconds/60;
  seconds = time_Seconds - 60*minutes;
  printf("execution Time: %d minutes and %f miliseconds \n",minutes,seconds*1000);
  return 0;
}
