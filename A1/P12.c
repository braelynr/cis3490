/* Braelyn Rotman
  1006740
  February 9th, 2019
  A2 Q1.2 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>

//void merge(int *B, int *C, int *A, int p, int q);

int *temp;
int bOp = 0;
int inv = 0;


void merge(int set[], int l, int m, int r)
{
  int x = l; // l index
	int y = m; // r index
	int z = x; // merged index

  bOp++;
	while (y <= r && x <= m - 1 )
  {
		if (set[x] > set[y])
    {
			temp[z] = set[y];
			z++;
			y++;

      inv = inv + m - x;
		}
		else
    {
			temp[z] = set[x];
			z++;
			x++;
		}
	}

	while (x <= m - 1) // merge left
  {
		temp[z] = set[x];
		z++;
		x++;
  }

	while (y <= r) // merge right
  {
		temp[z] = set[y];
		z++;
		y++;
  }

	for (x = l ; x <= r ; x++)
  {
		set[x] = temp[x]; // copy to original
  }
}

void sort(int set[], int l, int r)
{
	int m = 0; // middle of set

	if (r > l)
  {
		m = (r + l) / 2;

		sort(set, l, m);
		sort(set, m + 1, r);

		merge(set, l, m + 1, r);
	}
}
/* OLD MODIFIED PSEUDO CODE
int sort(int *set, int n)
{
	int *B;
	int *C;
	int p = 0, q = 0;
	if (n > 1)
	{
		B = set;
		C = set + n/2;
		sort(B, n/2 - 1);
		sort(C, n/2);
		p = n/2;
		q = n/2;
		merge(B, C, set, p, q);
	}
	return inv;
}

void merge(int *B, int *C, int *A, int p, int q)
{
	int i = 0, j = 0, k = 0;
	while (i < p && j < q)
	{
		if (B[i] <= C[j])
		{
			// A[k] <- B[i]
			temp[k] = B[i];
			i++;
			inv = inv  + j;
		}
		else
		{
			//A[k] <- C[j]
			temp[k] = C[j];
			j++;
			inv++;;
		}
		k++;
	}
	inv = inv - j;
	if (i == p)
	{
		//A <- C
	}
	else
	{
		//A <- B
		inv = inv + j;
	}
}*/

void findInvMerge(int *set, int n)
{
  struct timeb start, end; // time structures
  //int inv = 0;
  int milli; // runtime in milliseconds
  temp = (int*)malloc(sizeof(int) * n);

  ftime(&start); // set start time
  sort(set, 0, n-1);
	//sort(set, n);
  ftime(&end); // set finish time

	free(temp);

  milli = (int)(1000 * (end.time - start.time)) + (end.millitm - start.millitm);

  printf("-----Question 1.2-----\n");
  printf("Number of Elements in Set: %d\n", n);
  printf("Number of Basic Operations: %d\n", bOp);
  printf("Number of Inversions: %d\n", inv);
  printf("Algorithm Time: %d milliseconds\n", milli);
  printf("Efficiency Class: O(nlog(n))\n\n");
}
