#include "Whatever.hpp"
#include "Utils.hpp"

int main( void ) {
    int a = 2;
    int b = 3;

    Utils::printMsg("a = " + Utils::toStr(a) + ", b = " + Utils::toStr(b), "green");
    Utils::printMsg("Swapping a and b", "magenta");
    ::swap(a, b);
    Utils::printMsg("a = " + Utils::toStr(a) + ", b = " + Utils::toStr(b), "red");
    Utils::printMsg("testing min and max after swapping", "magenta");
    Utils::printMsg("min(a, b) = " + Utils::toStr(::min(a, b)), "yellow");
    Utils::printMsg("max(a, b) = " + Utils::toStr(::max(a, b)), "blue");
       
    std::string c = "chaine1";
    std::string d = "chaine2";

    Utils::printMsg("\n\nc = " + c + ", d = " + d, "green");
    Utils::printMsg("Swapping a and b", "magenta");
    ::swap(c, d);
    Utils::printMsg("c = " + c + ", d = " + d, "red");
    Utils::printMsg("testing min and max after swapping", "magenta");
    Utils::printMsg("min(c, d) = " + ::min(c, d), "yellow");
    Utils::printMsg("max(c, d) = " + ::max(c, d), "blue");
  
    return 0;
}
