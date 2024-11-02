
#include <iostream>

int main( int argc, char * argv )
{
    int * m = NULL;
    int n = 0;

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

    int min = 0;
    for (int i = 0; i < n; ++i)
    {
        if (*(m + min) > *(m + i))
            min = i;
    }

    for (int i = min; i < n; i++)
    {
        printf("%d ", *(m + i));
    }
    for (int i = 0; i < min; i++)
    {
        printf("%d ", *(m + i));
    }

    free(m);

    return EXIT_SUCCESS;
}