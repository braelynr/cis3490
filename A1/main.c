#include <stdio.h>
#include <stdlib.h>

void findInvBrute(int *set, int n);
void findInvMerge(int *set, int n);

int main(void)
{
  FILE *fp;
  int *set;
  int i = 0;
  int size = 50;

  set = calloc(50, sizeof(int));

  fp = fopen("data_1.txt", "r");
  if(fp == NULL)
  {
    printf("Failed to open file \"data_1.txt\"\n");
    return -1;
  }
  while(fscanf(fp, "%d ", &set[i]) != EOF)
  {
    i++;
    if(size == i + 1)
    {
      set = realloc(set, sizeof(int)*(size + 50));
      size = size + 50;
    }
  }
  fclose(fp);
  /*for(int j = 0 ; j < i ; j++)
  {
    printf("%d, ", set[j]);
  }*/
  findInvBrute(set, i);
  findInvMerge(set, i);
  return 0;
}
