#include <iostream>

int main( int argc, char * argv[] )
{
  int a = 0;
  int b = 0;

  scanf_s("%d", &a);
  scanf_s("%d", &b);

  printf("%d %d", b - 1,  a - 1);

  return EXIT_SUCCESS;
}
