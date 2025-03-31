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

        // Testing getExchangeRate function
        // Utils::printMsg("Exchange rate for 2021-01-01: " + Utils::toStr(btc.getExchangeRate("2009-01-01")), "blue");
        // Utils::printMsg("Exchange rate for 2021-01-03: " + Utils::toStr(btc.getExchangeRate("2021-01-03")), "blue");
        // Utils::printMsg("Exchange rate for 2021-01-10: " + Utils::toStr(btc.getExchangeRate("2021-01-10")), "blue");
    } catch (const std::exception& e) {
        Utils::printErr("Error: " + Utils::toStr(e.what()));
        return 1;
    }
    
    return 0;
}
