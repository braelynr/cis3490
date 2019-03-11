/* Braelyn Rotman
  1006740
  March 10th, 2019
  A3 Q2.3 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/timeb.h>

// this program was based off of the textbook as well as various explanation videos on youtube

int Nshift = 0;
int matches = 0;

void goodTable(char *P, int good[]) // fill shift table for good suffixes
{
  int i = 0, j = 0, m = 0, x = 0 , y = 0; // indexes and pattern length
  int suffix[128]; // table with all characters

  m = strlen(P);

  // create suffix table
  suffix[m - 1] = m;
  y = m - 1;
  for (i = m - 2; i >= 0; i--)
  {
    if (i > y && suffix[i+m-x-1] < i - y)
    {
      suffix[i] = suffix[i+m-x-1];
    }
    else
    {
      if (i < y)
      {
        y = i;
      }
      x = i;
      while (y >= 0)
      {
        if(P[y] != P[y+m-x-1])
        {
          break;
        }
        y--;
      }
      suffix[i] = x - y;
    }
  }

  for (i = m - 1; i >= 0; i--) // fill good table shifts
  {
     if (suffix[i] == i + 1)
     {
        for (j = 0 ; j < m-i-1; j++)
        {
           if (good[j] == m)
           {
             good[j] = m-i-1;
           }
        }
      }
  }
  for (i = 0 ; i < m - 1 ; i++)
  {
     good[m - suffix[i] - 1] = m - i - 1;
  }

}

void badTable(char *P, int bad[]) // fill shift table for bad characters
{
  int i = 0, m = 0;
  m = strlen(P); // string length of pattern

  for (i = 0 ; i < m - 1 ; i++) // fill bad table shifts
  {
      bad[(int)P[i]] = m - i - 1;
  }

}

int max(int a, int b) // a function to find the max of 2 integers
{
  if(a > b)
  {
    return a;
  }
  return b;
}

void search(char *T, char *P)
{
  int i = 0, j = 0, n = 0, m = 0;
  int good[128], bad[128]; // shift tables
  n = strlen(T);
  m = strlen(P);

  for (i = 0 ; i < 128 ; i++) // initialize tables to pattern length
  {
      bad[i] = m;
      good[i] = m;
  }
  goodTable(P, good); // fill in good shift table
  badTable(P, bad); // fill in bad shift table

  while (j <= n - m) // start searching
  {
    i = m - 1;
    while(i >= 0) // compare pattern to text char by char until chars dont match or the end of the string is reached
    {
      if(T[i + j] != P[i]) // chars dont match
      {
        break;
      }
      i--;
    }

    if (i < 0) // match was found
    {
      matches++; // used a global variable instead of recursion
      j = j + m; // skip over found word (shift by pattern length)
    }
    else // no match found, use maximum shift value
    {
      j = j + max(good[i], bad[(int)T[i + j]] - m+i+1);
    }
    Nshift++;
  }
}


void boyermoore(char *T, char *P)
{
  struct timeb start, end; // time structures
  int milli; // runtime in milliseconds

  ftime(&start); // set start time
  search(T, P);
  ftime(&end); // set finish time

  milli = (int)(1000 * (end.time - start.time)) + (end.millitm - start.millitm);

  printf("-----Question 2.3-----\n");
  printf("Total Number of Matches: %d\n", matches);
  printf("Number of Shifts: %d\n", Nshift);
  printf("Algorithm Time: %d milliseconds\n", milli);
}
