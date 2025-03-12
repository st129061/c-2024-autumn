#include"Matrix.h"

double** Matrix::createData(int rows, int cols)
{
    double** res = new double* [rows] { 0 };
    for (int i = 0; i < rows; ++i)
    {
        res[i] = new double[cols] { 0 };
    }
    return res;
}
void Matrix::freeData(double** data, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] data[i];
    }
    delete[] data;
}
Matrix::Matrix()
{
    this->rows = 1;
    this->cols = 1;
    this->data = createData(1, 1);
}
Matrix::Matrix(int dim)
{
    this->rows = dim;
    this->cols = dim;
    this->data = createData(dim, dim);
}
Matrix::Matrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    this->data = createData(rows, cols);
}
Matrix::Matrix(const Matrix& matr)
{
    this->rows = matr.rows;
    this->cols = matr.cols;
    this->data = createData(matr.rows, matr.cols);
    for (int i = 0; i < matr.rows; ++i)
    {
        for (int j = 0; j < matr.cols; ++j)
        {
            this->data[i][j] = matr.data[i][j];
        }
    }
}
Matrix::~Matrix()
{
    if (this->data != nullptr)
    {
        freeData(this->data, this->rows);
        this->data = nullptr;
        this->rows = 0;
        this->cols = 0;
    }
}
double Matrix::get(int row, int col)
{
    if (0 <= row && row <= this->rows &&
        0 <= col && col <= this->cols)
    {
        return this->data[row][col];
    }
    else
    {
        return -1;
    }
}
void Matrix::set(int row, int col, double val)
{
    if (0 <= row && row <= this->rows &&
        0 <= col && col <= this->cols)
    {
        this->data[row][col] = val;
    }
}
int Matrix::getR()
{
    return this->rows;
}
int Matrix::getC()
{
    return this->cols;
}
void Matrix::print(std::ostream& stream)
{
    stream << "[" << this->rows << "; " << this->cols << "]\n";
    for (int i = 0; i < this->rows; ++i)
    {
        stream << "\t";
        for (int j = 0; j < this->cols; ++j)
        {
            stream << this->data[i][j] << " ";
        }
        stream << "\n";
    }
}

void Matrix::multBy(double k)
{
    for (int i = 0; i < this->rows; ++i)
    {
        for (int j = 0; j < this->cols; ++j)
        {
            this->data[i][j] *= k;
        }
    }
}

void Matrix::addTo(Matrix matr)
{
    if (matr.rows == this->rows && matr.cols == this->cols)
    {
        for (int i = 0; i < this->rows; ++i)
        {
            for (int j = 0; j < this->cols; ++j)
            {
                this->data[i][j] += matr.data[i][j];
            }
        }
    }
}

double Matrix::det()
{
    if (this->rows > 0 && this->rows == this->cols)
    {
        int dim = this->rows;
        if (dim == 1)
        {
            return this->data[0][0];
        }
        double res = 0;
        for (int i = 0, mult = 1; i < dim; ++i, mult *= -1)
        {
            res += mult * this->data[0][i] * minor(0, i).det();
        }
        return res;
    }
    return 0.0;
}

Matrix Matrix::minor(int row, int col)
{
    if (this->rows > 1 &&
        this->rows == this->cols &&
        row < this->rows && col < this->cols)
    {
        int dim = this->rows - 1;
        Matrix res(dim);
        for (int i = 0, ii = 0; i < dim; ++i, ++ii)
        {
            if (ii == row)
            {
                ++ii;
            }
            for (int j = 0, jj = 0; j < dim; ++j, ++jj)
            {
                if (jj == col)
                {
                    ++jj;
                }
                res.data[i][j] = this->data[ii][jj];
            }
        }
        return res;
    }
    return Matrix();
}

Matrix mult(Matrix m1, Matrix m2)
{
    if (m1.cols == m2.rows)
    {
        Matrix res(m1.rows, m2.cols);
        for (int i = 0; i < res.rows; ++i)
        {
            for (int j = 0; j < res.cols; ++j)
            {
                res.data[i][j] = 0;
                for (int k = 0; k < m1.cols; ++k)
                {
                    res.data[i][j] += m1.data[i][k] * m2.data[k][j];
                }
            }
        }
        return res;
    }
    return Matrix();
}

void Matrix::transpose()
{
    if (this->rows == this->cols)
    {
        int dim = this->rows;
        for (int i = 0; i < dim; ++i)
        {
            for (int j = i + 1; j < dim; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                double tmp = this->data[i][j];
                this->data[i][j] = this->data[j][i];
                this->data[j][i] = tmp;
            }
        }
    }
    else
    {
        Matrix tmp(this->cols, this->rows);

        for (int i = 0; i < this->rows; ++i)
        {
            for (int j = 0; j < this->cols; ++j)
            {
                tmp.data[j][i] = this->data[i][j];
            }
        }

        

        freeData(this->data, this->rows);
        this->data = createData(tmp.rows, tmp.cols);

        
        this->rows = tmp.rows;
        this->cols = tmp.cols;

        for (int i = 0; i < this->rows; ++i)
        {
            for (int j = 0; j < this->cols; ++j)
            {
                this->data[i][j] = tmp.data[i][j];
            }
        }
    }
}

Matrix add(Matrix m1, Matrix m2)
{
    if (m1.rows == m2.rows && m1.cols == m2.cols)
    {
        Matrix res(m1.rows, m1.cols);

        for (int i = 0; i < m1.rows; ++i)
        {
            for (int j = 0; j < m1.cols; ++j)
            {
                res.data[i][j] = m1.data[i][j] + m2.data[i][j];
            }
        }
    }
    return Matrix();
}

Matrix transpose(Matrix m)
{
    m.transpose();

    return m;
}

Matrix subtr(Matrix m1, Matrix m2)
{
    m2.multBy(-1);
    return add(m1, m2);

    if (m1.rows == m2.rows && m1.cols == m2.cols)
    {
        Matrix res(m1.rows, m1.cols);

        for (int i = 0; i < m1.rows; ++i)
        {
            for (int j = 0; j < m1.cols; ++j)
            {
                res.data[i][j] = m1.data[i][j] - m2.data[i][j];
            }
        }
    }
    return Matrix();
}

Matrix reverse(Matrix m)
{
    double det = m.det();
    // det < 0.0000001 ?
    if (det != 0.0)
    {
        Matrix res(m.rows, m.cols);

        for (int i = 0; i < m.rows; ++i)
        {
            for (int j = 0; j < m.cols; ++j)
            {
                res.data[i][j] = m.minor(i, j).det() * (1 - (i + j) % 2 * 2);
            }
        }
        res.transpose();
        res.multBy(1 / det);

        return res;
    }
    
    return Matrix();
}

Matrix solve(Matrix A, Matrix B)
{
    // A * x = B
    // A^-1 * A * x = A^-1 * B
    return mult(reverse(A), B);
}