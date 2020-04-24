#include <stdio.h>

void swap(int *a, int *b)
{
  int c = *a;
  *a = *b;
  *b = c;
}

int main(void)
{
  int a = 5;
  int b = 6;
  swap(&a, &b);
  printf("a is %d, b is %d\n", a, b);
  return 0;
}