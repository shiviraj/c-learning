#ifndef __SEPARATE_NUMBER_H_
#define __SEPARATE_NUMBER_H_

typedef unsigned int Index;
typedef int *Local_list;

typedef struct
{
  int *values;
  int length;
} Array;

typedef struct
{
  Array *arrays;
  int length;
} Array_of_array;

Array *copy_into_array(int *list, int length);
Array_of_array *create_array_of_array(int length);
Array_of_array *seprate_number(Local_list list, int length, Local_list range);
void print_separated_numbers(Array_of_array *separate_numbers);

#endif