#include <iostream>

// 14 = 5 * 2 + 4
// 5 = 4 * 1 + 1
// 4 = 1 * 4 + 0

int main( int argc, char *argv[] )
{
  int a = 0;
  int b = 0;

  scanf_s("%d", &a);
  scanf_s("%d", &b);

  if (a < b)
  {
    int tmp = a;

    a = b;
    b = tmp;
  }

  int gcd = b;
  int r = a % b;
  
  while (r != 0)
  {
    int r3 = gcd % r;
    
    gcd = r;
    r = r3;
  }

  printf("%d\n", a * b / gcd);
  
  return EXIT_SUCCESS;
}