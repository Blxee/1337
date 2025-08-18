int minChanges(int n, int k) {
  int num;
  int mask;

  if (k & ~n)
    return (-1);
  num = 0;
  mask = n ^ k;
  while (mask)
  {
    if (mask & 1)
      num++;
    mask >>= 1;
  }
  return (num);
}
