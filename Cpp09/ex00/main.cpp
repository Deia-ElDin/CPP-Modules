#include "Utils.hpp"
#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) 
        return (Utils::printErr("Error: could not open file."), 1);

    BitcoinExchange btc;
    
    btc.processInputFile(av[1]);
    
    return 0;
}