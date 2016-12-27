#include <stdio.h>
#include <stdlib.h>

// chose to do this low level without much help from libraries

//use some assembly to get a random number
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

void swap(void *p1, void *p2)
{
  void* temp = p1;
  p1 = p2;
  p2 = temp;
}

//not used
//swaps a random pointer to the end of the array based on the median of three randomly chosen indices
void pivot(char *array, int maxIndex)
{
  //indices 1,2,3 respectively
  int indexOne = rand() % (maxIndex + 1);
  int indexTwo = rand() % (maxIndex + 1);
  int indexThree = rand() % (maxIndex + 1);
  if (compare((array + indexOne), (array + indexTwo)) > 0) //case 1>2
  {
    if (compare((array + indexThree), (array + indexOne)) > 0)
    {
      swap((array + maxIndex), (array + indexOne)); // case  3>1>2
    }
    else if (compare((array + indexOne), (array + indexThree)) > 0)
    {
      swap((array + maxIndex), (array + indexTwo)); // case  1>2>3
    }
    else
    {
      swap((array + maxIndex), (array + indexThree)); //case 1>3>2
    }
  }

  else // case: 2>1
  {
    if (compare((array + indexOne), (array + indexThree)) > 0)
    {
      swap((array + maxIndex), (array + indexOne)); // case 2>1>3
    }
    else if (compare((array + maxIndex), (array + maxIndex / 2)) < 0)
    {
      swap((array + maxIndex), (array + indexTwo)); // case 3>2>1
    }
    else
    {
      swap((array + maxIndex), (array + indexThree)); //case 2>3>1
    }
  }
}

//split everything from low to high into two lists.
//half less than pivot, half greater than pivot
char** partition(char** low, char** high){

  if(low == high){
    return low;
  }

  //choose a random element for a pivot
  int randomNum = (size_t) rand();
  char** pivot = low + randomNum%(high-low);
  //swap their values and change pointers
  swap(pivot,high--); 
  //go from low to high, swapping if index i < pivot
  char** i = low;
  while( i != high){
    if(compare(*i,*pivot) <= 0){
      swap(low++,i); //once swapped, increment low to point to a new index
    }
    i++;
  }
  // at the very end, everything to the left of pivot is less than it
  // and everything to the right of it should be greater than it
  // therefore, need to swap low and pivot
  swap(pivot,low); 
  //return pointer to pivot
  return low;
}

void quicksort(char** low, char** high)
{
  //base case
  if(high<low){
    return;
  }

  char** pivot = partition(low,high); //paritition the array into two lists, left and right of the pivot
  quicksort(low,pivot-1); //sort the left list
  quicksort(pivot+1, high); //sort the right list

}

long getBasicScore(char* name){
    long score = 0;
    int i;
    while( *(name+i) != '\0'){
      score+= *(name+i++) -64;
    }
    return score;
  }

int main()
{
  srand(rdtsc());
  char const *filePath = "q22.txt";
  FILE *textStream = fopen(filePath, "r");
  char **nameArray =
      (char **)malloc(5163 * sizeof(char *)); // not implemented as an array
  *(nameArray) = malloc(16 * sizeof(char));
  char c;
  int charIndex, nameIndex;
  int quoteCount;
  while ((c = getc(textStream)) != EOF)
  {
    if (c > 64 && c <91)
    {
      *(*(nameArray + nameIndex) + charIndex++) = c;
    }
    if (c == 34)
    {
      quoteCount++;
      if (quoteCount % 2 == 0)
      {
        charIndex = 0;
        *(nameArray + ++nameIndex) = malloc(40 * sizeof(char));
      }
    }
  }

  quicksort(nameArray, (nameArray + nameIndex-1));

  long nameScoreTotal;
  for(int i =0; i< nameIndex;i++){
    nameScoreTotal += getBasicScore( *(nameArray + i) );
  }

  printf("\n%ld\n", nameScoreTotal);

}