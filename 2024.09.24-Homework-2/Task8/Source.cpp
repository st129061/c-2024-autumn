#include <iostream>
#include <cmath>

int main( int argc, char * argv[] )
{
  int M = 0;
  int N = 0;

  scanf_s("%d", &M);
  scanf_s("%d", &N);
  
  int a = std::min(M / 2, N / 2);
  int newM = M - 2 * a;
  int newN = N - 2 * a;
  int add = 0;
  if (newM == 0 || newN == 0)
    add = (newM + newM) * 2;
  printf("%d", M * N * 4 + add);

  return EXIT_SUCCESS;
}
