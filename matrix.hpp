#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix{
    int** matrix;
	int rows;
	int cols;

public:
    Matrix(int n);
    Matrix(int m, int n);
    ~Matrix();
    void setDataRand();
    void setDataFile(const char* file);
    Matrix* multipy(const Matrix& rhs);
    void print();
};

#endif