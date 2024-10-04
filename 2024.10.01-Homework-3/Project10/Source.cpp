#include <iostream>

int main( int argc, char *argv[] )
{
  int N = 0;

  scanf_s("%d", &N);

  int max_days = 0;
  int days = 0;

  for (int k = 0; k < N; ++k)
  {
    int t = 0;
    
    scanf_s("%d", &t);
    if (t <= 0)
    {
      if (days > max_days)
      {
        max_days = days;
      }
      days = 0;
    }
    else
    {
      days += 1;
    }
  }
  if (days > max_days)
  {
    max_days = days;
  }

  printf("%d\n", max_days);
  
  return EXIT_SUCCESS;
}