#include <iostream>

int main( int argc, char * argv[] )
{
  int x = 0;
  int y = 0;

  scanf_s("%d", &x);
  scanf_s("%d", &y);

  if (x == y)
  {
    if (x == 1)
    {
      printf("0");
    }
    else
    {
      printf("2");
    }
  }
  else
  {
    printf("1");
  }

  return EXIT_SUCCESS;
}
