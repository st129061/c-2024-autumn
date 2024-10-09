
#include <iostream>

int main( int argc, char * argv[] )
{
  int mass[100] = {0};
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

  ans = n;

  for (int i = 0; i < n; ++i)
  {
    if (x > mass[i])
    {
      ans = i;
      break;
    }
  }

  printf("%d", ans + 1);
  
  return EXIT_SUCCESS;
}
