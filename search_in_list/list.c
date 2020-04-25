#include <stdlib.h>
#include "list.h"

List *create_list()
{
  List *list = malloc(sizeof(List));
  list->count = 0;
  list->first = NULL;
  list->last = NULL;
  return list;
}

void insert_input(List *list, int num)
{
  Node *new_node = malloc(sizeof(Node));
  new_node->value = num;
  new_node->next = NULL;
  list->count++;
  if (list->first == NULL)
    list->first = new_node;
  else
    list->last->next = new_node;
  list->last = new_node;
}

int find_position(List *list, int num)
{
  int position = 0;
  Node *current_node = list->first;
  while (current_node != NULL && current_node->value != num)
  {
    position++;
    current_node = current_node->next;
    if (list->count == position)
      position = -1;
  }
  return position;
}

void free_list(List *list)
{
  Node *node = list->first;
  while (node != NULL)
  {
    Node *temp = node->next;
    free(node);
    node = temp;
  }
  free(list);
}