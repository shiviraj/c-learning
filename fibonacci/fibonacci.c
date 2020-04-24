#include <stdio.h>

void fibonacci_series(int, int *);
void print_fibonacci(int, int *);

void fibonacci_series(int number, int *fibonacci)
{
  int current_term = 0;
  int next_term = 1;

  for (int num = 0; num < number; num++)
  {
    *(fibonacci + num) = current_term;
    next_term = current_term + next_term;
    current_term = next_term - current_term;
  }
};

void print_fibonacci(int number, int *fibonacci)
{
  for (int num = 0; num < number; num++)
  {
    int *address = fibonacci + num;
    printf("%p\t%d\n", address, *address);
  }
}

int main(void)
{
  int number;
  printf("Enter a number : ");
  scanf("%d", &number);
  int fibonacci[number];
  printf("%p\t%p\n", &number, &fibonacci);
  fibonacci_series(number, &fibonacci);
  print_fibonacci(number, &fibonacci);
  return 0;
}