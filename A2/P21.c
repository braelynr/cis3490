/* Braelyn Rotman
  1006740
  February 10th, 2019
  A2 Q2.1 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include <stdbool.h>

typedef struct point{
  float x;
  float y;
} Point;

unsigned long int basicOp = 0; // # basic operations
Point *extreme;

void sortExt(int n) // sort extreme by x
{
  Point temp;
  for (int i = 0; i < n ; i++)
  {
    for (int j = i + 1; j < n ; j++)
    {
      if (extreme[i].x > extreme[j].x)
      {
        temp.x = extreme[i].x;
        temp.y = extreme[i].y;
        extreme[i].x = extreme[j].x;
        extreme[i].y = extreme[j].y;
        extreme[j].x = temp.x;
        extreme[j].y = temp.y;
      }
      else if(extreme[i].x == extreme[j].x)
      {
        if(extreme[i].y > extreme[j].y)
        {
          temp.x = extreme[i].x;
          temp.y = extreme[i].y;
          extreme[i].x = extreme[j].x;
          extreme[i].y = extreme[j].y;
          extreme[j].x = temp.x;
          extreme[j].y = temp.y;
        }
      }
    }
  }
}

bool hasI(int i, Point* plane)
{
  for (int k = 0 ; k < sizeof(extreme) ; k++)
  {
    if (plane[i].x == extreme[k].x && plane[i].y == extreme[k].y)
    {
      return true;
    }
  }
  return false;
}

bool hasJ(int j, Point* plane)
{
  for (int k = 0 ; k < sizeof(extreme) ; k++)
  {
    if (plane[j].x == extreme[k].x && plane[j].y == extreme[k].y)
    {
      return true;
    }
  }
  return false;
}

void convexBrute(Point *plane, int n)
{
  int size = 5; // extreme array size
  int e = 0; // number of extreme points
  struct timeb start, end; // time structures
  int milli; // runtime in milliseconds
  int i = 0, j = 0, k = 0;
  float c;
  float equ;
  bool ex = false; // extreme points
  char side; // p or n

  extreme = calloc(5, sizeof(Point));
  ftime(&start); // set start time
  for (i = 0 ; i < n ; i=i+2)//2)
  {
    for (j = i + 1 ; j < n ; j++) // j = i + 1
    {
      if (i != j)
      {
        side = ' ';
        ex = true;
        c = (plane[i].x)*(plane[j].y) - (plane[i].y)*(plane[j].x);

        for (k = 0 ; k < n ; k++)
        {
        //  printf("i = %d\t j = %d\t k = %d\n", i , j, k);
          if (k != i && k != j)
          {
            equ = ((plane[j].y - plane[i].y)*plane[k].x) + ((plane[i].x - plane[j].x)*plane[k].y);
          //  printf("equ - c = %f\n", equ - c);
            basicOp++;
            if (equ - c > 0)
            {
              if (side == 'n') // not an outside line
              {
                ex = false;
              }
              side = 'p';
            }
            else if (equ - c < 0)
            {
              if (side == 'p') // not an outside line
              {
                ex = false;
              }
              side = 'n';
            }
            else // on line
            {
              ex = false;
            }
          }
        }
        if (ex == true) // add to extreme points array
        {
          e = e + 2; // +2
          if (e >= size)
          {
            size = size + 5;
            extreme = realloc(extreme, sizeof(Point)*size);
          }
         if(hasI(i, plane) == false)
         {
           extreme[e - 2] = plane[i]; // -2
         }
         else
         {
           e--;
         }
         if(hasJ(j, plane) == false)
         {
           extreme[e - 1] = plane[j];
         }
         else
         {
           e--;
         }
          //break;
        }
      }
    }
          printf("i = %d\n", i);
  }
  ftime(&end); // set finish time
  milli = (int)(1000 * (end.time - start.time)) + (end.millitm - start.millitm);

  printf("-----Question 2.1-----\n");
  printf("Number of Elements in Set: %d\n", n);
  printf("Number of Basic Operations: %lu\n", basicOp);
  printf("Points on Outside: %d\n", e);
  printf("Algorithm Time: %d milliseconds\n", milli);
  printf("Efficiency Class: O(n^3)\n\n");

  sortExt(e);
  printf("Convex Hull Extreme Points:\n");
  for (int x = 0 ; x < e ; x++)
  {
    printf("%f %f\n", extreme[x].x, extreme[x].y);
  }
  printf("\n");
  free(extreme);
}
