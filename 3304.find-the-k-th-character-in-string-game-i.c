#include <stdlib.h>

char kthCharacter(int k) {
  int word_capacity = 64;
  int word_size = 1;
  char *word = malloc(sizeof(*word) * word_capacity);
  char result;

  word[0] = 'a';

  while (word_size < k) {

    if (word_capacity < word_size * 2) {
      word_capacity *= 2;
      word = realloc(word, sizeof(*word) * word_capacity);
    }

    for (int i = 0; i < word_size; i++) {
      word[word_size + i] = 'a' + (word[i] - 'a' + 1) % 26;
    }

    word_size *= 2;
  }
    
  result = word[k - 1];
  free(word);

  return result;
}
