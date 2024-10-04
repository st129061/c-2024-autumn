#include <iostream>

int main( int argc, char *argv[] )
{
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;

  scanf_s("%d", &a);
  scanf_s("%d", &b);
  scanf_s("%d", &c);
  scanf_s("%d", &d);

  for (int k = -100; k <= 100; ++k)
  {
    if ((long long)a * k * k * k + (long long)b * k * k + (long long)c * k + d == 0)
    {
      printf("%d ", k);
    }
  }
  
  return EXIT_SUCCESS;
}