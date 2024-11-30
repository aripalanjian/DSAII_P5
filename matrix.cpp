#include "matrix.hpp"
#include <iostream>

Matrix::Matrix(){
    this->rows = 0;
    this->cols = 0;
}

Matrix::Matrix(int row, int col) {
    //Constructor for constructing a matrix of size m(rows) x n(columns)
    this->rows = row;
    this->cols = col;

    this->matrix = new int*[row];
    for(int i = 0; i < row; i++) {
        this->matrix[i] = new int[col];
        for(int j = 0; j < col; j++){
            matrix[i][j] = 0;
        }
        // if (i == 0) {
        //     for (int j = 0; j < col; j++){
        //         matrix[i][j] = 0;
        //     }
        // } else {
        //     matrix[i][0] = 0;
        // }
    }
}

Matrix::Matrix(const Matrix& copy){
    this->rows = copy.rows;
    this->cols = copy.cols;
    this->matrix = new int*[this->rows];
    for(int i = 0; i < this->rows; i++) {
        this->matrix[i] = new int[this->cols];
        for(int j = 0; j < this->cols; j++){
            this->matrix[i][j] = copy.matrix[i][j];
        }
    }

}

Matrix& Matrix::operator=(const Matrix& copy){
    if(this != &copy){    
        this->rows = copy.rows;
        this->cols = copy.cols;
        this->matrix = new int*[this->rows];
        for(int i = 0; i < this->rows; i++) {
            this->matrix[i] = new int[this->cols];
            for(int j = 0; j < this->cols; j++){
                this->matrix[i][j] = copy.matrix[i][j];
            }
        }
    }

    return *this;
}

Matrix::~Matrix(){
    for (int i = 0; i < rows; i++){
        delete [] matrix[i];
    }

    delete [] matrix;
}

void Matrix::print() {
    using std::cout;
    cout << "[\n";
    for (int i = 0; i < rows; i++) {
        cout << "\t";
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "]\n";
}