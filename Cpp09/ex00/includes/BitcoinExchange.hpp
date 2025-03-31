#ifndef __BITCOIN_EXCHANGE_HPP__
#define __BITCOIN_EXCHANGE_HPP__

#include <string>   // std::string
#include <map>      // std::map
#include <fstream>  // std::ifstream

class BitcoinExchange 
{
    private:
        std::map<std::string, float> _exchangeRates;
    
        // Database file parsing functions
        void validateDatabaseFile(const std::string& filename);
        void parseFile(std::ifstream& file, const std::string& filename);
        void fillDbContainer(std::ifstream& file, const std::string& filename);
        
        // User input file parsing functions
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
