/* Braelyn Rotman
  1006740
  February 8th, 2019
  A1 Q1.1 */

#include <stdio.h>
#include <sys/timeb.h>

void findInvBrute(int *set, int n)
{
  struct timeb start, end; // time structures
  int milli; // runtime in milliseconds
  int i = 0, j = 0;
  int inv = 0; // # inversions
  unsigned long int basicOp = 0; // # basic operations

  ftime(&start); // set start time
  for (i = 0 ; i < n ; i++)
  {
    for (j = i + 1 ; j < n ; j++) 
    {
      basicOp++;
      if (set[i] > set[j]) // basic operation
      {
        inv++;
      }
    }
  }
  ftime(&end); // set finish time
  milli = (int)(1000 * (end.time - start.time)) + (end.millitm - start.millitm);

  printf("-----Question 1.1-----\n");
  printf("Number of Elements in Set: %d\n", n);
  printf("Number of Basic Operations: %lu\n", basicOp);
  printf("Number of Inversions: %d\n", inv);
  printf("Algorithm Time: %d milliseconds\n", milli);
  printf("Efficiency Class: O(n^2)\n\n");

}
