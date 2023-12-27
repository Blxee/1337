#include <limits.h>

int myAtoi(char *str)
{
  int sign = 1;
  int i;
  long x, scale = 1;

  while (*str == ' ')
    str++;
  if (*str == '+')
    str++;
  else if (*str == '-')
    sign = -1, str++;
  while (*str == '0')
    str++;

  i = 0;
  while (str[i] >= '0' && str[i] <= '9' && i < 12)
    i++;
  i--;

  x = 0;
  while (i >= 0)
  {
    x += (str[i] - '0') * scale;
    scale *= 10;
    i--;
  }
  x *= sign;

  if (x > INT_MAX) x = INT_MAX;
  else if (x < INT_MIN) x = INT_MIN;

  return (x);
}
