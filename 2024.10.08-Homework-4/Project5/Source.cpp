
#include <iostream>

int main( int argc, char * argv[] )
{
  int mass[1000] = {0};
  int n = 0;
  int x = 0;
  int min_d = 2001;

  scanf_s("%d", &n);

  for (int i = 0; i < n; ++i)
  {
    int j = 0;

    scanf_s("%d", &j);
    mass[i] = j;
  }

  scanf_s("%d", &x);

  for (int i = 0; i < n; ++i)
  {
    if (abs(mass[i] - x) < abs(min_d) || (abs(mass[i] - x) == abs(min_d) && mass[i] - x < 0))
    {
      min_d = mass[i] - x;
    }
  }
  
  printf("%d", x + min_d);
  
  return EXIT_SUCCESS;
}
