#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void anagramBrute(char *words[], char *string);
void anagramPreSort(char *words[], char *string);
void bruteMatch(char *string, char *word);
void horspool(char *string, char *word);
void boyermoore(char *string, char *word);

int main(void) // use arguments to choose program i think and enter string
{
  FILE *fp;
  int *set; // set of ints
  char *words[30000]; // set of strings
  char *text = NULL; // string for data_5.txt
  int i = 0; // number of strings
  int size = 50; // allocated set size
  char *string = calloc(50, sizeof(char));

//  strcpy(string, "1234567890");
  printf("Q1: Enter a string: ");
  fgets(string, 50, stdin);
  string[strlen(string) - 1] = '\0';

  set = calloc(50, sizeof(int));

  // read data_4.txt into an int array
  fp = fopen("data_4.txt", "r");
  if(fp == NULL)
  {
    printf("Failed to open file \"data_4.txt\"\n");
    return -1;
  }
  while(fscanf(fp, "%d ", &set[i]) != EOF)
  {
    words[i] = calloc(15, sizeof(char));
    sprintf(words[i], "%d", (int)set[i]);
    i++;
    if(size == i + 1)
    {
      set = realloc(set, sizeof(int)*(size + 50));
      *words = realloc(*words, sizeof(char)*15*(size + 50));
      size = size + 50;
    }
  }
  fclose(fp);
  free(set);
  set = NULL;
  fp = NULL;

  anagramBrute(words, string);
  anagramPreSort(words, string);

  for(i = 0 ; i < 30000 ; i++)
  {
    free(words[i]);
  }
  free(string);
  string = NULL;

  // read data_5.txt into a string
  fp = fopen("data_5.txt", "r");
  if(fp == NULL)
  {
    printf("Failed to open file \"data_5.txt\"\n");
    return -1;
  }
  i = 0;
  size = 500;
  text = calloc(500, sizeof(char));
  while((text[i] = fgetc(fp)) != EOF)
  {
  //  printf("%c", text[i]);
    if(text[i] > 126 || text[i] < 0)
    {
      text[i] = '\0';
      i--;
    }
    i++;
    if(i == size)
    {
      size = size + 500;
      text = realloc(text, sizeof(char)*size);
      for(int j = size - 500 ; j < size ; j++) // initialize
      {
        text[j] = '\0';
      }
    }
  }
  fclose(fp);

  string = calloc(50, sizeof(char));
  //strcpy(string, "Winter Semester");
  printf("Q2: Enter a pattern: ");
  //scanf("%s", string);
  fgets(string, 50, stdin);
  string[strlen(string) - 1] = '\0';

  bruteMatch(text, string);
  horspool(text, string);
  boyermoore(text, string);

  free(text);
  free(string);

  return 0;
}
