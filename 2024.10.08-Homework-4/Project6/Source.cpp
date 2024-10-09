
#include <iostream>

int main( int argc, char * argv[] )
{
  int mass[100] = {0};
  int p[100] = {0};
  int n = 0;
  int max_tax = -1;
  int index_max_tax = -1;

  scanf_s("%d", &n);

  for (int i = 0; i < n; ++i)
  {
    int j = 0;

    scanf_s("%d", &j);
    mass[i] = j;
  }

  for (int i = 0; i < n; ++i)
  {
    int j = 0;

    scanf_s("%d", &j);
    p[i] = j;
  }

  for (int i = 0; i < n; ++i)
  {
    if (mass[i] * p[i] > max_tax)
    {
      max_tax = mass[i] * p[i];
      index_max_tax = i;
    }
  }
  
  printf("%d", index_max_tax + 1);
  
  return EXIT_SUCCESS;
}
