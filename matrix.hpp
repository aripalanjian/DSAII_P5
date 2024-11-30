/***************************************************************
  Student Name: Ari Palanjian
  File Name: matrix.hpp
  Project 5

  Defines the class Matrix which is a 2-dimensional array holding
    integer values that describe the longest common subsequence
    at a given index i and j.
***************************************************************/
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