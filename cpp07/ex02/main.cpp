#include "Array.hpp"
#include "Utils.hpp"

void    testDefault();
void    testParam();
void    testCopy();
void    testAssignmentOperator();
void    testException();
void    testStr();
void    testFloat();
void    fillArray(Array<int>& arr);
void    printArray(const std::string &text, Array<int>& arr);
void    printArraySize(Array<int>& arr);

int main() {
    int test = 0;

    if (!test || test == 1) testDefault();
    if (!test || test == 2) testParam();
    if (!test || test == 3) testCopy();
    if (!test || test == 4) testAssignmentOperator();
    if (!test || test == 5) testException();
    if (!test || test == 6) testStr();
    if (!test || test == 7) testFloat();

    return 0;
}

void    testDefault() {
    Utils::printTest("\nTesting Default Constructor:");

    Array<int> empty;
    printArraySize(empty);
}

void    testParam() {
    Utils::printTest("\nTesting Parameterized Constructor:");

    Array<int> nums(5);
    printArraySize(nums);
}

void    testCopy() {
    Utils::printTest("\nTesting Copy Constructor:");

    Utils::printMsg("\nCreating the Original Array:", "cyan");
    Array<int> original(5);

    fillArray(original);
    printArray("Original array:", original);

    Utils::printMsg("\nCreating the Copy Array:", "cyan");
    Array<int> copy(original);
    
    printArray("Copy array:", copy);

    Utils::printTest("\nTesting Modifications:");
    copy[0] = 100;
    Utils::printMsg("copy[0] = " + Utils::toStr(copy[0]), "green");
    Utils::printMsg("original[0] = " + Utils::toStr(original[0]), "green");
}

void    testAssignmentOperator() {
    Utils::printTest("\nTesting Assignment Operator:");

    Utils::printMsg("\nCreating the Original Array:", "cyan");
    Array<int> original(5);

    fillArray(original);
    printArray("Original array:", original);

    Utils::printMsg("\nCreating the Assigned Array:", "cyan");
    Array<int> assigned;
    assigned = original;
    
    printArray("Assigned array:", assigned);
}

void    testException() {
    Utils::printTest("\nTesting Exception for Out of Boundaries:");
    Array<int> arr(5);
    
    fillArray(arr);
    printArray("Printing The Array: ", arr);

    try {
        Utils::printMsg("Trying to access index arr[5] (out of boundaries)", "yellow");
        arr[5] = 42;
    }
    catch (const std::exception& e) {
        Utils::printErr("Exception caught: " + std::string(e.what()));
    }
}

void    testStr() {
    Utils::printTest("\nTesting with std::string:");
    Array<std::string> str_arr(3);

    str_arr[0] = "42";
    str_arr[1] = "AD";
    str_arr[2] = "!";
    
    for (unsigned int i = 0; i < str_arr.size(); i++)
        Utils::printMsg("str_arr[" + Utils::toStr(i) + "] = " + str_arr[i], "green");
}

void    testFloat() {
    Utils::printTest("\nTesting with float:");
    Array<float> float_arr(3);

    float_arr[0] = 42.42;
    float_arr[1] = 42.42;
    float_arr[2] = 42.42;

    for (unsigned int i = 0; i < float_arr.size(); i++)
        Utils::printMsg("float_arr[" + Utils::toStr(i) + "] = " + Utils::toStr(float_arr[i]), "green");
}

void    fillArray(Array<int>& arr) {
    for (unsigned int i = 0; i < arr.size(); i++)
        arr[i] = i + 1;
}

void    printArray(const std::string &text, Array<int>& arr) {
    Utils::printMsg("\n" + text, "green");

    for (unsigned int i = 0; i < arr.size(); i++)
        Utils::printMsg("arr[" + Utils::toStr(i) + "] = " + Utils::toStr(arr[i]), "green");
}

void    printArraySize(Array<int>& arr) {
    Utils::printMsg("Size: " + Utils::toStr(arr.size()), "green");
}

