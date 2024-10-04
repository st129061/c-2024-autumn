#include <iostream>

int main( int argc, char *argv[] )
{
  int N = 0;
  int ans_number = 0;

  scanf_s("%d", &N);

  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      int is_road = 0;
      scanf_s("%d", &is_road);

      if (is_road == 1)
      {
        if (i == j)
        {
          ans_number += 2;
        }
        else
        {
          ans_number += 1;
        }
      }
    }
  }

  printf("%d\n", ans_number / 2);
  
  return EXIT_SUCCESS;
}