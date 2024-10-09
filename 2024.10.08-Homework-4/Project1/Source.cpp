
#include <iostream>

int main( int argc, char * argv[] )
{
  int mass[1000] = {0};
  int n = 0;
  int x = 0;
  int ans = 0;

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
    if (mass[i] == x)
    {
      ans += 1;
    }
  }
  
  printf("%d", ans);

  return EXIT_SUCCESS;
}
