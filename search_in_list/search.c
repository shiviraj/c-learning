#include <stdio.h>
#include "list.h"

void insert_input_in_list(List *list)
{
  signed int input_num = 0;
  while (input_num != -99)
  {
    printf("Please enter a number:\n");
    scanf("%d", &input_num);
    insert_input(list, input_num);
  };
}

void print_position(int num, int position)
{
  if (position == -1)
    printf("%d is not present in the list\n", num);
  else
    printf("%d is present in the list at position %d\n", num, position);
}

void find_and_print_position(List *list)
{
  signed int input_num;
  printf("What number would you like to search for?\n");
  scanf("%d", &input_num);
  while (input_num != -99)
  {
    int position = find_position(list, input_num);
    print_position(input_num, position);
    printf("What number would you like to search for?\n");
    scanf("%d", &input_num);
  };
}

int main(void)
{
  List *list = create_list();
  insert_input_in_list(list);
  find_and_print_position(list);
  free_list(list);
  return 0;
}