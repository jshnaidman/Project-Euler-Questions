#include <stdio.h>
#include <stdlib.h>

// chose to do this low level without much help from libraries

unsigned long long rdtsc()
{
  unsigned int lo, hi;
  __asm__ volatile("rdtsc"
                   : "=a"(lo), "=d"(hi));
  return ((unsigned long long)hi << 32) | lo;
}

// Compared strings alphabetically
// returns  1 if first > second
// returns -1 if first < second
// returns  0 if first == second
int compare(char *first, char *second)
{
  int maxIndex;
  if (sizeof(first) > sizeof(second))
  {
    maxIndex = sizeof(first);
  }
  else
  {
    maxIndex = sizeof(second);
  }

  for (int i = 0; i < maxIndex; i++)
  {
    if (*(first + i) < *(second + i))
    {
      return 1;
    }
    else if (*(first + i) > *(second + i))
    {
      return -1;
    }
  }
  return 0;
}

void swap(char *p1, char *p2)
{
  char temp = *p1;
  *p1 = *p2;
  p2 = temp;
}

//swaps a random pointer to the end of the array based on the median of three randomly chosen indices
void pivot(char *array, int maxIndex)
{
  //indices 1,2,3 respectively
  indexOne = rand() % (maxIndex + 1);
  indexTwo = rand() % (maxIndex + 1);
  indexThree = rand()(% maxIndex + 1);
  if (compare((array + indexOne), (array + indexTwo)) > 0) //case 1>2
  {
    if (compare((array + indexThree), (array + indexOne) > 0)
    {
      swap((array + maxIndex), (array + indexOne)); // case  3>1>2
    }
    else if (compare((array + indexOne), (array + indexThree)) > 0)
    {
      swap((array + maxIndex), (array + indexTwo)); // case  1>2>3
    }
    else{
      swap((array + maxIndex), (array + indexThree)); //case 1>3>2
    }
  }

  else  // case: 2>1
  {
    if( compare( (array+indexOne) , (array + indexThree) > 0){
      swap((array + maxIndex), (array + indexOne)); // case 2>1>3
		}
		else if( compare( (array + maxIndex) , (array + maxIndex/2) <0){
      swap((array + maxIndex), (array + indexTwo)); // case 3>2>1
		}
    else{
      swap((array + maxIndex), (array + indexThree)); //case 2>3>1
    }
  }
}

void quicksort(char *low, char *high)
{
}

int main()
{
  srand(rdtsc());
  char const *filePath = "/Users/jshnaidman/Documents/OneDrive - McGill "
                         "University/Programming/Project Euler/21-30/Question "
                         "22/q22.txt";
  FILE *textStream = fopen(filePath, "r");
  char **nameArray =
      (char **)malloc(5163 * sizeof(char *)); // not implemented as an array
  *(nameArray) = malloc(16 * sizeof(char));
  char c;
  int charIndex, nameIndex;
  int quoteCount;
  while ((c = getc(textStream)) != EOF)
  {
    if (c != ',')
    {
      *(*(nameArray + nameIndex) + charIndex++) = c;
    }
    if (c == 34)
    {
      quoteCount++;
      if (quoteCount % 2 == 0)
      {
        printf("%d\n", nameIndex++);
        charIndex = 0;
        *(nameArray + nameIndex) = malloc(40 * sizeof(char));
      }
    }
  }

}

quicksort(*nameArray, *(nameArray + nameIndex));
}
