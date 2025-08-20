#include <stdlib.h>

int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
  int *ans;
  int i;
  int j;

  ans = malloc(sizeof(*ans) * numsSize);
  if (!ans)
    return (NULL);
  *returnSize = numsSize;
  i = 0;
  while (i < numsSize)
  {
    j = 1;
    while (nums[i] & j)
      j <<= 1;
    if (j == 1)
    {
      ans[i] = -1;
      i++;
      continue;
    }
    j >>= 1;
    ans[i] = nums[i] & ~j;
    i++;
  }
  return (ans);
}
