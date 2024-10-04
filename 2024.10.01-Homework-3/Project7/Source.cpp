#include <iostream>

// 14 = 5 * 2 + 4
// 5 = 4 * 1 + 1
// 4 = 1 * 4 + 0

int main( int argc, char *argv[] )
{
  int n = 0;
  int m = 0;

  scanf_s("%d", &n);
  scanf_s("%d", &m);

  int a = n;
  int b = m;

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

  printf("%d\n", n / gcd);
  
  return EXIT_SUCCESS;
}