/* Braelyn Rotman
  1006740
  February 10th, 2019
  A2 Q2.2 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include <stdbool.h>
#include <math.h>

typedef struct point{
  float x;
  float y;
} Point;

Point *extreme;
int numPoints; // number of extreme points
int length; // malloced space for extreme points
unsigned long int bsOp = 0; // # basic operations


bool containsPoint(Point add)
{
  for (int i = 0 ; i < numPoints ; i++)
  {
    if(extreme[i].x == add.x && extreme[i].y == add.y)
    {
      return true;
    }
  }
  return false;
}

void add(Point add) // add a point to the hull
{
  if(containsPoint(add) == false)
  {
    numPoints++;
    if(numPoints > length)
    {
      length = length + 5;
      extreme = realloc(extreme, sizeof(Point)*length);
    }
    extreme[numPoints - 1].x = add.x;
    extreme[numPoints - 1].y = add.y;
  }
}

int getSide(Point left, Point right, Point compare)
{
  float a = 0, b = 0, c = 0, d = 0;
//  printf("GETSIDE\n");
  a = right.y - left.y;
  b = left.x - right.x;
  c = (left.x)*(right.y) - (left.y)*(right.x);
  d = ((a)*compare.x) + ((b)*compare.y) - c; // check side of line
  if (d > 0)
  {
    return 1;
  }
  else if (d < 0)
  {
    return -1;
  }
  return 0;
}

void recursion(Point *S, int n, Point left, Point right, int side)
{
  int i = 0;
  int index = 0;
  float a = 0, b = 0, c = 0;
  int dist = 0;
  int d = 0; // result of equation determining the side of a line
  int max = 0; // max distance
//  printf("RECURSION\n");

  // find farthest point from line
  for (i = 0 ; i < n ; i++)
  {
    d = getSide(left, right, S[i]);
    bsOp++;
    if(d == side) // if on the correct side
    {
      a = right.y - left.y;
      b = left.x - right.x;
      c = (left.x)*(right.y) - (left.y)*(right.x);

      dist = abs((a)*S[i].x + (b)*S[i].y + c); // distance formula modified from https://brilliant.org/wiki/dot-product-distance-between-point-and-a-line/
    //  dist = dist/sqrt(((a*a) + (b*b))); // dont need to sqrt since its the same divisor for every point
      if (dist > max)
      {
        max = dist;
        index = i;
      }
    }
  }

  if (max == 0) // means there were no points
  {
    // add line endpoints to hull
    add(left);
    add(right);
    return;
  }

  //recurse
  recursion(S, n, S[index], left, (-1)*getSide(left, right, S[index]));
  recursion(S, n, S[index], right, getSide(left, right, S[index])); // infinite
}


void findhull(Point* S, int n)
{
  recursion(S, n, S[0], S[n-1], -1);
  recursion(S, n, S[0], S[n-1], 1);
}

void sortX(Point *S, int n) // sort extreme by x
{
  Point temp;
  for (int i = 0; i < n ; i++)
  {
    for (int j = i + 1; j < n ; j++)
    {
      if (S[i].x > S[j].x)
      {
        temp.x = S[i].x;
        temp.y = S[i].y;
        S[i].x = S[j].x;
        S[i].y = S[j].y;
        S[j].x = temp.x;
        S[j].y = temp.y;
      }
      else if(S[i].x == S[j].x)
      {
        if(S[i].y > S[j].y)
        {
          temp.x = S[i].x;
          temp.y = S[i].y;
          S[i].x = S[j].x;
          S[i].y = S[j].y;
          S[j].x = temp.x;
          S[j].y = temp.y;
        }
      }
    }
  }
}

void quickhull(Point *S, int n)
{
  struct timeb start, end; // time structures
  int milli; // runtime in milliseconds

  sortX(S, n);
  extreme = calloc(5, sizeof(Point));
  length = 5;
  ftime(&start); // set start time
  findhull(S, n);
  ftime(&end); // set finish time
  milli = (int)(1000 * (end.time - start.time)) + (end.millitm - start.millitm);

  printf("-----Question 2.2-----\n");
  printf("Number of Elements in Set: %d\n", n);
  printf("Number of Basic Operations: %lu\n", bsOp);
  printf("Points on Outside: %d\n", numPoints);
  printf("Algorithm Time: %d milliseconds\n", milli);
  printf("Efficiency Class: O(nlog(n))\n\n");

  //sortExt(e);
  printf("Convex Hull Extreme Points:\n");
  for (int x = 0 ; x < numPoints ; x++)
  {
    printf("%f %f\n", extreme[x].x, extreme[x].y);
  }
  free(extreme);
  printf("\n");
}
