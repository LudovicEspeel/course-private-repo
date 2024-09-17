#pragma once
#include <string>

using namespace std;

// start vraag
// Class definition
class Matrix
{
    friend Matrix operator*(const Matrix &matrix1, const Matrix &matrix2);
    friend Matrix operator*(const Matrix &matrix1, int scalar);
    friend Matrix operator*(int scalar, const Matrix &matrix1);
    public:
        Matrix(int *matrix, int rowSize, int colSize);
        ~Matrix();
        int getElement(int row, int col) const;
        string getString() const;
        Matrix operator+(const Matrix &matrix);
        Matrix operator-(const Matrix &matrix);
    private:
        int *matrix;
        int rowSize;
        int colSize;
        Matrix scalarMultiplication(int scalar) const;
};
// einde vraag