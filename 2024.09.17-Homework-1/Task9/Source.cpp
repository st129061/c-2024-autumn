#include <iostream>

int main( int argc, char * argv[] )
{
  int H = 0;
  int A = 0;
  int B = 0;
  int d = 0;

  scanf_s("%d", &H);
  scanf_s("%d", &A);
  scanf_s("%d", &B);

  d = (H - B) / (A - B);
  d = d * (d > 0) + 1 * (d <= 0);

  printf("%d", d + !((H - B) <= d * (A - B)));

  return EXIT_SUCCESS;
}
