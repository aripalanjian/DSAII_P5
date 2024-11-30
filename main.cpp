#include <fstream>
#include <iostream>
#include <string.h>
#include "lcs.hpp"
#include <cmath>

bool debug = false;

template <typename T>
void printM(int m, int n, T** arr){
    std::cout << "   ";
    for(int i = 0; i < n; i++){
        std::cout << "0" << i+1 << " ";
    }
    std::cout << "\n";
    for(int i = 0; i < m; i++){
        std::cout << "0" << i+1 << "  ";
        for(int j = 0; j < n; j++){
            std::cout << arr[i][j] << "  ";
        }
        std::cout << "\n";
    }
}

char calculateSimilarity(std::string s1, std::string s2, int lenLCS){
    std::string longer, shorter;
    if (s1.size() > s2.size()){
        longer = s1;
        shorter = s2;
    } else {
        longer = s2;
        shorter = s1;
    }

    char val;
    std::cout << "longer: " << longer.size() << ", shorter: " << shorter.size() << ", len LCS: " << lenLCS;
    double strLenComp = fabs(longer.size()-shorter.size())/longer.size();
    double lcsComp = fabs(shorter.size() - lenLCS) / shorter.size();
    std::cout << " strLenComp: " << strLenComp << ", lcsComp: " << lcsComp;

    if( strLenComp <= .1 && lcsComp <= .1 ) {        
        val = 'H';
    } else if (strLenComp <= .2 && lcsComp <= .2 ) {
        val = 'M';
    } else if (strLenComp <= .4 && lcsComp <= .5 ) {
        val = 'L';
    } else {
        val = 'D';
    }

    std::cout << ", val: " << val  << "\n";

    return val;
}

void runPart2(int count, char** similarity, int& firstStrLoc, std::ifstream& f2, std::string& s1, std::string& s2){
    for(int i = 0; i < count; i++){
            similarity[i] = new char[count];
        }

        //Fill Diagonal and lower triangle with '-'s
        for(int i = 0; i < count; i++){
            for(int j = 0; j < count; j++){
                similarity[i][j] = '-';
            }
        }
        for(int i = 0; i < count - 1; i++){        
            f2.seekg(firstStrLoc, std::ios::beg);
            std::getline(f2, s1);
            firstStrLoc = f2.tellg();
            for (int j = i + 1; j < count; j++){
                if(f2.tellg() != -1){                
                    f2.seekg(0, std::ios::cur);
                    std::getline(f2,s2);
                    // std::cout << "s1: " << s1 << ", s2: " << s2 << "\n";
                    LCS part2(s1,s2);
                    std::cout << "[" << i+1 << "][" << j+1 << "] ";
                    similarity[i][j] = calculateSimilarity(s1,s2,part2.spaceSaving());
                }
            }

            f2.clear();
        }
}

int main(int argC, char** argV){
    if (argC > 1){
        for(int i = 1; i < argC; i++){
            if(strcmp("-d",argV[i]) == 0 || strcmp("-debug",argV[i]) == 0){
                debug = true;
            }
        }
    }

    const char* fileTwoStrings = "twoStrings.txt";
    const char* fileMultiStrings = "multiStrings.txt";

    std::ifstream f1(fileTwoStrings);
    std::string s1;
    std::string s2;
    f1 >> s1;
    f1 >> s2;
    f1.close();

    if (debug){
        LCS test1("aaabaaa","aabbaca");
        test1.advBasic();
        test1.printC();
        std::cout << test1.getLCSConly(7,7) << "\n";
    } 
    LCS part1(s1,s2);
    part1.advBasic();
    std::cout << "s1: " << s1 << "\ns2: " << s2 << "\n";
    std::cout << part1.getLCSConly(s1.size()+1,s2.size()+1) << "\n";

    std::ifstream f2(fileMultiStrings);

    std::string tmp;
    //Get String count from file
    std::getline(f2, tmp);
    int count = std::stoi(tmp);
    int firstStrLoc = f2.tellg();

    if (debug){
        //Display strings in file using random access
        for(int i = 0; i < count; i++){
            f2.seekg(0, std::ios::cur);
            std::cout << i+1 << ": byte location: " << f2.tellg();
            std::getline(f2, tmp);
            std::cout << ", value: " << tmp << "\n";
        }
        //Reset flags and change current position to location of the first string
        f2.clear();
    }

    
    char** similarity = new char*[count];
    runPart2(count, similarity, firstStrLoc, f2, s1, s2);

    printM(count, count, similarity);
    for(int i = 0; i < count; i++){
        delete[] similarity[i];
    }
    delete [] similarity;


    //Close f2
    f2.close();

    return 0;
}