#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Matrix.h"

int main(int argc, char* argv[])
{
    Matrix matr(3);
    for (int i = 0; i < matr.getR(); ++i)
    {
        for (int j = 0; j < matr.getC(); ++j)
        {
            matr.set(i, j, 3 * i + j);
        }
    }
    matr.print(std::cout);
    std::cout << matr.det() << "\n";

    Matrix A(2);
    A.set(0, 0, 3);
    A.set(0, 1, 4);
    A.set(1, 0, 1);
    A.set(1, 1, 2);

    reverse(A).print(std::cout);

    Matrix B(3);
    B.set(0, 0, 1);
    B.set(0, 1, -2);
    B.set(0, 2, 3);
    B.set(1, 0, 0);
    B.set(1, 1, 4);
    B.set(1, 2, -1);
    B.set(2, 0, 5);
    B.set(2, 1, 0);
    B.set(2, 2, 1);

    Matrix BB = reverse(B);
    BB.multBy(B.det());
    BB.print(std::cout);

    Matrix C(2), D(2);

    C.set(0, 0, 3);
    C.set(0, 1, 5);
    C.set(1, 0, 1);
    C.set(1, 1, 2);

    D.set(0, 0, 4);
    D.set(0, 1, 1);
    D.set(1, 0, 3);
    D.set(1, 1, 1);

    solve(C, D).print(std::cout);
    
    /* Слово Hui используется и европейцами с 1846 года для обозначения собраний маори */
    Matrix HUI(3, 2);
    HUI.set(0, 0, 1);
    HUI.set(0, 1, -2);
    HUI.set(1, 0, 0);
    HUI.set(1, 1, 4);
    HUI.set(2, 0, 5);
    HUI.set(2, 1, 0);

    HUI.print(std::cout);
    transpose(HUI).print(std::cout);

    return 0;
}