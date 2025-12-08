#include "hash_tables.h"
#include <string.h>
/**
 * hash_table_set - adds an element to the hash table
 * @ht: pointer to hash table
 * @key: key (string), cannot be empty
 * @value: value associated with the key (string), must be duplicated
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
unsigned long int idx;
hash_node_t *node, *tmp;
char *value_dup;
if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
return (0);
idx = key_index((const unsigned char *)key, ht->size);
tmp = ht->array[idx];
while (tmp)
{
if (strcmp(tmp->key, key) == 0)
{
value_dup = strdup(value);
if (value_dup == NULL)
return (0);

free(tmp->value);
tmp->value = value_dup;
return (1);
}
tmp = tmp->next;
}
node = malloc(sizeof(hash_node_t));
if (node == NULL)
return (0);
node->key = strdup(key);
if (node->key == NULL)
{
free(node);
return (0);
}
value_dup = strdup(value);
if (value_dup == NULL)
{
free(node->key);
free(node);
return (0);
}
node->value = value_dup;
node->next = ht->array[idx];
ht->array[idx] = node;
return (1);
}
