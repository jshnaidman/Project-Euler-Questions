#include <stdio.h>
#include <stdlib.h>

//use some assembly to get a random number
unsigned long long rdtsc()
{
  unsigned int lo, hi;
  __asm__ volatile("rdtsc"
                   : "=a"(lo), "=d"(hi));
  return ((unsigned long long)hi << 32) | lo;
}

void *myMemSet(void *arr, int c, size_t n)
{
char* str = (char*) arr;
  for (size_t i = 0; i < n; i++)
  {
    *(str + i) = c;
  }
  return str;
}

// Compared strings alphabetically
// returns  1 if first > second
// returns -1 if first < second
// returns  0 if first == second
int compare(char *first, char *second)
{
  while(*first && (*first == *second)){
    first++;second++;
  }
  return (*first < *second) ? -1 : (*second > *first);
}
//swaps values pointed at by p1 and p2, used for swapping strings
void swap(char **p1, char**p2)
{
  char *temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}


//split everything from low to high into two lists.
//half less than pivot, half greater than pivot
char **partition(char **low, char **high)
{
  //choose a random element for a pivot
  int randomNum = (size_t)rand();
  char **pivot = low + randomNum % (high - low);
  //put the pivot at the end of the list
  swap(pivot, high); //swap values
  char** temp = high; //swap pointers
  high = pivot;
  pivot = temp;
  //go from low to high, swapping if index curr < pivot
  char **curr = low; //wall is 'behind' low
  while (curr != pivot)
  {
    if (compare(*curr, *pivot) < 0)
    {
      swap(low++, curr); //once swapped, increment low because it's been swapped
    }
    curr++;
  } 
  // at the very end, everything to the left of pivot is less than it
  // and everything to the right of it should be greater than it
  // therefore, need to swap pivot with the index after low, since it comes after low
  swap(pivot, low);
  //return pointer to pivot
  return low;
}

void quicksort(char **low, char **high)
{
  //base case
  if (high <= low)
  {
    return;
  }

  char **pivot = partition(low, high); //paritition the array into two lists, less than and greater than pivot
  quicksort(low, pivot-1);           //sort the left list
  quicksort(pivot + 1, high);          //sort the right list
}

long getBasicScore(char *name)
{
  long score = 0;
  long charIndex = 0;
  while (*(name + charIndex) != '\0')
  {
    score += *(name + charIndex++) - 64;
  }
  return score;
}

int main()
{
  srand(rdtsc());
  char const *filePath = "q22.txt";
  FILE *textStream = fopen(filePath, "r");
  char **nameArray = (char **)malloc(6000 * sizeof(char *)); // not implemented as an array
  myMemSet(nameArray, 0, 6000 * sizeof(char *));
  *(nameArray) = malloc(40 * sizeof(char));
  myMemSet(*nameArray, 0, 40 * sizeof(char));
  char c;
  int charIndex = 0;
  int nameIndex = 0;
  int quoteCount = 0;
  while ((c = getc(textStream)) != EOF)
  {
    if (c > 64 && c < 91)
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
        myMemSet(*(nameArray + nameIndex), 0, 40 * sizeof(char));
      }
    }
  }

  quicksort(nameArray, (nameArray + nameIndex-1));

  long nameScoreTotal = 0;
  long score;
  for (int i = 0; i < nameIndex; i++)
  {
    score = getBasicScore(*(nameArray + i));
    nameScoreTotal += (i+1)*score;
  }

  printf("%ld\n", nameScoreTotal);
}
