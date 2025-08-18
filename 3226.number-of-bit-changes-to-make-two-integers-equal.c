int minChanges(int n, int k) {
  int num;
  int i;

  num = 0;
  i = 0;
  while (i < 32)
  {
    if ((n & 1) != (k & 1))
    {
      if (n & 1)
        num++;
      else
        return (-1);
    }
    n >>= 1;
    k >>= 1;
    i++;
  }
  return (num);
}
