#include <iostream>

// 1 1 4    1 * 2 + 2 * 1 + 1 - 1 + 1 - 1
// 2 2 16   2 * 3 + 2 * 3 + 2 + 2
// 4 3 38   4 * 4 + 3 * 5 + 4 + 3
// 3 3 28   3 * 4 + 3 * 4 + 3 - 1 + 3 - 1
// 4 4 48   4 * 5 + 4 * 5 + 4 + 4
// 5 3 44   5 * 4 + 3 * 6 + 5 + 3 - 1 - 1
// 5 5 68   5 * 6 + 5 * 6 + 5 - 1 + 5 - 1
// 
//

int main( int argc, char * argv[] )
{
  int n = 0;
  int m = 0;

  scanf_s("%d", &n);
  scanf_s("%d", &m);
  
  if (n == 1 || m == 1 || n % 2 == 1 && m % 2 == 1)
  {
    printf("%d", n * (m + 1) + m * (n + 1) + n + m - 2);
  }
  else
  {
    printf("%d", n * (m + 1) + m * (n + 1) + n + m);
  }

  return EXIT_SUCCESS;
}
