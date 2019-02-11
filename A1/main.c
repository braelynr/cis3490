/* Braelyn Rotman
  1006740
  February 8th, 2019
  A2 main.c */

#include <stdio.h>
#include <stdlib.h>

typedef struct point{
  float x;
  float y;
} Point;

void findInvBrute(int *set, int n);
void findInvMerge(int *set, int n);
void convexBrute(Point *plane, int n);
void quickhull(Point *plane, int n);

int main(void)
{
  FILE *fp;
  int *set;
  Point *plane;
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
  fp = NULL;

  findInvBrute(set, i);
  findInvMerge(set, i);
  free(set);
  set = NULL;

  i = 0;
  size = 50;
  plane = calloc(50, sizeof(Point));

  fp = fopen("data.txt", "r");
  if(fp == NULL)
  {
    printf("Failed to open file \"data_2.txt\"\n");
    return -1;
  }
  while(fscanf(fp, "%f %f", &plane[i].x, &plane[i].y) != EOF)
  {
    i++;
    if(size == i + 1)
    {
      plane = realloc(plane, sizeof(Point)*(size + 50));
      size = size + 50;
    }
  }
  fclose(fp);

  convexBrute(plane, i);
  quickhull(plane, i);
  free(plane);

  return 0;
}
