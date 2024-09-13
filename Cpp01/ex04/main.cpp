#include <iostream> // std::cout, std::cerr
#include <fstream>  // std::ifstream, std::ofstream
#include <sstream>  // std::stringstream
#include <string>   // std::string

int printErr(const std::string& errMsg) {
    std::cerr << "\n\033[1m\033[31m" << "Error: " << errMsg << "\033[0m\n";
    return 1;
}

int printSuccess(const std::string& filename) {
    std::cout << "\n\033[1m\033[32mReplacement completed successfully and written to " + filename + ".replace \033[0m\n"; 
    return 0;
}

bool openInputFile(std::ifstream &file, const std::string &filename) {
    file.open(filename.c_str());
    return file.is_open();
}

bool openOutputFile(std::ofstream &file, const std::string &filename) {
    file.open(filename.c_str());
    return file.is_open();
}

std::string readFile(std::ifstream &file) {
    std::stringstream buffer;
    
    buffer << file.rdbuf();  // Read entire file into the buffer
    return buffer.str();    // Get the content as a string
}

std::string replaceOccurrences(const std::string &content, const std::string &s1, const std::string &s2) {
    std::string modifiedContent;
    size_t pos = 0, findPos;

    while ((findPos = content.find(s1, pos)) != std::string::npos) {
        modifiedContent += content.substr(pos, findPos - pos);
        modifiedContent += s2;
        pos = findPos + s1.length();
    }

    modifiedContent += content.substr(pos);

    return modifiedContent;
}


int main(int argc, char **av) {
    if (argc != 4) return printErr("Invalid number of arguments");

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    if (s1.empty()) return printErr("The string to be replaced cannot be empty.");

    std::ifstream inputFile;
    if (!openInputFile(inputFile, filename))
        return printErr("Cannot open file " + filename);

    std::string content = readFile(inputFile);
    inputFile.close();

    std::string modifiedContent = replaceOccurrences(content, s1, s2);

    std::ofstream outputFile;
    if (!openOutputFile(outputFile, filename + ".replace")) 
        return printErr("Cannot create file " + filename + ".replace");

    outputFile << modifiedContent;
    outputFile.close();

    return printSuccess(filename);
}

/*
    findPos = content.find(s1, pos):
        This finds the next occurrence of the substring s1 in the content, starting the search from the position pos. If it finds s1, it returns the index where s1 starts. If it doesn't find s1, it returns std::string::npos.

    modifiedContent += content.substr(pos, findPos - pos);:
        This adds the substring starting at pos and ending at findPos (but not including findPos) to modifiedContent. In other words, it appends the part of content between pos and findPos, which is the part before the occurrence of s1.

    modifiedContent += s2;:
        After appending the content before s1, this line adds the replacement string s2 to modifiedContent, effectively replacing s1 with s2.
    
    Update pos:
        The position pos is updated to findPos + s1.length() to move past the last occurrence of s1, so the next search starts right after the replaced substring.
    
    Continue Finding Occurrences:
        The loop repeats the process, finding the next occurrence of s1, appending the part before it, replacing it with s2, and updating pos.
    
    If No More Occurrences:
        When content.find(s1, pos) returns std::string::npos (i.e., s1 is no longer found), the loop exits.
    
        Then: The remaining content from pos to the end of the string (which doesn't contain s1 anymore) is added to modifiedContent with modifiedContent += content.substr(pos).
*/
