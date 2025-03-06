#include<iostream>

class ArrayList
{ //абстракци€, инкапсул€ци€
private:
    int len;
    int* data;

    void init(int len = 10)
    {
        if (len <= 0)
        {
            throw;
        }
        this->len = len;
        this->data = (int*)malloc(sizeof(int) * len);

        if (!this->data)
        {
            throw;
        }
    }
    bool indexValid(int index)
    {
        return 0 <= index < this->len;
    }
    void expand( int new_len )
    {
        clear();
        if (new_len <= 0)
        {
            init(new_len);
        }
    }

public:
    ArrayList(int len = 10)
    {
        this->init(len);
        for (int i = 0; i < this->len; ++i)
        {
            this->data[i] = 0;
        }
    }
    ArrayList(ArrayList& list)
    {
        //this->len = list.len;
        //this->data = list.data;
        this->init(list.len);
        for (int i = 0; i < list.len; ++i)
        {
            this->set(i, list.get(i));
        }
    }
    ~ArrayList()
    {
        clear();
    }

    void clear( void )
    {
        free(this->data);
        this->len = 0;
    }

    void randomize(int min = 10, int max = 99)
    {
        for (int i = 0; i < len; ++i)
        {
            this->data[i] = rand() % (max - min + 1) + min;
        }
    }
    void print()
    {
        for (int i = 0; i < this->len; ++i)
        {
            printf("%d ", this->data[i]);
        }
        printf("\n");
    }
    int get(int index)
    {
        if (indexValid(index))
        {
            return this->data[index];
        }
        return -1;
    }
    void set(int index, int value)
    {
        if (indexValid(index))
        {
            this->data[index] = value;
        }
    }
    int count()
    {
        return len;
    }

    /* Copy element from another list with ofset */
    void copyElement_dumb( ArrayList &copy_list, int copy_offset, int copy_len, int this_offset = 0 )
    {
        if (this_offset + copy_len > this->len || copy_offset + copy_len > copy_list.len)
        {
            throw;
        }
        // 0 1 2
        //     ^
        // ^ 
        int i = copy_offset;
        int j = this_offset;

        while (copy_len > 0)
        {
            this->data[j] = copy_list.data[i];
            ++i;
            ++j;
            --copy_len;
        }
    }

    /* Copy element from another list with ofset */
    void copyElement( ArrayList &copy_list, int copy_offset, int copy_len, int this_offset = 0 )
    {
        if (this_offset < 0)
        {
            this_offset = this->len + this_offset;
        }
        
        if (copy_offset < 0)
        {
            copy_offset = copy_list.len + copy_offset;
        }
        copyElement_dumb(copy_list, copy_offset, copy_len, this_offset);
    }

    void move( ArrayList &copy_list )
    {
        clear();
        this->len = copy_list.len;
        this->data = copy_list.data;

        copy_list.len = 0;
        copy_list.data = nullptr;
    }

    void pushBack(int element)
    {
        ArrayList copy_list(this->len + 1);
        
        copy_list.copyElement(*this, 0, this->len, 0);
        
        copy_list.insert(copy_list.len, element);
        
        move(copy_list);
    }
    void pushFront(int element)
    {
        ArrayList copy_list(this->len + 1);
        
        copy_list.copyElement(*this, 0, this->len, 1);
        
        copy_list.insert(0, element);
        
        move(copy_list);
    }
    void insert(int index, int element)
    {
        if (!indexValid(index))
        {
            throw;
        }
        this->data[index] = element;
    }
    int popBack()
    {
        ArrayList copy_list(this->len - 1);

        copy_list.copyElement(*this, 0, this->len - 1, 0);
        
        move(copy_list);
    }
    int popFront()
    {
        ArrayList copy_list(this->len - 1);

        copy_list.copyElement(*this, 1, this->len - 1, 0);
        
        move(copy_list);
    }
    int extract(int index)
    {
        ArrayList copy_list(this->len - 1);

        // 0 1 2 3 4 
        // ^ ^   ^ ^ ^ ^
        copy_list.copyElement(*this, 0, index, 0);
        copy_list.copyElement(*this, index + 1, this->len - index - 1, 0);
        
        move(copy_list);
    }
    void reverse(int start, int end)
    {
        int reverse_len = start - end;

        if (reverse_len < 0 || end >= this->len)
        {
            throw;
        }
        for (int i = 0; i < reverse_len / 2; ++i)
        {
            int tmp = this->data[start + i];
            this->data[start + i] = this->data[start + reverse_len - i - 1];
            this->data[start + reverse_len - i - 1] = tmp;
        }
    }
    int sum()
    {
        int res = 0;
        for (int i = 0; i < this->len; ++i)
        {
            res += this->data[i];
        }

        return res;
    }
    /// <summary>
    /// ¬торой по величине элемент
    /// </summary>
    int secondMax()
    {
        if (this->len <= 0)
        {
            return -1;
        }

        int max_1 = this->data[0];
        int max_2 = this->data[0];

        for (int i = 0; i < this->len; ++i)
        {
            if (max_1 < this->data[i])
            {
                max_1 = this->data[i];
            }
        }
        for (int i = 0; i < this->len; ++i)
        {
            if (max_2 < this->data[i] && this->data[i] != max_1)
            {
                max_2 = this->data[i];
            }
        }

        return max_2;
    }
    /// <summary>
    /// индекс последнего минимального элемента
    /// </summary>
    int lastMinIndex()
    {
        if (this->len <= 0)
        {
            return -1;
        }

        int min_index = 0;

        for (int i = 0; i < this->len; ++i)
        {
            if (this->data[min_index] > this->data[i])
            {
                min_index = i;
            }
        }

    }
    /// <summary>
    /// сместить на k элементов вправо
    /// </summary>
    int shift(int k)
    {
        // 1 2 3 4 5 6
        //       ^
        // 4 5 6 1 2 3
        
        // 1 2 3 4 5 6
        //         ^
        // 5 6 1 2 3 4
        if (k <= 0)
        {
            throw;
        }

        ArrayList tmp(abs(k));

        tmp.copyElement(*this, 0, k, 0);
        this->copyElement(*this, k, this->len - k, 0);
        this->copyElement(tmp, this->len - k, k, 0);
    }
    /// <summary>
    /// количество нечетных
    /// </summary>
    int countOdd()
    {            
        int sum = 0;
        for (int i = 0; i < this->len; ++i)
        {
            if (this->data[i] % 2 == 1)
            {
                sum += this->data[i];
            }
        }
        return sum;
    }
    /// <summary>
    /// сумма четных элементов
    /// </summary>
    int sumEven()
    {
        int sum = 0;
        for (int i = 0; i < this->len; ++i)
        {
            if (this->data[i] % 2 == 0)
            {
                sum += this->data[i];
            }
        }
        return sum;
    }
};

int max(ArrayList list)
{
    int mx = list.get(0);
    for (int i = 0; i < list.count(); ++i)
    {
        mx = (mx > list.get(i) ? mx : list.get(i));
    }
    return mx;
}

int main(int argc, char* argv[])
{
    ArrayList list(10);
    list.randomize();
    list.print();
    printf("%d\n", max(list));
    return 0;
}