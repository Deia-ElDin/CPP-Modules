#include "BitcoinExchange.hpp"
#include "Utils.hpp"

BitcoinExchange::BitcoinExchange() {
    Utils::printMsg("BitcoinExchange default constructor", "blue");
    validateDatabaseFile("data/data.csv");
}

BitcoinExchange::BitcoinExchange(const std::string& databaseFile) {
    Utils::printMsg("BitcoinExchange constructor with database file", "blue");
    validateDatabaseFile(databaseFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _exchangeRates(other._exchangeRates) {
    Utils::printMsg("BitcoinExchange copy constructor", "blue");
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    Utils::printMsg("BitcoinExchange assignment operator", "blue");

    if (this != &other) _exchangeRates = other._exchangeRates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
    Utils::printMsg("BitcoinExchange destructor", "magenta");
}

// Main parsing function
void    BitcoinExchange::validateDatabaseFile(const std::string& filename) {
    std::ifstream file;

    try {
        Utils::printMsg("Step 1:    parsing database file, filename = " + filename, "yellow");
        parseFile(file, filename);
        Utils::printMsg("Step 1:    Completed Successfully", "green");
    } catch (const std::exception& e) {
        Utils::throwErr("    Failed to validate database file: " + Utils::toStr(e.what()));
    }
    
    try {
        Utils::printMsg("Step 2:    filling database, filename = " + filename, "yellow");
        fillDbContainer(file, filename);
        Utils::printMsg("Step 2:    Completed Successfully", "green");
    } catch (const std::exception& e) {
        Utils::throwErr("    Failed to fill database container: " + Utils::toStr(e.what()));
    }
}

void    BitcoinExchange::validateUserInputFile(const std::string& filename) {
    std::ifstream file;

    try {
        Utils::printMsg("Step 3:    parsing user input file, filename = " + filename, "yellow");
        parseInputFile(file, filename);
        Utils::printMsg("Step 3:    Completed Successfully", "green");
    } catch (const std::exception& e) {
        Utils::throwErr("    Failed to validate user input file: " + Utils::toStr(e.what()));
    }
    
    try {
        Utils::printMsg("Step 4:    processing user input file, filename = " + filename, "yellow");
        processInputFile(file, filename);
        Utils::printMsg("Step 4:    Completed Successfully", "green");
    } catch (const std::exception& e) {
        Utils::throwErr("    Failed to process user input file: " + Utils::toStr(e.what()));
    }
}


// Database file parsing functions
void    BitcoinExchange::parseFile(std::ifstream& file, const std::string& filename) {
    Utils::openFile(file, filename);

    std::string line;
    int         lineIdx = 0;
    bool        fileHasContent = false;
    
    while (std::getline(file, line) && ++lineIdx) {
        std::string trimmedLine = Utils::trim(line);
        Utils::parseDbFileLine(file, trimmedLine, lineIdx);
        fileHasContent = true;
    }
    
    if (!fileHasContent) 
        Utils::closeFileWithErr(file, "File is empty or contains only headers: " + filename);

    file.close();
}

void    BitcoinExchange::fillDbContainer(std::ifstream& file, const std::string& filename) {
    Utils::openFile(file, filename, true);

    std::string line;
    std::string prevDate = "";
    int         lineIdx = 1;

    while (std::getline(file, line) && ++lineIdx) {
        std::string trimmedLine = Utils::trim(line);
        
        std::istringstream iss(trimmedLine);
        std::string date;
        std::string rateStr;
        
        std::getline(iss, date, ',');
        std::getline(iss, rateStr);
        
        date = Utils::trim(date);
        rateStr = Utils::trim(rateStr);
        
        // convert string to float and the null is for the end of the string, because i'm sure it's a valid float
        float rate = strtof(rateStr.c_str(), NULL); 
        
        // just to make sure it's not the first line and there's prevDate to compare it with date.
        // if it's less than data it's not in chronological order
        if (!prevDate.empty() && date <= prevDate) { 
            std::stringstream ss;
            ss << "line " << lineIdx << "- Dates not in chronological order. '" << date << "' comes after '" << prevDate << "'";
            Utils::closeFileWithErr(file, ss.str());
        }

        prevDate = date; // then we set the prevDate to the current date for the next iteration
        _exchangeRates[date] = rate; // since all passed so far, we can store in our map (db)
    }

    file.close();

    if (_exchangeRates.empty()) 
        Utils::throwErr("No valid data entries found in database file.");
}


// User input file parsing functions
void    BitcoinExchange::parseInputFile(std::ifstream& file, const std::string& filename) {
    Utils::openFile(file, filename);

    std::string line;
    bool        fileHasContent = false;
    
    if (std::getline(file, line)) {
        std::string trimmedLine = Utils::trim(line);

        if (trimmedLine != "date | value")
            Utils::closeFileWithErr(file, "Invalid header in user input file. Expected 'date | value', got '" + trimmedLine + "'");
        fileHasContent = true;

    }
    
    if (!fileHasContent) 
        Utils::closeFileWithErr(file, "File is empty: " + filename);

    file.close();
}

void    BitcoinExchange::processInputFile(std::ifstream& file, const std::string& filename) {
    Utils::openFile(file, filename, true); 

    std::string line;
    
    while (std::getline(file, line)) {
        std::string errorMsg;
        std::string date;
        float       value;
        
        if (Utils::parseUserInputFileLine(line, date, value, errorMsg)) {
            float exchangeRate = getExchangeRate(date);

            if (exchangeRate < 0) {
                Utils::printErr("Error: no exchange rate available for date: " + date);
            } else {
                float result = value * exchangeRate;
                Utils::printMsg(date + " => " + Utils::toStr(value) + " = " + Utils::toStr(result), "white");
            }
        } else if (!errorMsg.empty()) {
            Utils::printErr("Error: " + errorMsg);
        }
    }

    file.close();
}


// Get exchange rate for a specific date
float   BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _exchangeRates.find(date);
    if (it != _exchangeRates.end()) 
        return it->second;
    
    it = _exchangeRates.begin(); // checking if the date is earlier than the first date in our db
    if (date < it->first) 
        return -1.0f;
    
    // returns an iterator (first entry not less than date, value >= data by step)
    it = _exchangeRates.lower_bound(date);
    // it == _exchangeRates.end() means that the date is later than the last date in our db,
    // which means it's right after the last element in our db so we need to get the previous element
    if (it != _exchangeRates.begin() && (it == _exchangeRates.end() || it->first > date)) 
        --it;

    return it->second;
}
