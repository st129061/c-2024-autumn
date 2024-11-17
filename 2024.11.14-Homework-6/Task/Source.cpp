#include <iostream>
#include <random>

int * CreateIntArray( unsigned int * len );
void DestroyIntArray( int ** array, unsigned int * len );

void ResizeIntArray( int ** array, unsigned int * len, unsigned int new_len );

void PushFrontIntArray( int ** array, unsigned int * len, int new_element );
void PushBackIntArray( int ** array, unsigned int * len, int new_element );
int PopFrontIntArray( int ** array, unsigned int * len );
int PopBackIntArray( int ** array, unsigned int * len );

void PrintIntArray( int * array, unsigned int len );

void FillRandomIntArray( int * a, int len, int min = 0, int max = 9 );

void PrintMenu( void )
{
    system("cls");
    std::cout
        << "0 exit - exit\n"
        << "1 create array\n"
        << "2 destroy array\n"
        << "3 push front array\n"
        << "4 push back to array\n"
        << "5 pop front from array\n"
        << "6 pop back from array\n"
        << "7 fill random";
}

int main( int argc, char * argv )
{
    int * array = NULL;
    unsigned int len = 0;
    unsigned int choice;
    bool flag = true;

    while (flag)
    {
        PrintMenu();
        std::cout << "\nArray: \n";
        PrintIntArray(array, len);
        std::cout << "\n> ";
        std::cin >> choice;

        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
        case 0:
        {
            flag = false;
            break;
        }
        case 1:
        {
            DestroyIntArray(&array, &len);
            std::cout << "Input len: ";
            std::cin >> len;
            array = CreateIntArray(&len);
            break;
        }
        case 2:
        {
            DestroyIntArray(&array, &len);
            break;
        }
        case 3:
        {
            int element;
            std::cout << "Intput element: ";
            std::cin >> element;
            PushFrontIntArray(&array, &len, element);
            break;
        }
        case 4:
        {
            int element;
            std::cout << "Intput element: ";
            std::cin >> element;
            PushBackIntArray(&array, &len, element);
            break;
        }
        case 5:
        {
            PopFrontIntArray(&array, &len);
            break;
        }
        case 6:
        {
            PopBackIntArray(&array, &len);
            break;
        }
        case 7:
        {
            int element1 = 0;
            int element2 = 0;

            std::cout << "Intput element min: ";
            std::cin >> element1;
            std::cout << "Intput element max: ";
            std::cin >> element2;

            FillRandomIntArray(array, len, element1, element2);
            break;
        }
        }
    }

    DestroyIntArray(&array, &len);

    return EXIT_SUCCESS;
}

int * CreateIntArray( unsigned int * len )
{
    int * array = NULL;

    if (*len > 0)
    {
        array = (int *)malloc(sizeof(int) * *len);
    }
    if (array != NULL)
    {
        for (unsigned int i = 0; i < *len; ++i)
        {
            array[i] = 0;
        }
    }
    else
    {
        *len = 0;
    }

    return array;
}
void DestroyIntArray( int ** array, unsigned int * len )
{
    free(*array);
    *array = NULL;
    *len = 0;
}

void ResizeIntArray( int ** array, unsigned int * len, unsigned int new_len )
{
    int * new_array = CreateIntArray(&new_len);

    for (unsigned int i = 0; i < *len && i < new_len; ++i)
    {
        new_array[i] = (*array)[i];
    }
    DestroyIntArray(array, len);
    *len = new_len;
    *array = new_array;
}

void PushFrontIntArray( int ** array, unsigned int * len, int new_element )
{
    unsigned int new_len = *len + 1;
    int * new_array = CreateIntArray(&new_len);

    for (unsigned int i = 1; i < new_len; ++i)
    {
        new_array[i] = (*array)[i - 1];
    }
    if (new_len > 0)
    {
        new_array[0] = new_element;
    }
    DestroyIntArray(array, len);
    *len = new_len;
    *array = new_array;
}
void PushBackIntArray( int ** array, unsigned int * len, int new_element )
{
    unsigned int new_len = *len + 1;
    ResizeIntArray(array, len, new_len);
    if (*len > 0)
    {
        (*array)[*len - 1] = new_element;
    }
}
int PopFrontIntArray( int ** array, unsigned int * len )
{
    int save_value = 0;
    
    if (*len > 0)
    {
        unsigned int new_len = *len - 1;
        int * new_array = CreateIntArray(&new_len);

        for (unsigned int i = 0; i < new_len; ++i)
        {
            new_array[i] = (*array)[i + 1];
        }
        if (*len > 0)
        {
            save_value = (*array)[*len - 1];
        }
        DestroyIntArray(array, len);
        *len = new_len;
        *array = new_array;
    }
    
    return save_value;
}
int PopBackIntArray( int ** array, unsigned int * len )
{
    int save_value = 0;
    if (*len > 0)
    {
        unsigned int new_len = *len - 1;

        if (*len > 0)
        {
            save_value = (*array)[*len - 1];
        }
        ResizeIntArray(array, len, new_len);
    }

    return save_value;
}

void PrintIntArray( int * array, unsigned int len )
{
    if (array == NULL)
    {
        std::cout << "none";
    }
    else
    {
        for (unsigned int i = 0; i < len; ++i)
        {
            std::cout << array[i] << " ";
        }
    }
}

void FillRandomIntArray( int * a, int len, int min, int max )
{
    for (int i = 0; i < len; ++i)
    {
        a[i] = rand() % (max - min + 1) + min;
    }
}
