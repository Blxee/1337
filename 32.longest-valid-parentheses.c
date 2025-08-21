#include <stdlib.h>
#include <string.h>
static char *openings = "([{";
static char *closings = ")]}";

int bracket_idx(char b)
{
  int i;

  i = 0;
  while (i < 3)
  {
    if (b == openings[i])
      return (i);
    i++;
  }
  return (-1);
}

int longestValidParentheses(char* s) {
  int i;
  int j;
  int pairs;
  char *stack;
  int idx = 0;
  int longest = 0;

  stack = malloc(strlen(s));
  pairs = 0;
  i = 0;
  while (s[i])
  {
    j = bracket_idx(s[i]);
    if (j != -1)
      stack[idx++] = closings[j];
    else if (idx > 0 && s[i] == stack[idx - 1])
    {
      pairs += 2;
      if (pairs > longest)
        longest = pairs;
      idx--;
    }
    else
    {
      pairs = 0;
      idx = 0;
    }
    i++;
  }
  free(stack);
  return (longest);
}
