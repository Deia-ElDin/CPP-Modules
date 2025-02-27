#include "MutantStack.hpp"
#include "Utils.hpp"
#include <iostream>
#include <list>
#include <vector>

void    testBasicStack(void);
void    compareWithList(void);
void    testAdvancedFeatures(void);
void    testErrorHandling(void);

int main() {
    try {
        // Run the provided test
        Utils::printTestTitle("Subject Example Test");
        
        MutantStack<int> mutantStack;
        mutantStack.push(5);
        Utils::printMsg("Pushed 5", "green");
        
        mutantStack.push(17);
        Utils::printMsg("Pushed 17", "green");
        
        Utils::printMsg("Top element: " + Utils::toStr(mutantStack.top()), "cyan");
        
        mutantStack.pop();
        Utils::printMsg("Popped top element", "yellow");
        
        Utils::printMsg("Stack size: " + Utils::toStr(mutantStack.size()), "cyan");
        
        mutantStack.push(3);
        Utils::printMsg("Pushed 3", "green");
        
        mutantStack.push(5);
        Utils::printMsg("Pushed 5", "green");
        
        mutantStack.push(737);
        Utils::printMsg("Pushed 737", "green");
        
        mutantStack.push(0);
        Utils::printMsg("Pushed 0", "green");
        
        Utils::printMsg("Iterating through stack contents:", "magenta");
        MutantStack<int>::iterator it = mutantStack.begin();
        MutantStack<int>::iterator ite = mutantStack.end();
        ++it;
        --it;
        while (it != ite) {
            Utils::printMsg(Utils::toStr(*it), "yellow");
            ++it;
        }
        
        std::stack<int> s(mutantStack);
        Utils::printMsg("Created standard stack from MutantStack (size: " + 
                      Utils::toStr(s.size()) + ")", "blue");
        
        Utils::printSeparator();
        
        // Run additional tests
        testBasicStack();
        compareWithList();
        testAdvancedFeatures();
        testErrorHandling();
        
        Utils::printMsg("All tests completed successfully!", "green");
        return 0;
    } catch (const std::exception& e) {
        Utils::printErr("Unhandled exception: " + std::string(e.what()));
        return 1;
    }
}

void testBasicStack() {
    Utils::printTestTitle("Basic Stack Operations");
    
    MutantStack<int> mutantStack;
    
    // Push some values
    mutantStack.push(5);
    mutantStack.push(17);
    
    // Test top value
    Utils::printMsg("Top value: " + Utils::toStr(mutantStack.top()), "green");
    
    // Test pop
    mutantStack.pop();
    Utils::printMsg("Size after pop: " + Utils::toStr(mutantStack.size()), "green");
    
    // Add more values
    mutantStack.push(3);
    mutantStack.push(5);
    mutantStack.push(737);
    mutantStack.push(0);
    
    // Test iterators
    Utils::printMsg("Stack contents using iterators:", "cyan");
    MutantStack<int>::iterator it = mutantStack.begin();
    MutantStack<int>::iterator ite = mutantStack.end();
    
    ++it;
    --it;
    
    std::string stackContents;
    while (it != ite) {
        stackContents += Utils::toStr(*it) + " ";
        ++it;
    }
    Utils::printMsg(stackContents, "yellow");
    
    // Test copy construction to std::stack
    std::stack<int> s(mutantStack);
    Utils::printMsg("Created standard stack from MutantStack", "magenta");
    Utils::printMsg("Standard stack size: " + Utils::toStr(s.size()), "magenta");
    Utils::printMsg("Standard stack top: " + Utils::toStr(s.top()), "magenta");
    
    Utils::printSeparator();
}

void compareWithList() {
    Utils::printTestTitle("Comparing MutantStack with std::list");
    
    // Test with MutantStack
    MutantStack<int> mutantStack;
    mutantStack.push(5);
    mutantStack.push(17);
    Utils::printMsg("MutantStack top: " + Utils::toStr(mutantStack.top()), "cyan");
    mutantStack.pop();
    Utils::printMsg("MutantStack size after pop: " + Utils::toStr(mutantStack.size()), "cyan");
    mutantStack.push(3);
    mutantStack.push(5);
    mutantStack.push(737);
    mutantStack.push(0);
    
    std::string mutantStackContent;
    for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
        mutantStackContent += Utils::toStr(*it) + " ";
    }
    Utils::printMsg("MutantStack contents: " + mutantStackContent, "cyan");
    
    // Test with std::list (to verify same behavior)
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    Utils::printMsg("List back: " + Utils::toStr(lst.back()), "yellow");
    lst.pop_back();
    Utils::printMsg("List size after pop: " + Utils::toStr(lst.size()), "yellow");
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::string listContent;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        listContent += Utils::toStr(*it) + " ";
    }
    Utils::printMsg("List contents: " + listContent, "yellow");
    
    Utils::printSeparator();
}

void testAdvancedFeatures() {
    Utils::printTestTitle("Advanced Features");
    
    // Test with a different container type
    MutantStack<std::string, std::vector<std::string> > strStack;
    strStack.push("Hello");
    strStack.push("World");
    strStack.push("!");
    
    std::string strStackContent;
    for (MutantStack<std::string, std::vector<std::string> >::iterator it = strStack.begin(); 
         it != strStack.end(); ++it) {
        strStackContent += *it + " ";
    }
    Utils::printMsg("String stack contents: " + strStackContent, "green");
    
    // Test reverse iterators
    MutantStack<int> mutantStack;
    for (int i = 1; i <= 5; ++i) {
        mutantStack.push(i);
    }
    
    std::string normalOrder;
    for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
        normalOrder += Utils::toStr(*it) + " ";
    }
    Utils::printMsg("Stack contents (normal order): " + normalOrder, "magenta");
    
    std::string reverseOrder;
    for (MutantStack<int>::reverse_iterator it = mutantStack.rbegin(); it != mutantStack.rend(); ++it) {
        reverseOrder += Utils::toStr(*it) + " ";
    }
    Utils::printMsg("Stack contents (reverse order): " + reverseOrder, "magenta");
    
    // Test const iterators
    const MutantStack<int> constStack(mutantStack);
    std::string constStackContent;
    for (MutantStack<int>::const_iterator it = constStack.begin(); it != constStack.end(); ++it) {
        constStackContent += Utils::toStr(*it) + " ";
    }
    Utils::printMsg("Const stack contents: " + constStackContent, "blue");
    
    Utils::printSeparator();
}

void testErrorHandling() {
    Utils::printTestTitle("Error Handling Test");
    
    try {
        // Create a stack with limited size
        MutantStack<int> smallStack;
        
        // Fill the stack
        smallStack.push(1);
        Utils::printMsg("Pushed 1 to stack", "green");
        
        // Try to access an element when there's only one
        Utils::printMsg("Top element is: " + Utils::toStr(smallStack.top()), "green");
        
        // Testing pop on single element stack
        smallStack.pop();
        Utils::printMsg("Popped the only element", "yellow");
        
        // Try to check span with empty stack - this should throw
        if (smallStack.empty()) {
            Utils::printMsg("Stack is now empty", "yellow");
            Utils::printMsg("Attempting to access top of empty stack would throw std::out_of_range in a custom implementation", "red");
        }
        
    } catch (const std::exception& e) {
        Utils::printErr("Caught exception: " + std::string(e.what()));
    }
    
    Utils::printSeparator();
}
