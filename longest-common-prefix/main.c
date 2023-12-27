#include <stdlib.h>
#include <string.h>


char* longestCommonPrefix(char** strs, int strsSize)
{
  char *prefix = malloc(200 * sizeof(char));
  unsigned int i, j;

  if (prefix == NULL)
    return (NULL);

  strcpy(prefix, strs[i]);
  i = 1;
  while (i < strsSize)
  {
    j = 0;
    while (prefix[j] &&  prefix[j] == strs[i][j])
      j++;
    prefix[j] = '\0';
    i++;
  }

  return (prefix);
}
