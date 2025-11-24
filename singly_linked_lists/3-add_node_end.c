#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to the pointer of the first node
 * @str: string to duplicate and store in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
list_t *new_node;
list_t *current;
unsigned int len = 0;

if (str == NULL)
return (NULL);


while (str[len])
len++;


new_node = malloc(sizeof(list_t));
if (new_node == NULL)
return (NULL);

new_node->str = strdup(str);
if (new_node->str == NULL)
{
free(new_node);
return (NULL);
}

new_node->len = len;
new_node->next = NULL;


if (*head == NULL)
{
*head = new_node;
return (new_node);
}


current = *head;
while (current->next != NULL)
current = current->next;

current->next = new_node;

return (new_node);
}
