#include <stdlib.h>
#include <string.h>

#define false 0
#define true 1
typedef int bool;


/**
 * areNumbersAscending - determines whether numbers in string are ascending
 *
 * @s: the target string
 *
 * Return: 1 if ascending and 0 elsewise
 */
bool areNumbersAscending(char* s) {
  char *token;
  int prev = -1, num;

  token = strtok(s, " ");
  if (*token >= '0' && *token <= '9')
    prev = atoi(token);

  while ((token = strtok(NULL, " ")) != NULL)
  {
    if (*token >= '0' && *token <= '9')
      num = atoi(token);
    if (prev >= num)
      return (false);
  }

  return (true);
}
