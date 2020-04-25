#ifndef __LIST_H_
#define __LIST_H_

typedef struct node
{
  int value;
  struct node *next;
} Node;

typedef struct
{
  Node *first;
  Node *last;
  int count;
} List;

List *create_list();
void insert_input(List *list, int num);
int find_position(List *list, int num);
void free_list(List *list);

#endif