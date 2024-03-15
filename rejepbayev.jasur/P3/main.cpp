#include <iostream>
#include "readLine.hpp"
#include "addSizeLine.hpp"
#include "comparisonLine.hpp"

int main() {
    rejepbayev::AddSizeLine addSizeLine;
    rejepbayev::ComparisonLine comparisonLine;

    size_t userLen = 0;
    char* userStr = new char[10]; // Initial size
    std::cout << "Enter your string: ";
    userStr = rejepbayev::readLine(std::cin, userStr, userLen);

    const char* staticStr = "example";
    size_t staticLen = 7;

    size_t count = comparisonLine.resComparison(userStr, staticStr, userLen, staticLen);
    std::cout << "Number of matching characters: " << count << std::endl;

    delete[] userStr;
    return 0;
}
