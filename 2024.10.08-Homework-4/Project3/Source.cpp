
#include <iostream>

int main( int argc, char * argv[] )
{
  int mass[1000] = {0};
  int n = 0;
  int index_max = 0;
  int index_min = 0;

  scanf_s("%d", &n);

  for (int i = 0; i < n; ++i)
  {
    int j = 0;

    scanf_s("%d", &j);
    mass[i] = j;
  }

  for (int i = 0; i < n; ++i)
  {
    if (mass[index_max] <= mass[i])
    {
      index_max = i;
    }
  }
  
  for (int i = 0; i < n; ++i)
  {
    if (mass[index_min] > mass[i])
    {
      index_min = i;
    }
  }

  for (int i = 0; i < n; ++i)
  {
    if (mass[index_max] == mass[i])
    {
      mass[i] = mass[index_min];
    }
  }

  for (int i = 0; i < n; ++i)
  {
    printf("%d ", mass[i]);
  }
  
  return EXIT_SUCCESS;
}
