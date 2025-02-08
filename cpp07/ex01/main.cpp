#include "Iter.hpp"
#include "Utils.hpp"

void    printInt(int& i);
void    addOne(int& i);
void    addTwo(int& i);
void    printStr(std::string& str);
void    shiftStrByOne(std::string& str);


int main() {
    int         int_arr[] = {1, 2, 3, 4, 5};
    std::string str_arr[] = {"AAA", "BBB", "CCC"};

    Utils::printMsg("Printing each element", "magenta");
    iter(int_arr, 5, printInt);

    Utils::printMsg("Adding 1 to each element", "magenta");
    iter(int_arr, 5, addOne);
    iter(int_arr, 5, printInt);

    Utils::printMsg("Adding 2 to each element", "magenta");
    iter(int_arr, 5, addTwo);
    iter(int_arr, 5, printInt);

    Utils::printMsg("Printing each element", "magenta");
    iter(str_arr, 3, printStr);

    Utils::printMsg("Shifting each char by 1 char", "magenta");
    iter(str_arr, 3, shiftStrByOne);
    iter(str_arr, 3, printStr);

    return 0;
}


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
    for (size_t i = 0; i < str.length(); i++)
        str[i] += 1;
}
