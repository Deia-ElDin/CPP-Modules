#ifndef __BITCOIN_EXCHANGE_HPP__
#define __BITCOIN_EXCHANGE_HPP__

#include <iostream> // std::cout, std::cerr
#include <string>   // std::string
#include <map>      // std::map
#include <fstream>  // std::ifstream
#include <sstream>  // std::istringstream
#include <cstdlib>  // std::exit
#include <iomanip>  // std::setprecision, std::fixed

class BitcoinExchange {
    private:
        std::map<std::string, float> _exchangeRates;
    
        // Db Validation
        void validateDatabaseFile(const std::string& filename);
        void parseFile(std::ifstream& file, const std::string& filename);
        void fillDbContainer(std::ifstream& file, const std::string& filename);
        
        // User input file Validation
        void parseInputFile(std::ifstream& file, const std::string& filename);
        void processInputFile(std::ifstream& file, const std::string& filename);
        
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string& databaseFile);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
    
        // Proccess user input
        void validateUserInputFile(const std::string& filename);
        
        // Get exchange rate for a specific date
        float getExchangeRate(const std::string& date) const;
    };

#endif