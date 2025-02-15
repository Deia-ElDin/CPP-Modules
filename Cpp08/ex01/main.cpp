#include "Span.hpp"
#include "Utils.hpp"
#include <iostream>


int main() {
    {
        Utils::printTestTitle("Basic Test");

        Span sp(5);

        sp.getDefaultSize();
        sp.getActualSize();

        Utils::printMsg("Adding numbers...", "cyan");
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        sp.getDefaultSize();
        sp.getActualSize();

        Utils::printMsg("Shortest Span = " + Utils::toStr(sp.shortestSpan()), "green");
        Utils::printMsg("Longest Span  = " + Utils::toStr(sp.longestSpan()), "green");
    }

    Utils::printSeparator();

    {
        Utils::printTestTitle("Large Test (10,000 elements)");

        Span largeSp(10000);

        for (unsigned int i = 0; i < 10000; i++) 
            largeSp.addNumber(i);

        Utils::printMsg("Shortest Span = " + Utils::toStr(largeSp.shortestSpan()), "green");
        Utils::printMsg("Longest Span  = " + Utils::toStr(largeSp.longestSpan()), "green");
    }

    Utils::printSeparator();

    {
        Utils::printTestTitle("Testing _N");
        Span small(3);
        try {
            Utils::printMsg("Adding 3 numbers...", "cyan");
            small.addNumber(10);
            small.addNumber(20);
            small.addNumber(30);
            
            // This next call should throw since capacity is 3
            Utils::printMsg("Adding a 4th number...", "cyan");
            small.addNumber(40); 
        }
        catch (const std::exception &e) {
            Utils::printErr("Error: " + Utils::toStr(e.what()));
        }
    }

    Utils::printSeparator();
    
    {
        Utils::printTestTitle("Testing Not Enough Elements");

        Span empty(5);

        try {
            Utils::printMsg("Shortest Span = " + Utils::toStr(empty.shortestSpan()), "green");
        } 
        catch (const std::exception &e) {
            Utils::printErr("Error - empty: " + Utils::toStr(e.what()));
        }

        Utils::printMsg("Adding just one number...", "cyan");

        empty.addNumber(42);
        try {
            Utils::printMsg("Shortest Span = " + Utils::toStr(empty.shortestSpan()), "green");
        } 
        catch (const std::exception &e) {
            Utils::printErr("Error - one number: " + Utils::toStr(e.what()));
        }
    }

    return 0;
}
