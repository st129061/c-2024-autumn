#include <iostream>

int main( int argc, char * argv[] )
{
  int x1 = 0;
  int y1 = 0;
  int x2 = 0;
  int y2 = 0;

  scanf_s("%d", &x1);
  scanf_s("%d", &y1);
  scanf_s("%d", &x2);
  scanf_s("%d", &y2);

  int dx = x1 - x2;
  int dy = y1 - y2;

  if (dx == 0 || dy == 0 || dx == dy || dx == -dy)
  {
    printf("YES");
  }
  else
  {
    printf("NO");
  }

  return EXIT_SUCCESS;
}
