
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

    int odd = 0;
    int even = 0;

    for (int i = 0; i < n; ++i)
    {
        if (*(m + i) % 2 != 0)
        {
            printf("%d ", *(m + i));
            odd += 1;
        }
    }
    printf("\n");
    
    for (int i = 0; i < n; ++i)
    {
        if (*(m + i) % 2 == 0)
        {
            printf("%d ", *(m + i));
            even += 1;
        }
    }
    printf("\n");

    if (odd <= even)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    free(m);

    return EXIT_SUCCESS;
}