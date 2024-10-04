#include <iostream>

// 1 2 3 4 5 6 7  8
// 1 1 2 3 5 8 13 21
// 21 = 13 + 8 = 2 * 8 + 5 = 2 * 3 + 3 * 5 = 3 * ()
// F(i) = 
//    F(i - 1) + F(i - 2) = 
//    F(2) * (F(i - 2) + F(i - 3)) + F(1) * F(i - 2) = 
// 
//    F(3) * F(i - 2) + F(2) * F(i - 3) = 
//    F(3) * (F(i - 3) + F(i - 4)) + F(2) * F(i - 3) = 
// 
//    F(4) * F(i - 3) + F(3) * F(i - 4)        . . . =
//    F(j + 1) * F(i - j) + F(j) * F(i - j - 1)
// 
// F(i + j) = 
//    F(j + 1) * F(i) + F(j) * F(i - 1)
// 
// gcd(F(i), F(i + j)) = 
//    gdc(F(i), F() * F(i) + F() * F(i + 1)) = 
//    gdc(F(i), F(j + 1) * F(i) + F(j) * F(i - 1)) = 
//    gdc(F(i), F(j) * F(i - 1)) = 
//    gdc(F(i - 1) + F(i - 2), F(j) * F(i - 1)) = 
//    gdc(F(i - 1) + F(i - 2), F(j) * F(i - 2)) = 
// 
// Fi = F(i - 1) + F(i - 2)
// gcd(Fi, F(i + j)) = 
// 14 = 5 * 2 + 4
// 5 = 4 * 1 + 1
// 4 = 1 * 4 + 0

int main( int argc, char *argv[] )
{
  int i = 0;
  int j = 0;

  scanf_s("%d", &i);
  scanf_s("%d", &j);

  int a = i;
  int b = j;

  if (a < b)
  {
    int tmp = a;

    a = b;
    b = tmp;
  }

  int gcd = b;
  int r = a % b;
  
  while (r != 0)
  {
    int r3 = gcd % r;
    
    gcd = r;
    r = r3;
  }

  int fi = 1;
  int fi1 = 1;

  for (int k = 2; k < gcd; ++k)
  {
    int tmpf = fi;

    fi = (fi + fi1) % 1000000000;
    fi1 = tmpf;
  }

  printf("%d\n", fi);
  
  return EXIT_SUCCESS;
}