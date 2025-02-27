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
        testList();
        testDeque();
    }
    catch(const std::exception& e) {
        Utils::printErr("Program Error: " + Utils::toStr(e.what()));
    }
    return 0;
}

void    testVector(void)
{
    Utils::printTestTitle("Testing std::vector");

    std::vector<int> vec;

    try {
        easyfind(vec, 1);
    } catch(const std::exception& e) {
        Utils::printErr("Empty Error: " + Utils::toStr(e.what()));
    }
    
    for (int i = 0; i < 20; ++i)
            vec.push_back(i * 10);

    Utils::printContainer("Vector", vec);

    try {
        std::vector<int>::iterator it = easyfind(vec, 100);
        Utils::printMsg("Found value in vector: " + Utils::toStr(*it), "green");
    } catch(const std::exception& e) {
        Utils::printErr("Error: " + Utils::toStr(e.what()));
    }

    try {
        Utils::printTestTitle("Testing const vector");

        const std::vector<int>&             constVec = vec;
        std::vector<int>::const_iterator    constIt = easyfind(constVec, 100);

        Utils::printContainer("Const Vector", constVec);
        Utils::printMsg("Found value in const vector: " + Utils::toStr(*constIt), "green");
    } catch(const std::exception& e) {
        Utils::printErr("Error: " + Utils::toStr(e.what()));    
    }

    try {
        Utils::printTestTitle("Testing vector with negative value");
        easyfind(vec, -10);
    } catch(const std::exception& e) {
        Utils::printErr("Error - negative value: " + Utils::toStr(e.what()));
    }

    try {
        Utils::printTestTitle("Testing vector with out of boundary value");
        easyfind(vec, 1000);
    } catch(const std::exception& e) {
        Utils::printErr("Error - out of boundary value: " + Utils::toStr(e.what()));
    }

    Utils::printSeparator();
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

    Utils::printSeparator();
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

    Utils::printSeparator();
}


// Feature	                            std::deque	             std::vector	     std::list
// Random Access (O(1))	                ✅ Yes	                ✅ Yes	            ❌ No (O(n))
// Insertion/Deletion at Front (O(1))	✅ Yes (push_front())	❌ No (O(n))        	✅ Yes
// Insertion/Deletion at Back (O(1))	✅ Yes (push_back())	    ✅ Yes (push_back())	✅ Yes
// Insertion/Deletion in Middle (O(n))	❌ No	                ❌ No	            ✅ Yes (O(1))
// Contiguous Memory	                ❌ No (blocks)           ✅ Yes	            ❌ No (linked nodes)
// Cache-Friendly	                    Medium                   ✅ High 	         ❌ Poor