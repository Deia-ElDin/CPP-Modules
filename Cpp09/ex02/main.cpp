#include "PmergeMe.hpp"
#include "Utils.hpp"
#include <iostream>

int main(int ac, char** av) {
    if (ac < 2) {
        Utils::printErr("Error: Program requires at least one positive integer as argument");
        return 1;
    }

    PmergeMe sorter;
    
    try {
        if (!sorter.parseInput(ac, av)) 
            return 1;
        
        sorter.sortContainers();
        sorter.displayResults();
    } catch (const std::exception& e) {
        Utils::printErr(Utils::toStr(e.what()));
        return 1;
    }

    return 0;
}


// to generate 3k different numbers => jot -r 3000 1 2147483647 | tr '\n' ' '