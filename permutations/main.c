#include <stdlib.h>


int factorial(int x)
  { return ((x == 1) ? 1 : x * factorial(x - 1)); }


int** permute(
  int* nums, int numsSize,
  int* returnSize, int** returnColumnSizes
) {
  int** permutations;
  int rows = factorial(numsSize), cols = numsSize;
  int i;

  permutations = malloc(rows * sizeof(int *));
  for (i = 0; i < rows; i++)
  {
    // do it!
  }

  *returnSize = rows;
  *returnColumnSizes = malloc(rows * sizeof(int));
  for (i = 0; i < rows; i++)
    (*returnColumnSizes)[i] = cols;

  return (permutations);
}

#include <stdio.h>
int main(void)
{
  int nums[] = {1, 2, 3}, s = 3, rs, *rcs;
  permute(nums, s, &rs, &rcs);
  return 0;
}
