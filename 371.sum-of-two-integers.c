int getSum(unsigned int a, unsigned int b) {

  do {
    int c = (a & b) << 1;
    a ^= b;
    b = c;
  } while (b);

  return a;
}
