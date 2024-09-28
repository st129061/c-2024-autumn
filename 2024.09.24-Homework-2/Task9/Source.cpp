#include <iostream>

int main( int argc, char * argv[] )
{
  int K = 0;
  int W = 0;

  scanf_s("%d", &K);
  scanf_s("%d", &W);
  
  int a1 = 0;
  int b1 = 0;
  int a2 = 0;
  int b2 = 0;
  int a3 = 0;
  int b3 = 0;

  scanf_s("%d", &a1);
  scanf_s("%d", &b1);
  scanf_s("%d", &a2);
  scanf_s("%d", &b2);
  scanf_s("%d", &a3);
  scanf_s("%d", &b3);
  
  int w1 = a1;
  int w2 = a2;
  int w3 = a3;
  int w4 = a1 + a2;
  int w5 = a2 + a3;
  int w6 = a1 + a3;
  int w7 = a1 + a2 + a3;
  
  int k1 = b1;
  int k2 = b2;
  int k3 = b3;
  int k4 = b1 + b2;
  int k5 = b2 + b3;
  int k6 = b1 + b3;
  int k7 = b1 + b2 + b3;

  if (
    w1 <= W && k1 >= K ||
    w2 <= W && k2 >= K ||
    w3 <= W && k3 >= K ||
    w4 <= W && k4 >= K ||
    w5 <= W && k5 >= K ||
    w6 <= W && k6 >= K ||
    w7 <= W && k7 >= K
    )
  {
    printf("YES");
  }
  else
  {
    printf("NO");
  }


  return EXIT_SUCCESS;
}
