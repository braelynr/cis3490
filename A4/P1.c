/* Braelyn Rotman
  1006740
  March 21, 2019
  Assignment 4 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n = 0;

// function that finds an optimal binary search tree using algorithm from textbook
void optimalBST(float P[], int R[n+2][n+1], float C[n+2][n+1])
{
  int j = 0;
  float minval = 0;
  int kmin = 0;
  float sum = 0;

  for(int i = 1 ; i <= n ; i++)
  {
    C[i][i-1] = 0;
    C[i][i] = P[i];
    R[i][i] = i;
  }
  C[n+1][n] = 0;
  for(int d = 1; d < n ; d++)
  {
    for(int i = 1; i <= n-d ; i++)
    {
      j = i+d;
      minval = 10000;
      for(int k = i ; k <= j ; k++)
      {
        if(C[i][k-1]+C[k+1][j] < minval)
        {
          minval = C[i][k-1]+C[k+1][j];
          kmin = k;
        }
      }
      R[i][j] = kmin;
      sum = P[i];
      for(int s = i+1 ; s <= j ; s++)
      {
        sum = sum+P[s];
      }
      C[i][j] = minval + sum;
    }
  }
  //  printf("C[1,n] = %f\n", C[1][n]);
}

void searchTree(char *unique[], float P[], int k)
{
  int x = 0, y = 0;
  int R[k+2][k+1];
  float C[k+2][k+1];
  int node = 0;
  char *key = calloc(50, sizeof(char));

  n = k;

  optimalBST(P, R, C);

  printf("\n(Q1) Enter a key: ");
  scanf("%s", key);

  x = k;
  y = 1;
  while(1) // move through root table
  {
    if(R[y][x] == 0)
    {
      printf("Not found.\n");
      break;
    }
    node = R[y][x];

    if(strcmp(key, unique[node]) < 0)
    {
      printf("Compared with %s (%.2f), go left subtree.\n", unique[node], C[y][x]);

      x = R[y][x]-1; // left subtree
    }
    else if(strcmp(key, unique[node]) > 0)
    {
      printf("Compared with %s (%.2f), go right subtree.\n", unique[node], C[y][x]);

      y = R[y][x]+1; // right subtree
    }
    else
    {
      printf("Compared with %s (%.2f), found.\n", unique[node], C[y][x]);
      break;
    }
  }

  free(key);
}
