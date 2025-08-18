int minChanges(int n, int k) {
  int num;
  int mask;

  num = 0;
  mask = n ^ k;
  if (k & ~n)
    return (-1);
  while (mask)
  {
    if (mask & 1)
      num++;
    mask >>= 1;
  }
  return (num);
}
