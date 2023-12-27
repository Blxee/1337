#include <stdlib.h>


typedef struct hash_node_s {
  int key;
  int value;
  struct hash_node_s *next;
} hash_node_t;


typedef struct hash_table_s {
  hash_node_t **array;
  int size;
} hash_table_t;


hash_table_t *ht_create(int size)
{
  hash_table_t *table;

  if (size < 0)
    return (NULL);

  table = malloc(sizeof(*table));
  if (table == NULL)
    return (NULL);

  table->array = calloc(size, sizeof(hash_node_t *));
  if (table->array == NULL)
  {
    free(table);
    return (NULL);
  }

  return (table);
}


hash_node_t *ht_set(hash_table_t *table, int key, int value)
{
  int index;
  hash_node_t *node, **tmp;

  if (table == NULL || key < 0)
    return (NULL);

  index = key % table->size;

  node = malloc(sizeof(*node));
  if (node == NULL)
    return (NULL);
  node->key = key;
  node->value = value;
  node->next = NULL;

  tmp = &table->array[index];
  while (*tmp != NULL)
    tmp = &(*tmp)->next;
  *tmp = node;

  return (node);
}


hash_node_t *ht_get(hash_table_t *table, int key)
{
  int index;
  hash_node_t *node;

  if (table == NULL || key < 0)
    return (NULL);

  index = key % table->size;

  node = table->array[index];
  while (node != NULL && node->key != key)
    node = node->next;

  return (node);
}


void ht_free(hash_table_t *table)
{
  int i;
  hash_node_t *tmp;

  if (table != NULL)
  {
    if (table->array != NULL)
    {
      i = 0;
      while (i < table->size)
      {
        tmp = table->array[i];
        // while (tmp->next)
        free(tmp);
      }
      free(table->array);
    }
    free(table);
  }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(
  int* nums,
  int numsSize,
  int target,
  int* returnSize
) {
  hash_table_t *table;
  hash_node_t *node;
  int i;
  int *two;

  table = ht_create(numsSize);

  i = 0;
  while (i < numsSize)
  {
    ht_set(table, nums[i], i);
    i++;
  }

  i = 0;
  while (i < numsSize)
  {
    node = ht_get(table, target - nums[i]);
    if (node != NULL)
    {
      two = malloc(2 * sizeof(*two));
      two[0] = i;
      two[1] = node->value;
      *returnSize = 2;
      ht_free(table);
      return (two);
    }
    i++;
  }

  ht_free(table);
  return (NULL);
}
