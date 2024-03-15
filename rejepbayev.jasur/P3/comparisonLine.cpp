#include "comparisonLine.hpp"

size_t rejepbayev::resComparison(char* userStr, const char* staticStr, size_t userLen, size_t staticLen) {
  size_t count = 0;
  for (size_t i = 0; i < userLen; i++)
  {
    for (size_t j = 0; j < staticLen; j++)
    {
      if (userStr[i] == staticStr[j] && userStr[i] != ' ')
      {
        count++;
        break;
      }
    }
  }
  return count;
}
