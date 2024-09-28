#include <iostream>
#include <cmath>

int main( int argc, char * argv[] )
{
  int a = 0;
  int b = 0;
  int c = 0;

  scanf_s("%d", &a);
  scanf_s("%d", &b);
  scanf_s("%d", &c);
  
  if (a == 0)
  {
    if (b == 0)
    {
      if (c == 0)
      {
        printf("-1");
      }
      else
      {
        printf("0");
      }
    }
    else
    {
      double x0 = -(double)c / b;

      printf("1\n");
      printf("%f", x0);
    }
  }
  else
  {
    double D = b * b - 4.0 * a * c;

    if (D < 0)
    {
      printf("0");
    }
    else if (D == 0)
    {
      double x0 = -(double)b / (2.0 * a);

      printf("1\n");
      printf("%f", x0);
    }
    else
    {
      double x1 = (-(double)b - sqrt(D)) / (2.0 * a);
      double x2 = (-(double)b + sqrt(D)) / (2.0 * a);

      printf("2\n");
      printf("%f\n", x1);
      printf("%f", x2);
    }
  }
  
  return EXIT_SUCCESS;
}
