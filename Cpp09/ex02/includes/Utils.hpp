#ifndef __UTILS_HPP__
# define __UTILS_HPP__

#include <iostream>
#include <string>
#include <sstream> 
#include <stdexcept> // std::runtime_error

namespace Utils 
{
    // Console output
    void        printMsg(const std::string& msg, const std::string& color);
    void        printErr(const std::string& msg);
    void        printSeparator(void);
    void        throwErr(const std::string& msg);
    
    template <typename T>
    std::string toStr(T value) {
        std::stringstream ss;
        
        ss << value;
        return ss.str();
    }
}

#endif





// std::string Utils::findClosestDate(const std::map<std::string, float>& exchangeRates, const std::string& date) {
//     std::map<std::string, float>::const_iterator it = exchangeRates.find(date);
//         if (it != exchangeRates.end()) {
//         return date;
//     }

//     // If the date is earlier than the first date in our database, return empty string
//     it = exchangeRates.begin();
//     if (it != exchangeRates.end() && date < it->first) {
//         return "";
//     }

//     // Otherwise, find the closest date that is not greater than the given date
//     it = exchangeRates.lower_bound(date);
//     if (it != exchangeRates.begin() && (it == exchangeRates.end() || it->first > date)) {
//         --it;
//     }

//     return it->first;
// }


// void                Utils::parseFile(std::ifstream& file, const std::string& filename) {
//     openFile(file, filename);

//     std::string line;
//     int         lineIdx = 0;
//     bool        fileHasContent = false;
    
//     while (std::getline(file, line) && ++lineIdx) {
//         std::string trimmedLine = trim(line);
//         std::string date;
//         float       rate;

//         if (lineIdx == 1) {
//             parseFileHeader(file, trimmedLine, "date,exchange_rate");
//             continue;
//         }

//         if (trimmedLine.empty()) {
//             std::stringstream ss;
//             ss << "Line " << lineIdx << " is empty or contains only whitespace in file: " << filename;
//             closeFileWithErr(file, ss.str());
//         }
        
//         parseLine(file, trimmedLine, lineIdx, date, rate);

//         fileHasContent = true;
//     }
    
//     if (!fileHasContent) 
//         closeFileWithErr(file, "File is empty or contains only headers: " + filename);

//     file.close();
// }



// void                Utils::fillDbContainer(std::ifstream& file, const std::string& filename, std::map<std::string, float>& exchangeRates) {
//     openFile(file, filename, true);

//     std::string line;
//     std::string prevDate = "";
//     int lineIdx = 1;

//     while (std::getline(file, line) && ++lineIdx) {
//         std::string trimmedLine = trim(line);
        
//         std::istringstream iss(trimmedLine);
//         std::string date;
//         std::string rateStr;
        
//         std::getline(iss, date, ',');
//         std::getline(iss, rateStr);
        
//         date = trim(date);
//         rateStr = trim(rateStr);
        
//         float rate = std::strtof(rateStr.c_str(), NULL);
        
//         // just to make sure it's not the first line and there's prevDate t compare it with date, if it's less than data it's not in chronological order
//         if (!prevDate.empty() && date <= prevDate) { 
//             std::stringstream ss;
//             ss << "line " << lineIdx << "- Dates not in chronological order. '" << date << "' comes after '" << prevDate << "'";
//             closeFileWithErr(file, ss.str());
//         }

//         prevDate = date; // then we set the prevDate to the current date for the next iteration
//         exchangeRates[date] = rate; // since all passed so far, we can store in our map (db)
//     }

//     file.close();

//     if (exchangeRates.empty()) throwErr("No valid data entries found in database file.");
// }

// void                Utils::parseInputFile(std::ifstream& file, const std::string& filename) {
//     openFile(file, filename);

//     std::string line;
//     int lineIdx = 0;
//     bool fileHasContent = false;
    
//     while (std::getline(file, line) && ++lineIdx) {
//         std::string trimmedLine = trim(line);
        
//         if (lineIdx == 1) {
//             parseFileHeader(file, trimmedLine, "date | value");
//             continue;
//         }

//         if (trimmedLine.empty()) {
//             std::stringstream ss;
//             ss << "Line " << lineIdx << " is empty or contains only whitespace in file: " << filename;
//             closeFileWithErr(file, ss.str());
//         }
        
//         size_t pipePos = trimmedLine.find('|');
//         if (pipePos == std::string::npos) {
//             std::stringstream ss;
//             ss << "Line " << lineIdx << " has invalid format. Expected 'date | value', got '" << trimmedLine << "'";
//             closeFileWithErr(file, ss.str());
//         }
        
//         std::string date = trim(trimmedLine.substr(0, pipePos));
//         std::string valueStr = trim(trimmedLine.substr(pipePos + 1));
//         float       value;
        
//         parseDbFileDate(file, date, lineIdx);
//         parseValue(file, valueStr, value, lineIdx);

//         fileHasContent = true;
//     }
    
//     if (!fileHasContent) 
//         closeFileWithErr(file, "File is empty or contains only headers: " + filename);

//     file.close();
// }

// void                Utils::processInputFile(std::ifstream& file, const std::string& filename, const BitcoinExchange& btc) {
//     openFile(file, filename, true);

//     std::string line;
    
//     while (std::getline(file, line)) {
//         size_t      pipePos = line.find('|');
//         std::string date = trim(line.substr(0, pipePos));
//         std::string valueStr = trim(line.substr(pipePos + 1));
//         float       value = std::strtof(valueStr.c_str(), NULL);

//         float exchangeRate = btc.getExchangeRate(date);
        
//         if (exchangeRate < 0) {
//             printErr("no exchange rate available for date: " + date);
//             continue;
//         }
        
//         float result = value * exchangeRate;
//         std::cout << date << " => " << value << " = " << result << std::endl;
//     }

//     file.close();
// }

// float               Utils::getExchangeRate(std::map<std::string, float>& exchangeRates, const std::string& date) {
//     // First try to find the exact date
//     std::map<std::string, float>::const_iterator it = exchangeRates.find(date);
//     if (it != exchangeRates.end()) {
//         return it->second;
//     }
    
//     // If the date is earlier than the first date in our database, return error value
//     it = exchangeRates.begin();
//     if (it != exchangeRates.end() && date < it->first) {
//         return -1.0f;  // Indicate that no exchange rate is available
//     }
    
//     // Otherwise, find the closest date that is not greater than the given date
//     it = exchangeRates.lower_bound(date);
//     if (it != exchangeRates.begin() && (it == exchangeRates.end() || it->first > date)) {
//         --it;  // Get the previous element (closest lower date)
//     }
    
//     return it->second;
// }
