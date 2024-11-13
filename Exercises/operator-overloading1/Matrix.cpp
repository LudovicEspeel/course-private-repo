#include "Matrix.h"
#include <sstream>
#include <iostream>
#include <cstring> 

Matrix::Matrix(int *matrix, int rowSize, int colSize) : rowSize(rowSize), colSize(colSize)
{
    this->matrix = new int[rowSize * colSize];
    copy(matrix, matrix + rowSize * colSize, this->matrix); // Copy element-by-element from matrix to this->matrix
}

// start vraag
Matrix::~Matrix()
{
    delete[] this->matrix;
}
// einde vraag

int Matrix::getElement(int row, int col) const
{
    return *(matrix + row * rowSize + col);
}

// start vraag
Matrix Matrix::operator+(const Matrix &matrix)
{
// einde vraag
    // ...
    // Each overload function will start with this line:
    int result[rowSize][colSize] = {{ 0 }};
    // Remark: sometimes the array won't be properly initialized to 0's, then initialize the elements manually on 0
    // in a loop or use the function memset(result, 0, sizeof(result)); (--> #include <cstring> needed)
    // ...
    // start vraag
    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
           result[i][j] = getElement(i, j) + matrix.getElement(i, j);
        }
    }
    // einde vraag
    // ...
    // And end with this line:
    return Matrix(&result[0][0], rowSize, colSize);

// start vraag
}
// einde vraag

// start vraag
Matrix Matrix::operator-(const Matrix &matrix)
{
    int result[rowSize][colSize] = {{ 0 }};

    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
           result[i][j] = getElement(i, j) - matrix.getElement(i, j);
        }
    }

    return Matrix(&result[0][0], rowSize, colSize);
}

Matrix operator*(int scalar, const Matrix &matrix1)
{
    return matrix1.scalarMultiplication(scalar);
}

Matrix operator*(const Matrix &matrix1, int scalar)
{
    return matrix1.scalarMultiplication(scalar);
}

Matrix operator*(const Matrix &matrix1, const Matrix &matrix2)
{
    int result[matrix1.rowSize][matrix2.colSize] = {{ 0 }}; // doen't init competely to 0?!
    memset(result, 0, sizeof(result));

    for(int row = 0; row < matrix1.rowSize; row++)
    {
        for(int col = 0; col < matrix2.colSize; col++)
        {
            for(int k = 0; k < matrix1.colSize; k++)
            {
                result[row][col] += matrix1.getElement(row, k) * matrix2.getElement(k, col);
            }
        }
    }

    return Matrix(&result[0][0], matrix1.rowSize, matrix2.colSize);
}

Matrix Matrix::scalarMultiplication(int scalar) const
{
    int result[rowSize][colSize] = {{ 0 }};

    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
           result[i][j] = getElement(i, j) * scalar;
        }
    }

    return Matrix(&result[0][0], rowSize, colSize);
}
// einde vraag

string Matrix::getString() const
{
    stringstream ss;

    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
            ss << getElement(i, j) << "\t";
        }
        ss << endl;
    }

    return ss.str();
}