#ifndef LCS_HPP
#define LCS_HPP

#include "matrix.hpp"
#include <string>

#define DIAG 0
#define UP 1
#define LEFT -1

class LCS{
    int m; //num rows
    int n; //num cols

    //Strings being compared
    std::string s1;
    std::string s2;

    //used in space saving
    int* row1;
    int* row2;

    Matrix* c;
    Matrix* b; //diagonal = 0, up = 1, left = -1

    int max;

public:
    LCS(std::string s1, std::string s2);
    LCS(const LCS& copy);
    ~LCS();
    LCS& operator=(const LCS& copy);

    int spaceSaving();
    void basic();
    void advBasic();

    int getLCSLen(){return max;}
    std::string getLCSConly(int i, int j);

    void printC(){c->print();}
};

#endif