#include <stdio.h>
#include <stdlib.h>

typedef char *String;

typedef struct
{
  String *value;
  int length;
} Dynamic_Array;

int find_length(char *text)
{
  int len = 0;
  while (text[len] != '\0')
  {
    len++;
  }
  return len;
}

int total_char(char *text, char spliter, int len)
{
  int count = 0;
  for (int i = 0; i < len; i++)
  {
    if (text[i] == spliter)
    {
      count++;
    }
  }
  return count;
}

Dynamic_Array *split_text(char *text, char spliter)
{
  int length = find_length(text);
  Dynamic_Array *array = malloc(sizeof(Dynamic_Array));
  array->length = total_char(text, spliter, length) + 1;
  char *heap_string = malloc(sizeof(char) * (length + 1));
  for (int i = 0; i < length; i++)
  {
    heap_string[i] = text[i];
  }
  heap_string[length] = '\0';
  array->value = malloc(sizeof(String) * array->length);
  for (int i = 0, j = 1; i < length && j < array->length; i++)
  {
    if (text[i] == spliter)
    {
      heap_string[i] = '\0';
      array->value[j] = heap_string[i + 1];
      j++;
    }
  }
  return array;
}

int main(void)
{
  char text[] = "This is a new text";
  Dynamic_Array *result = split_text(text, ' ');
  return 0;
}

/*
  string as an array of chars
  values = {value, length} => value = {value, length}
*/
