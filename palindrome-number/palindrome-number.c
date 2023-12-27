int isPalindrome(int x) {
  int max_digit, min_digit, left, right;

  if (x < 0)
    return (0);
  
  min_digit = 1;
  max_digit = 1;
  while (x / max_digit > 9)
    max_digit *= 10;

  while (max_digit > min_digit)
  {
    left = x / max_digit % 10;
    right = x / min_digit % 10;
    if (left != right)
      return (0);
    max_digit /= 10;
    min_digit *= 10;
  }

  return (1);
}
