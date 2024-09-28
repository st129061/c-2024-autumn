#include <iostream>
#include <stdlib.h>

int main( int argc, char * argv[] )
{
  int l1 = 0;
  int w1 = 0;
  int h1 = 0;
  int l2 = 0;
  int w2 = 0;
  int h2 = 0;
  int l3 = 0;
  int w3 = 0;
  int h3 = 0;

  scanf_s("%d", &l1);
  scanf_s("%d", &w1);
  scanf_s("%d", &h1);
  scanf_s("%d", &l2);
  scanf_s("%d", &w2);
  scanf_s("%d", &h2);
  scanf_s("%d", &l3);
  scanf_s("%d", &w3);
  scanf_s("%d", &h3);
  
  int maxl = std::max(l1, l2);
  int maxw = std::max(w1, w2);
  int maxh = std::max(h1, h2);

  int res_l_1_l = l1 + l2;
  int res_w_1_l = std::max(w1, w2);
  int res_l_2_l = l1 + w2;
  int res_w_2_l = std::max(w1, l2);
  int res_l_3_l = w1 + l2;
  int res_w_3_l = std::max(l1, w2);
  int res_l_4_l = w1 + w2;
  int res_w_4_l = std::max(l1, l2);

  int res_l_1_w = std::max(l1, l2);
  int res_w_1_w = w1 + w2;
  int res_l_2_w = std::max(l1, w2);
  int res_w_2_w = w1 + l2;
  int res_l_3_w = std::max(w1, l2);
  int res_w_3_w = l1 + w2;
  int res_l_4_w = std::max(w1, w2);
  int res_w_4_w = l1 + l2;

  if (maxh <= h3)
  {
    if (
      res_l_1_l <= l3 && res_w_1_l <= w3 ||
      res_l_2_l <= l3 && res_w_2_l <= w3 ||
      res_l_3_l <= l3 && res_w_3_l <= w3 ||
      res_l_4_l <= l3 && res_w_4_l <= w3 ||

      res_l_1_w <= l3 && res_w_1_w <= w3 ||
      res_l_2_w <= l3 && res_w_2_w <= w3 ||
      res_l_3_w <= l3 && res_w_3_w <= w3 ||
      res_l_4_w <= l3 && res_w_4_w <= w3
      )
    {
      printf("YES");
    }
    else if (h1 + h2 <= h3 && (
      (w1 <= w3 && l1 <= l3 || w1 <= l3 && l1 <= w3) &&
      (w2 <= w3 && l2 <= l3 || w2 <= l3 && l2 <= w3)))
    {
      printf("YES");
    }
    else
    {
      printf("NO");
    }
  }
  else
  {
    printf("NO");
  }
  
  return EXIT_SUCCESS;
}
