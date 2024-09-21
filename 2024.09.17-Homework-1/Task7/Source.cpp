#include <iostream>

int main( int argc, char * argv[] )
{
  int a = 0;
  int b = 0;

  scanf_s("%d", &a);
  scanf_s("%d", &b);

  printf("%d", 1 + (a * b % 109 + 109) % 109);

  return EXIT_SUCCESS;
}
