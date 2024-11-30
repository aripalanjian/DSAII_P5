#include "lcs.hpp"

LCS::LCS(std::string s1, std::string s2){
    m = s1.size() + 1;
    n = s2.size() + 1;

    this->s1 = s1;
    this->s2 = s2;

    this->row1 = nullptr;
    this->row2 = nullptr;

    c = nullptr;
    b = nullptr;

    max = 0;
}

LCS::LCS(const LCS& copy){
    this->m = copy.m;
    this->n = copy.n;

    this->s1 = copy.s1;
    this->s2 = copy.s2;

    this->row1 = copy.row1;
    this->row2 = copy.row2;

    this->c = copy.c;
    this->b = copy.b;

    this->max = copy.max;
}

LCS::~LCS(){
    if (row1 != nullptr){
        delete [] row1;
    }
    if (row2 != nullptr){
        delete [] row2;
    }
    if (c != nullptr) {
        delete c;
    }
    if (b != nullptr) {
        delete b;
    }

}

LCS& LCS::operator=(const LCS& copy){
    if (this != &copy){
        this->m = copy.m;
        this->n = copy.n;

        this->s1 = copy.s1;
        this->s2 = copy.s2;

        this->row1 = copy.row1;
        this->row2 = copy.row2;

        this->c = copy.c;
        this->b = copy.b;
    }

    return *this;
}

#include <iostream>
int LCS::spaceSaving(){
    row1 = new int[n];
    row2 = new int[n];
    for(int i = 0; i < n; i++){
        row1[i] = 0;
        row2[i] = 0;
    }

    for(int i = 1; i < m; i++){
        
        for (int j = 1; j < n; j++){
            if (s1[i-1] == s2[j-1]) {
                row2[j] = row1[j-1] + 1;
            } else {
                if (row1[j] >= row2[j-1]) {
                    row2[j] = row1[j];
                } else {
                    row2[j] = row2[j-1];
                }
            }
            if (row2[j] > max) {
                    max = row2[j];
            }
        }

        int* tmp = row1;
        row1 = row2;
        row2 = tmp;
    }

    return max;

}

void LCS::basic(){
    c = new Matrix(m,n);
    b = new Matrix(m,n);
    for(int i = 1; i < m; i++){
        for (int j = 1; j < n; j++){
            if (s1[i-1] == s2[j-1]) {
                c->setVal(i, j, c->getVal(i-1, j-1) + 1);
                b->setVal(i, j, DIAG);
            } else {
                if (c->getVal(i-1, j) >= c->getVal(i, j-1)) {
                    c->setVal(i, j, c->getVal(i-1, j));
                    b->setVal(i, j, UP);
                } else {
                    c->setVal(i, j, c->getVal(i, j-1));
                    b->setVal(i, j, LEFT);
                }
            }

            if (c->getVal(i,j) > max) {
                max = c->getVal(i,j);
            }

        }
    }
}

void LCS::advBasic(){
    c = new Matrix(m,n);
    for(int i = 1; i < m; i++){
        for (int j = 1; j < n; j++){
            if (s1[i-1] == s2[j-1]) {
                c->setVal(i, j, c->getVal(i-1, j-1) + 1);
            } else {
                if (c->getVal(i-1, j) >= c->getVal(i, j-1)) {
                    c->setVal(i, j, c->getVal(i-1, j));
                } else {
                    c->setVal(i, j, c->getVal(i, j-1));
                }
            }

            if (c->getVal(i,j) > max) {
                max = c->getVal(i,j);
            }

        }
    }
}

std::string LCS::getLCSConly(int i, int j){
    if(i == 0 || j == 0) {
        return "";
    } else if(s1[i-1] == s2[j-1]){
        return getLCSConly(i-1,j-1) + s1[i-1];
    } else if(c->getVal(i-1,j) >= c->getVal(i,j-1)){
        return getLCSConly(i-1,j);
    } else {
        return getLCSConly(i,j-1);
    }
}
