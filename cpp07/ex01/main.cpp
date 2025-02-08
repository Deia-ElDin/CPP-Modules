#include "Iter.hpp"
#include "Utils.hpp"

void    printInt(int& i) {
    Utils::printMsg(Utils::toStr(i), "green");
}

void    addOne(int& i) {
    i++;
}

void    addTwo(int& i) {
    i += 2;
}

void    printStr(std::string& str) {
    Utils::printMsg(str, "green");
}

void    shiftStrByOne(std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        str[i] += 1;
    }
}


int main() {
    int arr[] = {1, 2, 3, 4, 5};

    Utils::printMsg("Printing each element", "magenta");
    iter(arr, 5, printInt);

    Utils::printMsg("Adding 1 to each element", "magenta");
    iter(arr, 5, addOne);
    iter(arr, 5, printInt);

    Utils::printMsg("Adding 2 to each element", "magenta");
    iter(arr, 5, addTwo);
    iter(arr, 5, printInt);

    std::string arr2[] = {"one", "two", "three", "four", "five"};

    Utils::printMsg("Printing each element", "magenta");
    iter(arr2, 5, printStr);

    // shift each char by 1
    Utils::printMsg("Shifting each char by 1", "magenta");
    iter(arr2, 5, shiftStrByOne);
    iter(arr2, 5, printStr);
    return 0;
}

