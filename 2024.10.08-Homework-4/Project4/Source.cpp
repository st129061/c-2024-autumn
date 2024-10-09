
#include <iostream>

int main( int argc, char * argv[] )
{
  int mass[1000] = {0};
  int n = 0;
  int max_sum = 0;

  scanf_s("%d", &n);

  for (int i = 0; i < n; ++i)
  {
    int j = 0;

    scanf_s("%d", &j);
    mass[i] = j;
  }

  for (int i = 1; i < n - 1; ++i)
  {
    if (mass[i - 1] + mass[i] + mass[i + 1] > max_sum)
    {
      max_sum = mass[i - 1] + mass[i] + mass[i + 1];
    }
  }

  if (mass[n - 1] + mass[0] + mass[1] > max_sum)
  {
    max_sum = mass[n - 1] + mass[0] + mass[1];
  }
  if (mass[n - 2] + mass[n - 1] + mass[0] > max_sum)
  {
    max_sum = mass[n - 2] + mass[n - 1] + mass[0];
  }
  
  printf("%d", max_sum);
  
  return EXIT_SUCCESS;
}
