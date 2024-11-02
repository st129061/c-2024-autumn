
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

    scanf_s("%d", &k);

    if (k > 0)
    {
        k = k % n;
    }
    else
    {
        k = n - ((-k) % n);
    }
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", *(m + (n - k + i) % n));
    }
    free(m);

    return EXIT_SUCCESS;
}