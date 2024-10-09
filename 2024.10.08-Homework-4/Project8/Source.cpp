
#include <iostream>

int main( int argc, char * argv[] )
{
  int mass[1000] = {0};
  int n = 0;
  int x = 0;

  scanf_s("%d", &n);

  for (int i = 0; i < n; ++i)
  {
    int j = 0;

    scanf_s("%d", &j);
    mass[i] = j;
  }

  scanf_s("%d", &x);

  for (int k = 0; k < x; ++k)
  {
    int l = 0;
    int r = 0;
    
    scanf_s("%d", &l);
    scanf_s("%d", &r);

    for (int i = l - 1; i < r; ++i)
    {
      printf("%d ", mass[i]);
    }

    printf("\n");
  }
  
  return EXIT_SUCCESS;
}
