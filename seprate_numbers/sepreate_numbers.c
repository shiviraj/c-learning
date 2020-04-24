#include <stdio.h>
#include <stdlib.h>
#include "seperate_number.h"

Array *copy_into_array(Local_list list, int length)
{
  Array *array = malloc(sizeof(Array));
  array->length = length;
  array->values = malloc(sizeof(int) * array->length);
  for (Index i = 0; i < length; i++)
    array->values[i] = list[i];
  return array;
}

Array_of_array *create_array_of_array(int length)
{
  Array_of_array *array = malloc(sizeof(Array_of_array));
  array->length = length;
  array->arrays = malloc(sizeof(Array) * length);
  return array;
}

Array_of_array *seprate_number(Local_list list, int length, Local_list range)
{
  int small_idx = 0, range_idx = 0, great_idx = 0;
  int small_nums[length], range_nums[length], great_nums[length];
  for (Index i = 0; i < length; i++)
  {
    if (range[0] > list[i])
      small_nums[small_idx++] = list[i];
    else if (list[i] > range[1])
      great_nums[great_idx++] = list[i];
    else
      range_nums[range_idx++] = list[i];
  }
  Array_of_array *seprated_list = create_array_of_array(3);
  seprated_list->arrays[0] = *copy_into_array(small_nums, small_idx);
  seprated_list->arrays[1] = *copy_into_array(range_nums, range_idx);
  seprated_list->arrays[2] = *copy_into_array(great_nums, great_idx);
  return seprated_list;
}

void print_separated_numbers(Array_of_array *separate_numbers)
{
  for (Index i = 0; i < separate_numbers->length; i++)
  {
    Array *current_range = &separate_numbers->arrays[i];
    for (Index j = 0; j < current_range->length; j++)
      printf("%d, ", current_range->values[j]);
    printf("\n");
  }
};

int main(void)
{
  int length = 8;
  int list[] = {3, 1, 7, 4, 6, 5, 8, 2};
  int range[] = {4, 7};
  Array_of_array *separated_numbers = seprate_number(list, length, range);
  print_separated_numbers(separated_numbers);
  return 0;
}