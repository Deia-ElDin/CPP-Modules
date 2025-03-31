#ifndef __UTILS_HPP__
# define __UTILS_HPP__

#include <iostream>
#include <string>
#include <sstream> 
#include <stdexcept> // std::runtime_error
#include <fstream>  // std::ifstream
#include <cmath>

namespace Utils 
{
    // Console output
    void        printMsg(const std::string& msg, const std::string& color);
    void        printErr(const std::string& msg);
    void        printSeparator(void);
    void        throwErr(const std::string& msg);
    
    // String operations
    std::string trim(const std::string& str);
    size_t      countChar(const std::string& str, char c);

    // File operations
    void        openFile(std::ifstream& file, const std::string& filename, bool escapeLine = false);
    void        closeFileWithErr(std::ifstream& file, const std::string& errMsg);
    
    // Datebase file validations
    void        parseDbFileLine(std::ifstream& file, const std::string& trimmedLine, int lineIdx);
    void        parseDbFileDate(std::ifstream& file, const std::string& date, int lineIdx);
    void        parseDbFileRate(std::ifstream& file, const std::string& rateStr, float& rate, int lineIdx);
    void        parseCommas(std::ifstream& file, const std::string& trimmedLine, int lineIdx);

    // User Input File validations
    bool        parseUserInputFileLine(const std::string& line, int lineIdx, std::string& date, float& value, std::string& errorMsg);
    bool        parseUserDate(const std::string& date, std::string& errorMsg);
    bool        parseUserValue(const std::string& valueStr, float& value, std::string& errorMsg);
    void        parsePipes(std::ifstream& file, const std::string& trimmedLine, int lineIdx);

// Header and Empty lines
    void        parseFileHeader(std::ifstream& file, const std::string& trimmedLine, const std::string& header);
    void        parseEmptyLine(std::ifstream& file, const std::string& trimmedLine, int lineIdx);
    
    template <typename T>
    std::string toStr(T value) {
        std::stringstream ss;
        
        ss << value;
        return ss.str();
    }
}

#endif
