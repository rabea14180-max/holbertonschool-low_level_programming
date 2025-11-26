#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to pointer to the head of the list
 * @idx: index where the new node should be added (starts at 0)
 * @n: value for the new node
 *
 * Return: address of the new node, or NULL if it fails
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *tmp, *new_node;
unsigned int i = 0;

if (h == NULL)
return (NULL);


if (idx == 0)
return (add_dnodeint(h, n));

tmp = *h;


while (tmp != NULL && i < idx - 1)
{
tmp = tmp->next;
i++;
}


if (tmp == NULL)
return (NULL);


if (tmp->next == NULL)
return (add_dnodeint_end(h, n));


new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;

new_node->next = tmp->next;
new_node->prev = tmp;
tmp->next->prev = new_node;
tmp->next = new_node;

return (new_node);
}
