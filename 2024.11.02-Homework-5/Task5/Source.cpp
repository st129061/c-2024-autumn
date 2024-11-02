
#include <iostream>

int main( int argc, char * argv )
{
    int * m = NULL;
    int n = 0;
    int k = 0;

    scanf_s("%d", &n);

    m = (int *)malloc(sizeof(int) * n);

    if (!m)
    {
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; ++i)
    {
        scanf_s("%d", m + i);
    }

    int sum = 0;
    int days = 1;
    int max = *(m + n - 1);
    for (int i = n - 2; i >= 0; --i)
    {
        if (*(m + i) < max)
        {
            days += 1;
        }
        else
        {
            sum += max * days;
            days = 1;
            max = *(m + i);
        }
    }
    sum += max * days;

    printf("%d", sum);

    free(m);

    return EXIT_SUCCESS;
}