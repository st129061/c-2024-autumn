
#include <iostream>

int main( int argc, char * argv[] )
{
  int mass[1000] = {0};
  int n = 0;

  scanf_s("%d", &n);

  for (int i = 0; i < n; ++i)
  {
    int j = 0;

    scanf_s("%d", &j);
    mass[i] = j;
  }

  for (int i = n - 1; i > -1; --i)
  {
    printf("%d ", mass[i]);

  }
  
  return EXIT_SUCCESS;
}
