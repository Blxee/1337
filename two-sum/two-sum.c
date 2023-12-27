#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(
  int* nums,
  int numsSize,
  int target,
  int* returnSize
) {
  int i, j;
  int *two;

  i = 0;
  while (i < numsSize)
  {
    j = 0;
    while (j < numsSize)
    {
      if (i == j)
        continue;
      if (nums[i] + nums[j] == target)
      {
        two = malloc(2 * sizeof(*two));
        two[0] = nums[i];
        two[1] = nums[j];
        *returnSize = 2;
        return (two);
      }
      j++;
    }
    i++;
  }

  return (NULL);
}
