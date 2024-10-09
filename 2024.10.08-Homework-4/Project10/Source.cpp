
#include <iostream>

int main( int argc, char * argv[] )
{
  int mass[1000] = {0};
  int n = 0;
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;

  scanf_s("%d", &n);
  scanf_s("%d", &a);
  scanf_s("%d", &b);
  scanf_s("%d", &c);
  scanf_s("%d", &d);

  a -= 1;
  b -= 1;
  c -= 1;
  d -= 1;

  for (int i = 0; i < n; ++i)
  {
    mass[i] = i + 1;
  }

  for (int i = 0; i <= (b - a) / 2; ++i)
  {
    int tmp = mass[a + i];
    
    mass[a + i] = mass[b - i];
    mass[b - i] = tmp;
  }

  for (int i = 0; i <= (d - c) / 2; ++i)
  {
    int tmp = mass[c + i];

    mass[c + i] = mass[d - i];
    mass[d - i] = tmp;
  }

  for (int i = 0; i < n; ++i)
  {
    printf("%d ", mass[i]);
  }

  return EXIT_SUCCESS;
}
