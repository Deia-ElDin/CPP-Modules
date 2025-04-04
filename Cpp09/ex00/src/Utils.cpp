#include "Utils.hpp"

// Console output
static	std::string constructMsg(const std::string& msg, const std::string& color) {
	std::string textBold = "\033[1m";
	std::string textColor = "\033[37m";
	std::string textReset = "\033[0m";

	if (color == "green") textColor = "\033[32m";
	else if (color == "red") textColor = "\033[31m";
	else if (color == "yellow") textColor = "\033[33m";
	else if (color == "blue") textColor = "\033[34m";
	else if (color == "magenta") textColor = "\033[35m";
	else if (color == "cyan") textColor = "\033[36m";
	else if (color == "white") textColor = "\033[37m";

	return textBold + textColor + msg + textReset;
}

void    Utils::printMsg(const std::string& msg, const std::string& color) {
	std::string fullMsg = constructMsg(msg, color);
	std::cout << fullMsg << std::endl;
}

void    Utils::printErr(const std::string& msg) {
	std::string fullMsg = constructMsg(msg, "red");
	std::cerr << fullMsg << std::endl;
}

void    Utils::printSeparator(void) {
	printMsg(" ----------------------------------------", "white");
}

void    Utils::throwErr(const std::string& msg) {
	std::string fullMsg = constructMsg(msg, "red");
	throw std::runtime_error(fullMsg);
}


// String operations
std::string         Utils::trim(const std::string& str) {
    if (str.empty()) return str;
    
    std::string result = str;

    size_t first = result.find_first_not_of(" \t"); // find first non-whitespace character
    
    if (first == std::string::npos) return ""; // no position found
    
    size_t last = result.find_last_not_of(" \t");
	
    return result.substr(first, last - first + 1);
}

size_t              Utils::countChar(const std::string& str, char c) {
    size_t count = 0;

    for (size_t i = 0; i < str.length(); i++) 
        if (str[i] == c) 
            count++;
    return count;
}

bool    Utils::isAllDigits(const std::string &str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
        if (!std::isdigit(*it))
            return false;
    return true;
}


// File operations
void    Utils::openFile(std::ifstream& file, const std::string& filename, bool escapeLine) {
    file.open(filename.c_str());

    if (!file.is_open()) throwErr("Could not open file: " + filename);

    if (escapeLine) {
        std::string line;
        std::getline(file, line);
    }
}

void    Utils::closeFileWithErr(std::ifstream& file, const std::string& errMsg) {
    file.close();
    throwErr(errMsg);
}


// Datebase file validations
void    Utils::parseDbFileLine(std::ifstream& file, const std::string& trimmedLine, int lineIdx) {
    if (lineIdx == 1) 
        return (parseFileHeader(file, trimmedLine, "date,exchange_rate"));
    parseEmptyLine(file, trimmedLine, lineIdx);
    parseCommas(file, trimmedLine, lineIdx);
 
    std::istringstream  iss(trimmedLine);
    std::string         date;
    std::string         rateStr;
    float               rate;

    if (!std::getline(iss, date, ',')) { // read text from an input string stream (iss) up until it encounters a comma
        std::stringstream ss;
        ss << "line " << lineIdx << " - Missing date field. Expected 'date,rate', got '" << trimmedLine << "'";
        closeFileWithErr(file, ss.str());
    }

    date = trim(date);
    parseDbFileDate(file, date, lineIdx);



    if (!std::getline(iss, rateStr)) {
        std::stringstream ss;
        ss << "line " << lineIdx << " - Missing rate field. Expected 'date,rate', got '" << trimmedLine << "'";
        closeFileWithErr(file, ss.str());
    }
    
    rateStr = trim(rateStr);
    parseDbFileRate(file, rateStr, rate, lineIdx);
}

void    Utils::parseDbFileDate(std::ifstream& file, const std::string& date, int lineIdx) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-' || date < "2009-01-03") {
        std::stringstream ss;
        if (date.length() != 10 || date[4] != '-' || date[7] != '-')
            ss << "line " << lineIdx << " - Invalid date format '" << date << "'. Expected YYYY-MM-DD";
        else
            ss << "line " << lineIdx << " - Invalid date '" << date << "'. Bitcoin didn't exist before January 3rd, 2009";
        closeFileWithErr(file, ss.str());
    }
    
    int year, month, day;

    try {
        std::string yearStr = date.substr(0, 4);
        std::string monthStr = date.substr(5, 2);
        std::string dayStr = date.substr(8, 2);
        
        if (!isAllDigits(yearStr) || !isAllDigits(monthStr) || !isAllDigits(dayStr)) {
            std::stringstream ss;
            ss << "line " << lineIdx << " - Invalid date format '" << date << "'. Expected YYYY-MM-DD";
            closeFileWithErr(file, ss.str());
        }
        
        year = atoi(yearStr.c_str());
        month = atoi(monthStr.c_str());
        day = atoi(dayStr.c_str());
    } catch (...) {
        std::stringstream ss;
        ss << "line " << lineIdx << " - Invalid date format '" << date << "'. Expected YYYY-MM-DD";
        closeFileWithErr(file, ss.str());
    }
    
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) {
        std::stringstream ss;
        ss << "line " << lineIdx << " - Invalid date values in '" << date << "'";
        closeFileWithErr(file, ss.str());
    }
    
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            std::stringstream ss;
            ss << "line " << lineIdx << " - Invalid day value in '" << date << "'. Month " << month << " has only 30 days";
            closeFileWithErr(file, ss.str());
        }
    } else if (month == 2) {
        // Check for leap year 
        // A year must be divisible by 4 so that the extra quarter-day each year adds up to a full day every four years.
        // It means that if a year is a century (divisible by 100), it must also be divisible by 400 to be a leap year.
        bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)); 

        if (day > (isLeapYear ? 29 : 28)) {
            std::stringstream ss;
            ss << "line " << lineIdx << " - Invalid day value in '" << date << "'. February " << year;
            ss << (isLeapYear ? " (leap year) has only 29 days" : " has only 28 days");
            closeFileWithErr(file, ss.str());
        }
    }
}

void    Utils::parseDbFileRate(std::ifstream& file, const std::string& rateStr, float& rate, int lineIdx) {
    // Check if the exchange rate string contains hexadecimal markers and triggers an error if found.
    // p+/- It indicates the exponent part in a hexadecimal floating-point literal, similar to 'e' in scientific notation.
    if (rateStr.find("0x") != std::string::npos || 
        rateStr.find("0X") != std::string::npos ||
        rateStr.find("p+") != std::string::npos ||
        rateStr.find("p-") != std::string::npos) {
        std::stringstream ss;
        ss << "line " << lineIdx << "- Invalid exchange rate format '" << rateStr << "'. Hexadecimal notation not allowed";
        closeFileWithErr(file, ss.str());
    }
    
    // Converts the string to a float and sets endptr to point to any remaining characters that weren't part of the number.
    char* endptr;
    rate = strtof(rateStr.c_str(), &endptr);
    
    // 1 mil is high enough for a single bitcoin
    if (*endptr != '\0' || rate < 0 || rate > 1000000.0f || std::isnan(rate) || std::isinf(rate)) { 
        std::stringstream ss;
        if (*endptr != '\0')
            ss << "line " << lineIdx << "- Invalid exchange rate format '" << rateStr << "'. Expected a number";
        else if (std::isnan(rate))
            ss << "line " << lineIdx << "- Invalid exchange rate '" << rateStr << "'. NaN is not allowed";
        else if (std::isinf(rate))
            ss << "line " << lineIdx << "- Invalid exchange rate '" << rateStr << "'. Infinity is not allowed";
        else if (rate < 0)
            ss << "line " << lineIdx << "- Invalid exchange rate '" << rateStr << "'. Value cannot be negative";
        else
            ss << "line " << lineIdx << "- Unreasonably large exchange rate '" << rateStr << "'";
        closeFileWithErr(file, ss.str());
    }
}

void    Utils::parseCommas(std::ifstream& file, const std::string& trimmedLine, int lineIdx) {
    size_t commaCount = countChar(trimmedLine, ',');
    
    if (commaCount == 0 || commaCount > 1) {
        std::stringstream ss;
        if (commaCount == 0)
            ss << "line " << lineIdx << " - Missing comma separator. Expected 'date,rate', got '" << trimmedLine << "'";
        else
            ss << "line " << lineIdx << " - Too many commas. Expected 'date,rate', got '" << trimmedLine << "'";
        closeFileWithErr(file, ss.str());
    }

    size_t commaPos = trimmedLine.find(',');
    std::string datePart = trim(trimmedLine.substr(0, commaPos));
    std::string ratePart = trim(trimmedLine.substr(commaPos + 1));
    
    if (datePart.empty() || ratePart.empty()) {
        std::stringstream ss;
        ss << "line " << lineIdx << " - Invalid format. Expected 'date,rate', got '" << trimmedLine << "'";
        closeFileWithErr(file, ss.str());
    }
}


// User Input File validations
bool    Utils::parseUserInputFileLine(const std::string& line, std::string& date, float& value, std::string& errorMsg) {
    std::string trimmedLine = trim(line);
    
    if (trimmedLine.empty()) {
        errorMsg = "bad input => " + line;
        return false;
    }
    
    size_t pipePos = trimmedLine.find('|');
    if (pipePos == std::string::npos) {
        errorMsg = "bad input => " + line;
        return false;
    }

    date = trim(trimmedLine.substr(0, pipePos));
    std::string valueStr = trim(trimmedLine.substr(pipePos + 1));
    
    if (date.empty() || valueStr.empty()) {
        errorMsg = "bad input => " + line;
        return false;
    }
    
    if (!parseUserDate(date, errorMsg)) {
        if (errorMsg.find("bad input =>") == std::string::npos)
            errorMsg = "bad input => " + line;
        return false;
    }
    
    if (!parseUserValue(valueStr, value, errorMsg)) {
        if (errorMsg == "bad input" || errorMsg == "not a valid number") {
            errorMsg = "bad input => " + line;
        }
        return false;
    }

    
    return true;
}

bool    Utils::parseUserDate(const std::string& date, std::string& errorMsg) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-' || date < "2009-01-03") {
        errorMsg = "bad input => " + date;
        return false;
    }
    
    int year, month, day;
    
    try {
        std::string yearStr = date.substr(0, 4);
        std::string monthStr = date.substr(5, 2);
        std::string dayStr = date.substr(8, 2);
        
        if (!isAllDigits(yearStr) || !isAllDigits(monthStr) || !isAllDigits(dayStr)) {
            errorMsg = "bad input => " + date;
            return false;
        }
        
        year = atoi(yearStr.c_str());
        month = atoi(monthStr.c_str());
        day = atoi(dayStr.c_str());
    } catch (...) {
        errorMsg = "bad input => " + date;
        return false;
    }
    
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) {
        errorMsg = "bad input => " + date;
        return false;
    }
    
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        errorMsg = "bad input => " + date;
        return false;
    } else if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > (isLeapYear ? 29 : 28)) {
            errorMsg = "bad input => " + date;
            return false;
        }
    }
    
    return true;
}

bool    Utils::parseUserValue(const std::string& valueStr, float& value, std::string& errorMsg) {
    if (valueStr.empty()) {
        errorMsg = "bad input";
        return false;
    }
    
    if (valueStr.find("0x") != std::string::npos || 
        valueStr.find("0X") != std::string::npos ||
        valueStr.find("p+") != std::string::npos ||
        valueStr.find("p-") != std::string::npos) {
        errorMsg = "bad input";
        return false;
    }
    
    char* endptr;
    value = strtof(valueStr.c_str(), &endptr);
    
    if (*endptr != '\0' || isnan(value) || isinf(value)) {
        errorMsg = "bad input";
        return false;
    }
    
    if (value < 0) {
        errorMsg = "not a positive number";
        return false;
    }
    
    if (value > 1000) {
        errorMsg = "too large a number";
        return false;
    }
    
    return true;
}

void    Utils::parsePipes(std::ifstream& file, const std::string& trimmedLine, int lineIdx) {
    size_t pipeCount = countChar(trimmedLine, '|');
    
    if (pipeCount == 0 || pipeCount > 1) {
        std::stringstream ss;
        if (pipeCount == 0)
            ss << "line " << lineIdx << " - Missing pipe separator. Expected 'date | value', got '" << trimmedLine << "'";
        else
            ss << "line " << lineIdx << " - Too many pipes. Expected 'date | value', got '" << trimmedLine << "'";
        closeFileWithErr(file, ss.str());
    }
}


// Header and Empty lines
void    Utils::parseFileHeader(std::ifstream& file, const std::string& trimmedLine, const std::string& header) {
    if (trimmedLine != header) {
        std::stringstream ss;
        if (header == "date,exchange_rate")
            ss << "Invalid header in database file. Expected '" << header << "', got '" << trimmedLine << "'";
        else
            ss << "Invalid header in user input file. Expected '" << header << "', got '" << trimmedLine << "'";
        closeFileWithErr(file, ss.str());
    }
}

void    Utils::parseEmptyLine(std::ifstream& file, const std::string& trimmedLine, int lineIdx) {
    if (trimmedLine.empty()) {
        std::stringstream ss;
        ss << "line " << lineIdx << " - Empty line or contains only whitespace";
        closeFileWithErr(file, ss.str());
    }
}
