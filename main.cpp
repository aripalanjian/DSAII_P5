/***************************************************************
  Student Name: Ari Palanjian
  File Name: main.cpp
  Project 5

  Initializes the driver program and evaluates command line
    options.
***************************************************************/
#include "geneseqsim.hpp"
#include <string.h>

int main(int argC, char** argV){
    bool debug = false;

    if (argC > 1){
        for(int i = 1; i < argC; i++){
            if(strcmp("-d",argV[i]) == 0 || strcmp("-debug",argV[i]) == 0){
                debug = true;
            }
        }
    }

    GeneSeqSim sim("twoStrings.txt", "multiStrings.txt", debug);
    sim.run();

    return 0;
}