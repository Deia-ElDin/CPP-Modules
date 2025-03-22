#include "BitcoinExchange.hpp"
#include "Utils.hpp"

BitcoinExchange::BitcoinExchange() {
    Utils::printMsg("BitcoinExchange default constructor", "yellow");
    parseExchangeRateDB("data/data.csv");
}

BitcoinExchange::BitcoinExchange(const std::string& databaseFile) {
    Utils::printMsg("BitcoinExchange constructor with database file", "yellow");
    parseExchangeRateDB(databaseFile);
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : exchangeRates(other.exchangeRates) {
    Utils::printMsg("BitcoinExchange copy constructor", "yellow");
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    Utils::printMsg("BitcoinExchange assignment operator", "yellow");

    if (this != &other) exchangeRates = other.exchangeRates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
    Utils::printMsg("BitcoinExchange destructor", "magenta");
}


bool BitcoinExchange::parseExchangeRateDB(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) 
        return (Utils::printErr("Error: could not open database file."), false);

    std::string line;
    // Skip the header line
    std::getline(file, line);

    // Parse the rest of the file
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        std::string rateStr;
        
        // Expected format: date,rate
        if (std::getline(iss, date, ',') && std::getline(iss, rateStr)) {
            try {
                float rate = std::atof(rateStr.c_str());
                if (isValidDate(date)) {
                    exchangeRates[date] = rate;
                }
            } catch (...) {
                std::cerr << "Error: failed to parse exchange rate for date: " << date << std::endl;
            }
        }
    }
    file.close();
    return !exchangeRates.empty();
}

void BitcoinExchange::processInputFile(const std::string& filename) {
    Utils::printMsg("1", "blue");
    if (exchangeRates.empty()) 
        return (Utils::printErr("Error: exchange rate database is empty."));
  Utils::printMsg("2", "blue");
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        return (Utils::printErr("Error: could not open file."));

    std::string line;
    // Skip the header line
    std::getline(file, line);

    // Process each line in the input file
    while (std::getline(file, line)) {
        processInputLine(line);
    }
    file.close();
}

void BitcoinExchange::processInputLine(const std::string& line) {
    std::istringstream iss(line);
    std::string date;
    std::string valueStr;
    
    // Expected format: date | value
    if (std::getline(iss, date, '|') && std::getline(iss, valueStr)) {
        // Trim whitespace
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));
        valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
        
        // Validate the date
        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            return;
        }
        
        // Parse and validate the value
        float value;
        try {
            value = std::atof(valueStr.c_str());
            if (value < 0) 
                return (Utils::printErr("Error: not a positive number."));
            if (value > 1000) 
                return (Utils::printErr("Error: too large a number."));

        } catch (...) {
            std::cerr << "Error: invalid value => " << valueStr << std::endl;
            return;
        }

        // Find the exchange rate for the date (or closest date)
        std::string closestDate = findClosestDate(date);
        if (closestDate.empty()) {
            std::cerr << "Error: no exchange rate available for date: " << date << std::endl;
            // Utils::printErr("Error: no exchange rate available for date: " + date);
            return;
        }

        // Calculate and display the result
        float exchangeRate = exchangeRates[closestDate];
        float result = value * exchangeRate;
        
        std::cout << date << " => " << value << " = " << result << std::endl;
    } else {
        Utils::printErr("Error: bad input => " + line);
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    // Date format should be YYYY-MM-DD
    if (date.length() != 10) {
        return false;
    }
    
    if (date[4] != '-' || date[7] != '-') {
        return false;
    }
    
    // Extract year, month, and day
    int year, month, day;
    try {
        year = std::atoi(date.substr(0, 4).c_str());
        month = std::atoi(date.substr(5, 2).c_str());
        day = std::atoi(date.substr(8, 2).c_str());
    } catch (...) {
        return false;
    }
    
    // Check basic range validity
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }
    
    // Check specific month lengths
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) return false;
    } else if (month == 2) {
        // February: check for leap year
        bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > (isLeapYear ? 29 : 28)) return false;
    }
    
    return true;
}

bool BitcoinExchange::isValidValue(const float value) const {
    return (value >= 0 && value <= 1000);
}

std::string BitcoinExchange::findClosestDate(const std::string& date) const {
    // If the exact date exists in the map, return it
    std::map<std::string, float>::const_iterator it = exchangeRates.find(date);
    if (it != exchangeRates.end()) {
        return date;
    }
    
    // If the date is earlier than the first date in our database, return empty string
    it = exchangeRates.begin();
    if (it != exchangeRates.end() && date < it->first) {
        return "";
    }
    
    // Otherwise, find the closest date that is not greater than the given date
    it = exchangeRates.lower_bound(date);
    if (it != exchangeRates.begin() && (it == exchangeRates.end() || it->first > date)) {
        --it;
    }
    
    return it->first;
}