#include <iostream>
#include "addSizeLine.hpp"
#include "comparisonLine.hpp"
#include "EQUAL_CHARS_FINDER.hpp"
#include "findRplSym.hpp"
#include "formingString.hpp"
#include "readingString.hpp"
#include "readLine.hpp"

using namespace rejepbayev::jasur;

int main() {
    std::cout << "Enter your string: ";
    size_t userLen = 0;
    char* userStr = readingString(std::cin, 10, 5);
    const char* staticStr = "example static text";
    size_t countMatches = resComparison(userStr, staticStr, strlen(userStr), strlen(staticStr));
    std::cout << "Number of characters matching with '" << staticStr << "': " << countMatches << std::endl;
    size_t equalPairsCount = counterOfEqualPairs(userStr, strlen(userStr));
    std::cout << "Number of equal character pairs: " << equalPairsCount << std::endl;
    delete[] userStr;
    return 0;
}
