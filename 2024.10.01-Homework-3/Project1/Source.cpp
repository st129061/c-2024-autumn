#include <iostream>

int main( int argc, char *argv[] )
{
  int up = 0;
  int down = 0;
  int i = 0;

  scanf_s("%d", &i);

  for (; i > 0; --i)
  {
    int tmp = 0;
    scanf_s("%d", &tmp);
    if (tmp == 0)
    {
      down += 1;
    }
    else
    {
      up += 1;
    }
  }

  if (down > up)
  {
    printf("%d", up);
  }
  else
  {
    printf("%d", down);
  }

  return EXIT_SUCCESS;
}