#include <stdio.h>

long int sum(int, int);
long int sum(int a, int b)
{
  int result = a + b;
  printf("actual value %d\n", result);
  return &result;
}

int i = 0;

int main(void)
{
  int a = 5;
  int b = 6;
  long int result = sum(a, b);
  int *ptr = result;
  long int r = &b;
  printf("%p\n", &a);
  printf("%p\n", &b);
  printf("%p\n", result);
  printf("value %d\n", ptr);
  (i++) ? sum(a, a) : main();
  printf("%d\n", (result - r));
  return 0;
}