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

void                Utils::printMsg(const std::string& msg, const std::string& color) {
	std::string fullMsg = constructMsg(msg, color);
	std::cout << fullMsg << std::endl;
}

void                Utils::printErr(const std::string& msg) {
	std::string fullMsg = constructMsg(msg, "red");
	std::cerr << fullMsg << std::endl;
}

void                Utils::printSeparator(void) {
	printMsg("----------------------------------------", "white");
}

void                Utils::throwErr(const std::string& msg) {
	std::string fullMsg = constructMsg(msg, "red");
	throw std::runtime_error(fullMsg);
}


// String operations
std::string         Utils::trim(const std::string& str) {
    if (str.empty()) return str;
    
    std::string result = str;

    size_t first = result.find_first_not_of(" \t");
    
    if (first == std::string::npos) return "";
    
    size_t last = result.find_last_not_of(" \t");
	
    return result.substr(first, last - first + 1);
}

size_t              Utils::countChar(const std::string& str, char c) {
    size_t count = 0;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}


// File operations
void                Utils::openFile(std::ifstream& file, const std::string& filename, bool escapeLine) {
    file.open(filename.c_str());

    if (!file.is_open()) throwErr("Could not open file: " + filename);

    if (escapeLine) {
        std::string line;
        std::getline(file, line);
    }
}

void                Utils::closeFileWithErr(std::ifstream& file, const std::string& errMsg) {
    file.close();
    throwErr(errMsg);
}


// Header and format validations
void                Utils::parseFileHeader(std::ifstream& file, const std::string& trimmedLine, const std::string& header) {
    if (trimmedLine != header) {
        std::stringstream ss;
        if (header == "date,exchange_rate")
            ss << "Invalid header in database file. Expected '" << header << "', got '" << trimmedLine << "'";
        else
            ss << "Invalid header in user input file. Expected '" << header << "', got '" << trimmedLine << "'";
        closeFileWithErr(file, ss.str());
    }
}

void                Utils::parseCommas(std::ifstream& file, const std::string& trimmedLine, int lineIdx) {
    size_t commaCount = countChar(trimmedLine, ',');
    
    if (commaCount == 0 || commaCount > 1) {
        std::stringstream ss;
        if (commaCount == 0)
            ss << "line " << lineIdx << "- Missing comma separator. Expected 'date,rate', got '" << trimmedLine << "'";
        else
            ss << "line " << lineIdx << "- Too many commas. Expected 'date,rate', got '" << trimmedLine << "'";
        closeFileWithErr(file, ss.str());
    }
}

void                Utils::parsePipes(std::ifstream& file, const std::string& trimmedLine, int lineIdx) {
    size_t pipeCount = countChar(trimmedLine, '|');
    
    if (pipeCount == 0 || pipeCount > 1) {
        std::stringstream ss;
        if (pipeCount == 0)
            ss << "line " << lineIdx << "- Missing pipe separator. Expected 'date | value', got '" << trimmedLine << "'";
        else
            ss << "line " << lineIdx << "- Too many pipes. Expected 'date | value', got '" << trimmedLine << "'";
        closeFileWithErr(file, ss.str());
    }
}

void                Utils::parseEmptyLine(std::ifstream& file, const std::string& trimmedLine, int lineIdx) {
    if (trimmedLine.empty()) {
        std::stringstream ss;
        ss << "line " << lineIdx << "- Empty line or contains only whitespace";
        closeFileWithErr(file, ss.str());
    }
}


// Values validations
void                Utils::parseDate(std::ifstream& file, const std::string& date, int lineIdx) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-' || date < "2009-01-03") {
        std::stringstream ss;
        if (date.length() != 10 || date[4] != '-' || date[7] != '-')
            ss << "line " << lineIdx << "- Invalid date format '" << date << "'. Expected YYYY-MM-DD";
        else
            ss << "line " << lineIdx << "- Invalid date '" << date << "'. Bitcoin didn't exist before January 3, 2009";

        closeFileWithErr(file, ss.str());
    }
    
    int year, month, day;

    try {
        year = std::atoi(date.substr(0, 4).c_str());
        month = std::atoi(date.substr(5, 2).c_str());
        day = std::atoi(date.substr(8, 2).c_str());
    } catch (...) {
        std::stringstream ss;
        ss << "line " << lineIdx << "- Invalid date format '" << date << "'. Expected YYYY-MM-DD";
        closeFileWithErr(file, ss.str());
    }
    
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) {
        std::stringstream ss;
        ss << "line " << lineIdx << "- Invalid date values in '" << date << "'";
        closeFileWithErr(file, ss.str());
    }
    
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            std::stringstream ss;
            ss << "line " << lineIdx << "- Invalid day value in '" << date << "'. Month " << month << " has only 30 days";
            closeFileWithErr(file, ss.str());
        }
    } else if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > (isLeapYear ? 29 : 28)) {
            std::stringstream ss;
            ss << "line " << lineIdx << "- Invalid day value in '" << date << "'. February " << year;
            ss << (isLeapYear ? " (leap year) has only 29 days" : " has only 28 days");
            closeFileWithErr(file, ss.str());
        }
    }
}

void                Utils::parseRate(std::ifstream& file, const std::string& rateStr, float& rate, int lineIdx) {
    char* endptr;
    rate = std::strtof(rateStr.c_str(), &endptr);
    
    if (*endptr != '\0' || rate < 0 || rate > 1000000.0f) {
        std::stringstream ss;
        if (*endptr != '\0') // we check for parsing errors
            ss << "line " << lineIdx << "- Invalid exchange rate format '" << rateStr << "'. Expected a number";
        else if (rate < 0) // we check for negative values
            ss << "line " << lineIdx << "- Invalid exchange rate '" << rateStr << "'. Value cannot be negative";
        else // we check for unreasonably large values
            ss << "line " << lineIdx << "- Unreasonably large exchange rate '" << rateStr << "'";
        closeFileWithErr(file, ss.str());
    }
}

void                Utils::parseValue(std::ifstream& file, const std::string& valueStr, float& value, int lineIdx) {
    if (valueStr.empty()) {
        std::stringstream ss;
        ss << "Line " << lineIdx << " is missing a value after '|'";
        closeFileWithErr(file, ss.str());
    }
    
    char* endptr;
    value = std::strtof(valueStr.c_str(), &endptr);
    
    if (*endptr != '\0' || value < 0 || value > 1000) {
        std::stringstream ss;
        if (*endptr != '\0') {
            ss << "Line " << lineIdx << " has invalid value format. Expected a number, got '" << valueStr << "'";
        } else if (value < 0) {
            ss << "Line " << lineIdx << " has negative value: " << value << ". Value must be positive.";
        } else {
            ss << "Line " << lineIdx << " has value exceeding maximum: " << value << ". Maximum allowed is 1000.";
        }
        closeFileWithErr(file, ss.str());
    }
}


// Parse line functions
void                Utils::parseDbFileLine(std::ifstream& file, const std::string& trimmedLine, int lineIdx) {
    if (lineIdx == 1) 
        return (parseFileHeader(file, trimmedLine, "date,exchange_rate"));
    parseEmptyLine(file, trimmedLine, lineIdx);
    parseCommas(file, trimmedLine, lineIdx);
 
    std::istringstream  iss(trimmedLine);
    std::string         date;
    std::string         rateStr;
    float               rate;

    if (!std::getline(iss, date, ',')) {
        std::stringstream ss;
        ss << "line " << lineIdx << "- Missing date field. Expected 'date,rate', got '" << trimmedLine << "'";
        closeFileWithErr(file, ss.str());
    }

    date = trim(date);
    parseDate(file, date, lineIdx);



    if (!std::getline(iss, rateStr)) {
        std::stringstream ss;
        ss << "line " << lineIdx << "- Missing rate field. Expected 'date,rate', got '" << trimmedLine << "'";
        closeFileWithErr(file, ss.str());
    }
    
    rateStr = trim(rateStr);
    parseRate(file, rateStr, rate, lineIdx);
}

void                Utils::parseUserInputFileLine(std::ifstream& file, const std::string& trimmedLine, int lineIdx) {
    if (lineIdx == 1) 
       return (parseFileHeader(file, trimmedLine, "date | value"));
    parseEmptyLine(file, trimmedLine, lineIdx);
    parsePipes(file, trimmedLine, lineIdx);

    size_t pipePos = trimmedLine.find('|');
    if (pipePos == std::string::npos) {
        std::stringstream ss;
        ss << "Line " << lineIdx << " has invalid format. Expected 'date | value', got '" << trimmedLine << "'";
        closeFileWithErr(file, ss.str());
    }
    
    std::string date = trim(trimmedLine.substr(0, pipePos));
    std::string valueStr = trim(trimmedLine.substr(pipePos + 1));
    float       value;
    
    parseDate(file, date, lineIdx);
    parseValue(file, valueStr, value, lineIdx);
}
