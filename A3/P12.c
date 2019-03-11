/* Braelyn Rotman
  1006740
  March 9th, 2019
  A3 Q1.2 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/timeb.h>

int compare(const void *a, const void *b) // for qsort
{
  return *(char *)a - *(char *)b;
}

void anagramPreSort(char *words[], char *string)
{
  struct timeb start, end; // time structures
  char *original[30000];
  char *word; // original string
  int milliPre; // sorting in milliseconds
  int milli; // algoithm run time in milliseconds
  int i = 0, j = 0;
  bool anagram = false;
  int a = 0;

  word = calloc(strlen(string), sizeof(char) + 1);
  strcpy(word, string);

  for(i = 0 ; i < 30000 ; i++) // make copy of original
  {
    original[i] = calloc(strlen(words[i]), sizeof(char) + 1);
    strcpy(original[i], words[i]);
  }

  // Pre-Sorting
  ftime(&start); // set start time
  qsort(string, strlen(string), sizeof(string[0]), compare);

  for(i = 0 ; i < 30000 ; i++) // sort each string from file
  {
    qsort(words[i], strlen(words[i]), sizeof(words[i][0]), compare);
  }
  ftime(&end); // set finish time
  milliPre = (int)(1000 * (end.time - start.time)) + (end.millitm - start.millitm);

  printf("-----Question 1.2-----\n");
  printf("Anagram List:\n");
  ftime(&start); // set start time
  for(i = 0 ; i < 30000 ; i++) // for each string in file
  {
    if(strlen(string) == strlen(words[i])) // compare to input string
    {
      a++; // assume its an anagram
      anagram = true;
      for(j = 0 ; j < strlen(string) ; j++) // check each character in string
      {
        if(words[i][j] != string[j]) // not an anagram
        {
          a--;
          anagram = false;
          break;
        }
      }
      if(anagram == true && strcmp(word, original[i]) != 0) // is an anagram
      {
        printf("\t%s\n", original[i]); // print original file string
      }
    }
  }

  ftime(&end); // set finish time
  milli = (int)(1000 * (end.time - start.time)) + (end.millitm - start.millitm);


  printf("Total Number of Anagrams: %d\n", a);
  printf("Pre-Sorting Time: %d milliseconds\n", milliPre);
  printf("Algorithm Time: %d milliseconds\n", milli);

  free(word);
  for(i = 0 ; i < 30000 ; i++) // make copy of original
  {
    free(original[i]);
  }

}
