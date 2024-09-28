#include <iostream>

int main( int argc, char * argv[] )
{
  int N = 0;
  
  scanf_s("%d", &N);

  // 5 * x + 3 * y = N
  // 5 = 3 * 1 + 2
  // 3 = 2 * 1 + 1
  // 2 = 1 * 2 + 0

  // 2 = 5 - 3
  // 1 = 3 * 2 - 5
  // N = 3 * 2N - 5 * N
  // 5x + 3y = 0
  // x = 3t
  // y = -5t

  // x = -N + 3t
  // y = 2 * N - 5t

  // x + y = N - 2t
  // x >= 0     t >= N / 3     t > 2 + 1 / 3
  // y >= 0     t <= 2N / 5    t < 3.2
  
  int t = 2 * N / 5;

  printf("%d %d", -N + 3 * t, 2 * N - 5 * t);

  return EXIT_SUCCESS;
}
