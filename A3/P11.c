/* Braelyn Rotman
  1006740
  March 5th, 2019
  A3 Q1.1 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/timeb.h>

char **permutes; // permutation array of input string
int size = 0; // allocated space for permutations
int length = 0; // # of permutations
int j = 0;

void permute(char *word, int start, int end) // this is a function to find all permutations of the input string
{
  int i = 0, k = 0;
  char temp; // for swaps
  if(start == end-1)
  {
  //  printf("\t%s\n", word); // all permutations
    length++;
    j++;
    if(size == j)
    {
      size = size + 100;
      permutes = realloc(permutes, size*sizeof(char *));
      for(k = size - 100 ; k < size ; k++)
      {
        permutes[k] = calloc(15, sizeof(char));
      }
    }
    strcpy(permutes[j], word);
  }
  else
  {
    for(i = start ; i < end ; i++)
    {
      temp = *(word+start);
      *(word+start) = *(word+i);
      *(word+i) = temp;
      permute(word, start+1, end);
      temp = *(word+start);
      *(word+start) = *(word+i);
      *(word+i) = temp;
    }
  }
}

void anagramBrute(char *words[], char *string)
{
  struct timeb start, end; // time structures
  int milli; // runtime in milliseconds
  int a = 0; // number of anagrams
  int i = 0, j = 0; // indexes

  printf("-----Question 1.1-----\n");
  printf("Anagram List:\n");
  //word = calloc(15, sizeof(char));
  ftime(&start); // set start time
  permutes = calloc(100, sizeof(char*));
  for (int i = 0; i < 100; i++)
  {
    permutes[i] = calloc(15, sizeof(char)); // initialize permutation array
  }
  size = 100;

  permute(string, 0, strlen(string));

  for(i = 0 ; i < 30000 ; i++) // for each string from file
  {
    for(j = 0 ; j < length ; j++) // for each permutation of input string
    {
      if(strcmp(words[i], permutes[j]) == 0 && strcmp(words[i], string) != 0) // match found and not original string
      {
        a++;
        printf("\t%s\n", words[i]); // print anagram
        break; // move on to next file string
      }

    }
  }

  ftime(&end); // set finish time
  milli = (int)(1000 * (end.time - start.time)) + (end.millitm - start.millitm);


  printf("Total Number of Anagrams: %d\n", a);
  printf("Algorithm Time: %d milliseconds\n", milli);

  for(i = 0 ; i < size ; i++)
  {
    free(permutes[i]);
  }
  free(permutes);

}
