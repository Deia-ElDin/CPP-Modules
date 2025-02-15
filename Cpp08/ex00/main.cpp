#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

void    testVector(void);
void    testList(void);
void    testDeque(void);

int main(void)
{
    try {
        testVector();
        Utils::printSeparator();
        testList();
        Utils::printSeparator();
        testDeque();
    }
    catch(const std::exception& e) {
        Utils::printErr("Unexpected error: Value not found in container");
    }
    return 0;
}

void    testVector(void)
{
    Utils::printTestTitle("Testing std::vector");

    std::vector<int> vec;

    int emptyValue = 1;
    int testValue = 100;
    int negativeValue = -10;
    int outOfBoundaryValue = 1000;

    try {
        easyfind(vec, emptyValue);
    } catch(const std::exception& e) {
        Utils::printErr("Empty - empty vector: Value not found in the container");
    }

    for (int i = 0; i < 20; ++i)
            vec.push_back(i * 10);

    Utils::printContainer("Vector", vec);


    try {
        std::vector<int>::iterator it = easyfind(vec, testValue);
        Utils::printMsg("Found value in vector: " + Utils::toStr(*it), "green");
    } catch(const std::exception& e) {
        Utils::printErr("Error: " + Utils::toStr(e.what()));
    }

    try {
        Utils::printTestTitle("Testing const vector");

        const std::vector<int>&             constVec = vec;
        std::vector<int>::const_iterator    constIt = easyfind(constVec, testValue);

        Utils::printContainer("Const Vector", constVec);
        Utils::printMsg("Found value in const vector: " + Utils::toStr(*constIt), "green");
    } catch(const std::exception& e) {
        Utils::printErr("Error: " + Utils::toStr(e.what()));    
    }

    try {
        Utils::printTestTitle("Testing vector with negative value");
        easyfind(vec, negativeValue);
    } catch(const std::exception& e) {
        Utils::printErr("Error - negative value: " + Utils::toStr(e.what()));
    }

    try {
        Utils::printTestTitle("Testing vector with out of boundary value");
        easyfind(vec, outOfBoundaryValue);
    } catch(const std::exception& e) {
        Utils::printErr("Error - out of boundary value: " + Utils::toStr(e.what()));
    }
}

void    testList(void)
{
    Utils::printTestTitle("Testing std::list");
    std::list<int> lst;

    for (int i = 0; i < 5; ++i)
        lst.push_back(i * 10);

    Utils::printContainer("List", lst);

    try {
        std::list<int>::iterator it = easyfind(lst, 10);
        Utils::printMsg("Found value in lst: " + Utils::toStr(*it), "green");

        easyfind(lst, 7);
    } catch(const std::exception& e) {
        Utils::printErr("Error finding 7: " + Utils::toStr(e.what()));
    }
}

void    testDeque(void)
{
    Utils::printTestTitle("Testing std::deque");
    std::deque<int> deq;
    
    for (int i = 0; i < 5; ++i)
        deq.push_back(i * 10);

    Utils::printContainer("Deque", deq);

    try {
        std::deque<int>::iterator it = easyfind(deq, 10);
        Utils::printMsg("Found value in deque: " + Utils::toStr(*it), "green");
        easyfind(deq, 2);
    } catch(const std::exception& e) {
        Utils::printErr("Error finding 7: " + Utils::toStr(e.what()));
    }
}

