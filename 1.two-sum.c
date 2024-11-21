#include <stdlib.h>

struct Map {
  struct Node **buckets;
  int size;
};

struct Node {
  int key;
  int value;
  struct Node *next;
};

struct Map *map_create(int size) {
  struct Map *map = malloc(sizeof(struct Map));

  map->buckets = malloc(sizeof(struct Node *) * size);
  map->size = size;

  for (int i = 0; i < size; i++)
    map->buckets[i] = NULL;

  return map;
}

void map_put(struct Map *map, int key, int value) {
  struct Node **node;

  node = &map->buckets[key % map->size];

  while (*node != NULL)
    node = &(*node)->next;

  *node = malloc(sizeof(struct Node));

  (*node)->key = key;
  (*node)->value = value;
  (*node)->next = NULL;
}

int map_get(struct Map *map, int key) {
  struct Node *node = map->buckets[key % map->size];

  while (node != NULL && node->key != key)
    node = node->next;

  if (node != NULL)
    return node->value;
  else
    return -1;
}

void map_free(struct Map *map) {
  struct Node *node, *prev;

  for (int i = 0; i < map->size; i++) {
    node = map->buckets[i];

    while (node != NULL) {
      prev = node;
      node = node->next;
      free(prev);
    }
  }

  free(map->buckets);
  free(map);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  struct Map *map = map_create(1024);
  int *result = malloc(sizeof(int) * 2);
  *returnSize = 2;

  for (int i = 0; i < numsSize; i++)
    map_put(map, nums[i], i);

  for (int i = 0; i < numsSize; i++) {
    int current = nums[i];
    int j = map_get(map, target - current);

    if (j == -1 || i == j)
      continue;
    int stored = nums[j];

    if (stored + current == target) {
      result[0] = i;
      result[1] = j;
      break;
    }
  }

  map_free(map);

  return result;
}

/*
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  int *result = malloc(sizeof(int) * 2);
  *returnSize = 2;

  for (int i = 0; i < numsSize; i++) {
    for (int j = 0; j < numsSize; j++) {
      if (i != j && nums[i] + nums[j] == target) {
        result[0] = i;
        result[1] = j;
        return result;
      }
    }
  }

  return result;
}
*/
