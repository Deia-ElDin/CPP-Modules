#include "MutantStack.hpp"
#include "Utils.hpp"
#include <list>
#include <vector>

void    pdfSubjectTest();
void    testBasicOperations();
void    testIterators();
void    testCompareWithList();
void    testReverseIterators();
void    testDifferentContainer();

int main() {
    try {
        pdfSubjectTest();
        // testBasicOperations();
        // testIterators();
        // testCompareWithList();
        // testReverseIterators();
        // testDifferentContainer();
        
        return 0;
    } catch (const std::exception& e) {
        Utils::printErr("Exception: " + std::string(e.what()));
        return 1;
    }
}

void pdfSubjectTest() {
    Utils::printTestTitle("PDF Subject Example Test");
    
    MutantStack<int> mStack;
    mStack.push(5);
    mStack.push(17);
    
    Utils::printMsg("Top: " + Utils::toStr(mStack.top()), "green");
    
    mStack.pop();
    Utils::printMsg("Size: " + Utils::toStr(mStack.size()), "cyan");
    Utils::printMsg("Top: " + Utils::toStr(mStack.top()), "green");
    
    mStack.push(3);
    mStack.push(5);
    mStack.push(737);
    mStack.push(0);
    
    Utils::printMsg("Iteration through stack:", "magenta");
    MutantStack<int>::iterator it = mStack.begin();
    MutantStack<int>::iterator ite = mStack.end();
    ++it;
    --it;
    while (it != ite) {
        Utils::printMsg(Utils::toStr(*it), "yellow");
        ++it;
    }
    
    std::stack<int> s(mStack);
    Utils::printMsg("Stack copy created successfully", "blue");
    
    Utils::printSeparator();
}

void testBasicOperations() {
    Utils::printTestTitle("Test 1: Basic Stack Operations");
    
    MutantStack<int> mStack;
    
    mStack.push(10);
    mStack.push(20);
    Utils::printMsg("Top after pushes: " + Utils::toStr(mStack.top()), "green");
    
    mStack.pop();
    Utils::printMsg("Size after pop: " + Utils::toStr(mStack.size()), "cyan");
    Utils::printMsg("New top: " + Utils::toStr(mStack.top()), "green");
    
    mStack.pop();
    Utils::printMsg("Is empty: " + Utils::toStr(mStack.empty()), "yellow");
    
    Utils::printSeparator();
}

void testIterators() {
    Utils::printTestTitle("Test 2: Basic Iterator Usage");
    
    MutantStack<int> mStack;
    
    for (int i = 1; i <= 5; i++) {
        mStack.push(i * 10);
    }
    
    Utils::printMsg("Printing the stack:", "yellow");
    for (MutantStack<int>::iterator it = mStack.begin(); it != mStack.end(); ++it) {
        Utils::printMsg(Utils::toStr(*it), "green");
    }
    
    Utils::printSeparator();
}

void testCompareWithList() {
    Utils::printTestTitle("Test 3: Comparison with std::list");
    
    MutantStack<int>    mStack;
    std::list<int>      myList;
    
    for (int i = 1; i <= 3; i++) {
        mStack.push(i);
        myList.push_back(i);
    }
    
    std::string mStackContent;
    for (MutantStack<int>::iterator it = mStack.begin(); it != mStack.end(); ++it) {
        mStackContent += Utils::toStr(*it) + " ";
    }
    
    std::string listContent;
    for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        listContent += Utils::toStr(*it) + " ";
    }
    
    Utils::printMsg("MutantStack contents: " + mStackContent, "cyan");
    Utils::printMsg("List contents: " + listContent, "yellow");
    Utils::printMsg("Both containers show same order: " + 
                  Utils::toStr(mStackContent == listContent ? "true" : "false"), "green");
    
    Utils::printSeparator();
}

void testReverseIterators() {
    Utils::printTestTitle("Test 4: Reverse Iterators");
    
    MutantStack<char> mStack;
    
    mStack.push('A');
    mStack.push('B');
    mStack.push('C');
    
    std::string forward;
    for (MutantStack<char>::iterator it = mStack.begin(); it != mStack.end(); ++it) {
        forward += *it;
    }
    
    std::string reverse;
    for (MutantStack<char>::reverse_iterator it = mStack.rbegin(); it != mStack.rend(); ++it) {
        reverse += *it;
    }
    
    Utils::printMsg("Forward iteration: " + forward, "cyan");
    Utils::printMsg("Reverse iteration: " + reverse, "yellow");
    
    Utils::printSeparator();
}

void testDifferentContainer() {
    Utils::printTestTitle("Test 5: Different Container Type");
    
    MutantStack<std::string, std::vector<std::string> > mStack;
    
    mStack.push("Hello");
    mStack.push("World");
    
    Utils::printMsg("Top element: " + mStack.top(), "green");
    Utils::printMsg("Stack contents:", "cyan");
    
    for (MutantStack<std::string, std::vector<std::string> >::iterator it = mStack.begin();
         it != mStack.end(); ++it) {
        Utils::printMsg(*it, "yellow");
    }
    
    Utils::printSeparator();
}
