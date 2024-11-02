
#include <algorithm>
#include <iostream>

int main( int argc, char * argv )
{
    int * mass1 = NULL;
    int * mass2 = NULL;
    int n = 0;
    int m = 0;

    scanf_s("%d", &n);
    scanf_s("%d", &m);

    mass1 = (int *)malloc(sizeof(int) * n);
    mass2 = (int *)malloc(sizeof(int) * m);

    if (!mass1 || !mass2)
    {
        return EXIT_FAILURE;
    }

    int tmp = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf_s("%d", mass1 + i);
    }
    
    tmp = 0;
    for (int i = 0; i < m; ++i)
    {
        scanf_s("%d", mass2 + i);
    }

    std::sort(mass1, mass1 + n);
    std::sort(mass2, mass2 + m);
    
    int index1 = 0;
    int index2 = 0;
    int i = 0;
    int j = 0;

    while (index1 < n)
    {
        while (*(mass1 + index1) > *(mass2 + j))
            j += 1;
        index2 = j;
        
        if (*(mass1 + index1) == *(mass2 + index2))
        {
            printf("%d ", *(mass1 + index1));
        }
        // while (*(mass2 + index2) == *(mass2 + j))

        while (i < n && *(mass1 + index1) == *(mass1 + i))
            i += 1;
        index1 = i;
    }

    free(mass1);
    free(mass2);

    return EXIT_SUCCESS;
}