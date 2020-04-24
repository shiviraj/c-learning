#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int *value;
  int length;
} Dynamic_Array;

int *copy_array_into_heap(int *array, int length)
{
  int *array_ptr = malloc(sizeof(int) * length);
  for (int i = 0; i < length; i++)
  {
    array_ptr[i] = array[i];
  }
  return array_ptr;
}

Dynamic_Array *create_dynamic_array(int *array, int length)
{
  Dynamic_Array *my_array = malloc(sizeof(Dynamic_Array));
  my_array->value = copy_array_into_heap(array, length);
  my_array->length = length;
  return my_array;
}

int total_even_num(Dynamic_Array *array)
{
  int len = 0;
  for (int i = 0; i < array->length; i++)
  {
    if (array->value[i] % 2 == 0)
    {
      len = len + 1;
    }
  }
  return len;
}

int *filter_evens(Dynamic_Array *array, int total_evens)
{
  int *evens_array = malloc(sizeof(int) * total_evens);
  int index = 0;
  for (int i = 0; i < array->length; i++)
  {
    if (array->value[i] % 2 == 0)
    {
      evens_array[index++] = array->value[i];
    }
  }
  return evens_array;
}

Dynamic_Array *filter_even_numbers(Dynamic_Array *array)
{
  Dynamic_Array *even_array = malloc(sizeof(Dynamic_Array));
  even_array->length = total_even_num(array);
  even_array->value = filter_evens(array, even_array->length);
  return even_array;
}

int main(void)
{
  int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Dynamic_Array *array = create_dynamic_array(numbers, 9);
  Dynamic_Array *evens = filter_even_numbers(array);
  return 0;
}