
#include <iostream>

int main( int argc, char * argv[] )
{
  int mass[1000] = {0};
  int n = 0;
  int l = 0;
  int r = 0;
  int index_max = 0;

  scanf_s("%d", &n);

  for (int i = 0; i < n; ++i)
  {
    int j = 0;

    scanf_s("%d", &j);
    mass[i] = j;
  }

  scanf_s("%d", &l);
  scanf_s("%d", &r);
  
  l -= 1;
  r -= 1;
  index_max = l;
  
  for (int i = l; i < r + 1; ++i)
  {
    if (mass[index_max] < mass[i])
    {
      index_max = i;
    }
  }
  
  printf("%d %d", mass[index_max], index_max + 1);

  return EXIT_SUCCESS;
}
