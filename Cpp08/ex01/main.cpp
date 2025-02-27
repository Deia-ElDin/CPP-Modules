#include "Span.hpp"
#include "Utils.hpp"
#include <iostream>

void    testBasic(void);
void    testLarge(void);
void    testAddNumber(void);
void    testNotEnoughElements(void);

int main(void) {

    testBasic();
    testLarge();
    testAddNumber();
    testNotEnoughElements();

    return 0;
}



void    testBasic() {
    Utils::printTestTitle("Basic Test");

    Span sp(0);

    sp.getDefaultSize();
    sp.getActualSize();

    Utils::printMsg("Adding numbers...", "cyan");
    try {
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(11);
    }
    catch (const std::exception &e) {
        Utils::printErr("Error: " + Utils::toStr(e.what()));
    }

    sp.getDefaultSize();
    sp.getActualSize();

    try {
        Utils::printMsg("Shortest Span = " + Utils::toStr(sp.shortestSpan()), "green");
        Utils::printMsg("Longest Span  = " + Utils::toStr(sp.longestSpan()), "green");
    }
    catch (const std::exception &e) {
        Utils::printErr("Failed to print: " + Utils::toStr(e.what()));
    }

    Utils::printSeparator();
}

void    testLarge() {
    Utils::printTestTitle("Large Test (10,000 elements)");

    Span largeSp(10000);

    try {
        for (unsigned int i = 0; i < 10000; i++) 
            largeSp.addNumber(i);

        Utils::printMsg("Shortest Span = " + Utils::toStr(largeSp.shortestSpan()), "green");
        Utils::printMsg("Longest Span  = " + Utils::toStr(largeSp.longestSpan()), "green");
    }
    catch (const std::exception &e) {
        Utils::printErr("Error: " + Utils::toStr(e.what()));
    }
}

void    testAddNumber() {
    Utils::printTestTitle("Testing addNumber");

    Span sp(5);

    try {
        Utils::printMsg("Adding 5 numbers...", "cyan");
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
    }
    catch (const std::exception &e) {
        Utils::printErr("Error: " + Utils::toStr(e.what()));
    }

    try {
        Utils::printMsg("Adding a 6th number...", "cyan");
        sp.addNumber(11);
    }
    catch (const std::exception &e) {
        Utils::printErr("Error: " + Utils::toStr(e.what()));
    }
}

void    testNotEnoughElements() {
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

