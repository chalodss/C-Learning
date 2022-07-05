/*
 ============================================
 Name         : pointers_variables.c
 Author       : Charles T.
 Version      : 1.0
 Copyright    : by default
 Description  : pointers and local variables
 ============================================
*/

#include <stdio.h>

#define RED   "\033[1;31m"
#define BLUE  "\033[1;34m"
#define PINK  "\033[1;35m"
#define EMPTY "\033[0m"

int	main(void)
{
  int a   = 16;
  int *p  = &a;

  printf("Local variables\n\n");
  printf("Value of variable a:\t %s%20d%s \t ---\t Address of a:  %s%20p%s\n", RED, a, EMPTY, BLUE, (void *)&a, EMPTY);
  printf("Value of pointer p:\t %s%20p%s \t ---\t Address of p: %s%21p%s\n", BLUE, p, EMPTY, PINK, (void *)&p, EMPTY);
  printf("Value pointed by p:\t %s%20d%s\n", RED, *p, EMPTY);
  return 0;
}
