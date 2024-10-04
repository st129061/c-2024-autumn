#include <iostream>

int main( int argc, char *argv[] )
{
  int N = 0;
  int ans_number = -1;
  int max_age = 0;

  scanf_s("%d", &N);

  for (int i = 0; i < N; ++i)
  {
    int age = 0;
    int sex = 0;
    scanf_s("%d", &age);
    scanf_s("%d", &sex);

    if (sex == 1 && max_age < age)
    {
      max_age = age;
      ans_number = i + 1;
    }
  }

  if (ans_number == -1)
  {
    printf("-1");
  }
  else
  {
    printf("%d\n", ans_number);
  }
  
  return EXIT_SUCCESS;
}