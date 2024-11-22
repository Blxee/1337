int is_digit(char c) {
  return c >= '0' && c <= '9';
}

void shift_str_left(char *str) {
  int i = 1;

  if (str[0] == '\0')
    return;

  do {
    str[i - 1] = str[i];
  } while (str[i++] != '\0');
}

char* clearDigits(char* s) {
  int i = 0;

  while (s[i] != '\0') {
    if (is_digit(s[i])) {
      shift_str_left(s + i);
      if (i > 0)
        shift_str_left(s + i - 1);
      i--;
    } else {
      i++;
    }
  }

  return s;
}
