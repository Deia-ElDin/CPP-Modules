#include "Utils.hpp"
#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        Utils::printErr("Ac Error: program requires one argument (input file).");
        Utils::printMsg("Usage: ./btc <input_file>", "yellow");
        return 1;
    }

    try {
        BitcoinExchange btc;
        btc.validateUserInputFile(av[1]);
    } catch (const std::exception& e) {
        Utils::printErr("Error: " + Utils::toStr(e.what()));
        return 1;
    }
    
    return 0;
}
