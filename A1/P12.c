/* Braelyn Rotman
  1006740
  February 8th, 2019
  A1 Q1.1 */

#include <stdio.h>
#include <sys/timeb.h>

void findInvMerge(int *set, int n)
{
  struct timeb start, end; // time structures
  int milli; // runtime in milliseconds
  int i = 0, j = 0;
  int invA = 0, invB = 0; // # inversions
  unsigned long int basicOp = 0; // # basic operations
  int *setA, *setB;

  setA = set; // point to beginning of array
  setB = setA + (n/2); // 2nd half of array

  ftime(&start); // set start time
  for (i = 0 ; i < n/2 ; i++)
  {
    for (j = 0 ; j < n ; j++) // must compare first half to both first half and second half
    {
      basicOp++;
      if (i < j && setA[i] > setA[j]) // basic operation
      {
        invA++;
      }
      if (j < n/2 && i < j && setB[i] > setB[j]) // basic operation
      {
        invB++;
      }
    }
  }
/*  for (i = 0 ; i < n/2 ; i++)
  {
    for (j = 0 ; j < n/2 ; j++) // only compare second half to second half
    {
      basicOp++;
      if (i < j && setB[i] > setB[j]) // basic operation
      {
        invB++;
      }
    }
  }*/
  ftime(&end); // set finish time
  milli = (int)(1000 * (end.time - start.time)) + (end.millitm - start.millitm);

  printf("-----Question 1.2-----\n");
  printf("Number of Elements in Set: %d\n", n);
  printf("Number of Basic Operations: %lu\n", basicOp);
  printf("Number of Inversions: %d\n", invA + invB);
  printf("Algorithm Time: %d milliseconds\n", milli);
  printf("Efficiency Class: O(nlog(n))\n\n");
}
