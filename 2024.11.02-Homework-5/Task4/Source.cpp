
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
    int eq = 1;

    for (int i = 0; i < n; ++i)
    {
        if (*(m + i) > 0)
        {
            sum += *(m + i);
        }
    }
    
    int min = 0;
    int max = 0;
    for (int i = 0; i < n; ++i)
    {
        if (*(m + i) > *(m + max))
        {
            max = i;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (*(m + i) < *(m + min))
        {
            min = i;
        }
    }
    if (min > max)
    {
        int tmp = min;
        min = max;
        max = tmp;
    }
    for (int i = min + 1; i < max; ++i)
    {
        eq *= *(m + i);
    }
        
    printf("%d %d", sum, eq);
    
    free(m);

    return EXIT_SUCCESS;
}