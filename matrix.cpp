#include "matrix.hpp"
#include <random>
#include <iostream>
#include <fstream>
#include <thread>

Matrix::Matrix(int n) {
    srand(clock());
    //Constructor for constructing a square matrix of size n x n
    matrix = new int*[n];
    for (int i = 0; i < n; i++){
        matrix[i] = new int[n];
    }
    this->rows = n;
    this->cols = n;
}
Matrix::Matrix(int row, int col) {
    //Constructor for constructing a matrix of size m(rows) x n(columns)
    srand(clock());
    matrix = new int*[row];
    for(int i = 0; i < row; i++) {
        matrix[i] = new int[col];
    }
    this->rows = row;
    this->cols = col;
}

Matrix::~Matrix(){
    for (int i = 0; i < rows; i++){
        delete [] matrix[i];
    }

    delete [] matrix;
}

void Matrix::setDataRand() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand()%9 + 1; //Random integer between 1-10
        }
    }
}

void Matrix::setDataFile(const char* file) {
    std::ifstream myFile(file);
    while(!myFile.eof()){        
        int i = 0;
        int j = 0;
        myFile >> matrix[i][j++];
        if (j == cols) {
            i++;
            j = 0;
        }
    }
    
}

Matrix* Matrix::multipy(const Matrix& rhs){
    if (this->cols == rhs.rows) {
        Matrix* result = new Matrix(this->rows, rhs.cols);
        for(int i = 0; i < this->rows; i++) {
            for (int k = 0; k < rhs.cols; k++) {
                for(int j = 0; j < rhs.rows; j++) {
                    result->matrix[i][k] += this->matrix[i][j] * rhs.matrix[j][k];
                }
            }
        }
        return result;
    } else {
        return NULL;
    }
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