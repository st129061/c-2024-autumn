#include <iostream>

int main( int argc, char *argv[] )
{
  int bridge_numbers = 0;
  int crash_bridge_number = -1;

  scanf_s("%d", &bridge_numbers);

  for (int i = 0; i < bridge_numbers; ++i)
  {
    int bridge_height = 0;
    scanf_s("%d", &bridge_height);

    if (bridge_height <= 437)
    {
      crash_bridge_number = i + 1;
      break;
    }
  }

  if (crash_bridge_number == -1)
  {
    printf("No crash\n");
  }
  else
  {
    printf("Crash %d\n", crash_bridge_number);
  }
  return EXIT_SUCCESS;
}