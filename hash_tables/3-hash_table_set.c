#include "hash_tables.h"
#include <string.h>
/**
 * hash_table_set - adds an element to a hash table
 * @ht: hash table
 * @key: key (non-empty)
 * @value: value to store (duplicated)
 *
 * Return: 1 success, 0 failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
hash_node_t *node, *tmp;
char *val_dup;
unsigned long int idx;
if (!ht || !key || !*key || !value)
return (0);
idx = key_index((const unsigned char *)key, ht->size);
tmp = ht->array[idx];
while (tmp)
{
if (strcmp(tmp->key, key) == 0)
{
val_dup = strdup(value);
if (!val_dup)
return (0);
free(tmp->value);
tmp->value = val_dup;
return (1);
}
tmp = tmp->next;
}
node = malloc(sizeof(hash_node_t));
if (!node)
return (0);
node->key = strdup(key);
if (!node->key)
return (free(node), 0);
val_dup = strdup(value);
if (!val_dup)
return (free(node->key), free(node), 0);

node->value = val_dup;
node->next = ht->array[idx];
ht->array[idx] = node;
return (1);
}
