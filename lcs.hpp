/***************************************************************
  Student Name: Ari Palanjian
  File Name: lcs.hpp
  Project 5

  Defines the class LCS which calculates the lowest common
    subsequence three ways:
        1)Space Saving - use two arrays to calculate the lcs
            by swapping the previously calulated row with the
            current row, but this only allows you to find the 
            maximum length
        2)Basic - Uses two, 2-dimensional arrays, one to hold
            the lcs at a given index of i and j and another to
            hold the traversal direction to reconstruct the lcs
        3)Advanced Basic - Uses 1 2-dimensional array to calculate
            the lcs, the subsequence is reconstucted using 
            recursion and evaluating the position above and to
            the left of the current index.
***************************************************************/
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

    int getMax(){return max;}
    void printC(){c->print();}
};

#endif