#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix{
    int** matrix;
	int rows;
	int cols;

public:
    Matrix();
    Matrix(int m, int n);
    Matrix(const Matrix& copy);
    Matrix& operator=(const Matrix& copy);
    ~Matrix();

    int getVal(int i, int j){return matrix[i][j];}
    void setVal(int i, int j, int val){this->matrix[i][j] = val;}
    void print();
};

#endif