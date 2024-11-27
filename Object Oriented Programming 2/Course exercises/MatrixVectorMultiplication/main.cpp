#include <iostream>

using namespace std;

int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int vector[] = {2, 1, 3};
    int expectedResult[] = {13, 31, 49};
    int calculatedResult[3] = {0};

    // perform the matrix and vector multiplication
    for(int row = 0; row < sizeof(matrix)/sizeof(matrix[0]); row++)
    {
        for(int col = 0; col < sizeof(matrix[0]) / sizeof(matrix[0][0]); col++)
        {
            calculatedResult[row] += matrix[row][col] * vector[col];
        }
    }

    // check now the elements with expected elements
    bool allOK = true;
    for(int i = 0; i < sizeof(expectedResult)/sizeof(expectedResult[0]); i++)
    {
        if(calculatedResult[i] != expectedResult[i])
        {
            allOK = false;
        }
    }

    if(allOK)
    {
        cout << "The calculated and expected arrays are equal. Congratulations!" << endl;
    }
    else
    {
        cout << "The calculated and expected arrays are not equal. There's a mistake!" << endl;
    }

    return 0;
}