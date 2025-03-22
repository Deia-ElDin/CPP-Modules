#ifndef __BITCOIN_EXCHANGE_HPP__
#define __BITCOIN_EXCHANGE_HPP__

#include <iostream> // std::cout, std::cerr
#include <string>   // std::string
#include <map>      // std::map
#include <fstream>  // std::ifstream
#include <sstream>  // std::istringstream
#include <cstdlib>  // std::exit
#include <iomanip>  // std::setprecision, std::fixed

class BitcoinExchange 
{
    private:
        std::map<std::string, float> exchangeRates;
        
        bool        isValidDate(const std::string& date) const;
        bool        isValidValue(const float value) const;
        std::string findClosestDate(const std::string& date) const;
        bool        parseExchangeRateDB(const std::string& filename);
        void        processInputLine(const std::string& line);

    public:
        BitcoinExchange();
        BitcoinExchange(const std::string& databaseFile);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        
        void processInputFile(const std::string& filename);
};

#endif