#include <iostream>

int main( int argc, char *argv[] )
{
  int i = 0;

  scanf_s("%d", &i);

  for (; i > 0; --i)
  {
    int n = 0;
    int m = 0;
    int d = 0;
    scanf_s("%d", &n);
    scanf_s("%d", &m);

    d = 19 * m + (n + 239) * (n + 366) / 2;
    printf("%d\n", d);
  }
  return EXIT_SUCCESS;
}