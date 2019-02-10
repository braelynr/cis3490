/* Braelyn Rotman
  1006740
  February 9th, 2019
  A1 Q1.2 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>

int *temp;
int basicOp = 0;


int merge(int set[], int l, int m, int r)
{
	int inv = 0;
  int x = l; // l index
	int y = m; // r index
	int z = x; // merged index

  basicOp++;
	while (y <= r && x <= m - 1 )
  {
		if (set[x] > set[y])
    {
      temp[z++] = set[y++];
      inv = inv + m - x;
		}
		else
    {
      temp[z++] = set[x++];
		}
	}

	while (x <= m - 1) // merge left
  {
		temp[z++] = set[x++];
  }

	while (y <= r) // merge right
  {
		temp[z++] = set[y++];
  }

	for (x = l ; x <= r ; x++)
  {
		set[x] = temp[x]; // copy to original
  }

	return inv;
}

int sort(int set[], int l, int r)
{
	int m = 0; // midpoint
  int inv = 0;

	if (r > l)
  {
		m = (r + l) / 2;

		inv = sort(set, l, m);
		inv = inv + sort(set, m + 1, r);

		inv = inv + merge(set, l, m + 1, r);
	}
	return inv;
}

void findInvMerge(int *set, int n)
{
  struct timeb start, end; // time structures
  int inv = 0;
  int milli; // runtime in milliseconds
  temp = (int*)malloc(sizeof(int) * n);

  ftime(&start); // set start time
  inv = sort(set, 0, n-1);
  ftime(&end); // set finish time

	free(temp);

  milli = (int)(1000 * (end.time - start.time)) + (end.millitm - start.millitm);

  printf("-----Question 1.2-----\n");
  printf("Number of Elements in Set: %d\n", n);
  printf("Number of Basic Operations: %d\n", basicOp);
  printf("Number of Inversions: %d\n", inv);
  printf("Algorithm Time: %d milliseconds\n", milli);
  printf("Efficiency Class: O(nlog(n))\n\n");
}
