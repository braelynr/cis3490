/* Braelyn Rotman
  1006740
  March 9th, 2019
  A3 Q2.2 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/timeb.h>

int shift = 0; // shift counter

int *shiftTable(char *pattern) // algorithm from textbook page 261
{
  int i = 0, j = 0, m = 0; // indexes
  int *table = calloc(128, sizeof(int));
  m = strlen(pattern);

  for(i = 0 ; i < 128 ; i++) // set all table values to length of pattern
  {
    table[i] = m;
  }
  for(j = 0 ; j <= m - 2 ; j++) // set shift values
  {
    table[(int)pattern[j]] = m - 1 - j;
  }

  return table;
}

int horspoolMatching(char *P, char *T)
{
  int i = 0, k = 0, m = 0, n = 0; // indexes and string lengths
  int *table = NULL;

  n = strlen(T); // length of text
  m = strlen(P); // length of pattern
  table = shiftTable(P);

  i = m - 1;
  while(i <= n - 1)
  {
    k = 0;
    while(k <= m - 1 && P[m-1-k] == T[i-k]) // match string against text char by char
    {
      k = k + 1;
    }
    if(k == m) // match found
    {
      free(table);
      table = NULL;
      return 1 + horspoolMatching(P, T+(i-m+1) + m); // 1 match + recursive call with new decreased index
    }
    else // no match
    {
      shift++;
      if(T[i] >= 0 && T[i] < 128) // validate character before indexing
      {
        i = i + table[(int)T[i]];
      }
      else // for invalid char just shift by the string length
      {
        i = i + m;
      }
    }
  }
  free(table);
  table = NULL;
  return 0; // if no matches are found
}

void horspool(char *string, char *word)
{
  struct timeb start, end; // time structures
  int milli; // runtime in milliseconds
  int matches = 0; // # of pattern matches

  ftime(&start); // set start time
  matches = horspoolMatching(word, string);
  ftime(&end); // set finish time

  milli = (int)(1000 * (end.time - start.time)) + (end.millitm - start.millitm);

  printf("-----Question 2.2-----\n");
  printf("Total Number of Matches: %d\n", matches);
  printf("Number of Shifts: %d\n", shift);
  printf("Algorithm Time: %d milliseconds\n", milli);
}
