#include <iostream>
#include <stdlib.h>

int main( int argc, char * argv[] )
{
  int x1 = 0;
  int y1 = 0;
  int z1 = 0;
  int x2 = 0;
  int y2 = 0;
  int z2 = 0;

  scanf_s("%d", &x1);
  scanf_s("%d", &y1);
  scanf_s("%d", &z1);
  scanf_s("%d", &x2);
  scanf_s("%d", &y2);
  scanf_s("%d", &z2);
  
  int max1 = std::max(x1, std::max(y1, z1));
  int min1 = std::min(x1, std::min(y1, z1));
  int average1 = x1 + y1 + z1 - max1 - min1;
  int max2 = std::max(x2, std::max(y2, z2));
  int min2 = std::min(x2, std::min(y2, z2));
  int average2 = x2 + y2 + z2 - max2 - min2;

  if (max1 == max2 && average1 == average2 && min1 == min2)
  {
    printf("Boxes are equal");
  }
  else if (max1 >= max2 && average1 >= average2 && min1 >= min2)
  {
    printf("The first box is larger than the second one");
  }
  else if (max1 <= max2 && average1 <= average2 && min1 <= min2)
  {
    printf("The first box is smaller than the second one");
  }
  else
  {
    printf("Boxes are incomparable");
  }

  return EXIT_SUCCESS;
}
