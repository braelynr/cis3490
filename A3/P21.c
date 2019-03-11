/* Braelyn Rotman
  1006740
  March 9th, 2019
  A3 Q2.1 */

#include <stdio.h>
#include <string.h>
#include <sys/timeb.h>

int shifts = 0; // pattern shifts

int stringMatch(char *T, char *P) // algorithm from textbook pg 105
{
  int i = 0, j = 0; // indexes
  int n = 0, m = 0; // string lengths

  n = strlen(T);
  m = strlen(P);

  for (i = 0 ; i <= n - m ; i++) // shift by 1 each time
  {
    shifts++;
    j = 0;
    while(j < m && P[j] == T[i + j]) // compare pattern to text char by char
    {
      j++;
    }
    if(j == m) // match found
    {
      return 1 + stringMatch(T + i + m, P); // return match + recursive call with new decreased index
    }
  }
  return 0; // no match
}


void bruteMatch(char *string, char *word)
{
  struct timeb start, end; // time structures
  int milli; // runtime in milliseconds
  int matches = 0; // # of pattern matches

  ftime(&start); // set start time

  matches = stringMatch(string, word);

  ftime(&end); // set finish time

  milli = (int)(1000 * (end.time - start.time)) + (end.millitm - start.millitm);

  printf("-----Question 2.1-----\n");
  printf("Total Number of Matches: %d\n", matches);
  printf("Number of Shifts: %d\n", shifts);
  printf("Algorithm Time: %d milliseconds\n", milli);
}
