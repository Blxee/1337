int minConst(char *colors, int *neededTime, int neededTimeSize)
{
  int i, total = 0, max = 0;

  i = 0;
  while (i < neededTimeSize)
  {
    if (i > 0 && colors[i-1] != colors[i])
    {
      total -= max;
      max = neededTime[i];
    }
    else
    {
      if (neededTime[i] > max)
        max = neededTime[i];
    }
    total += neededTime[i];
    i++;
  }
  total -= max;

  return (total);
}
