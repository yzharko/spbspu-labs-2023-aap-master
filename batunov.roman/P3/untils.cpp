#include "untils.hpp"
#include <unordered_map>

std::string batunov::getUniqueSymbols(const std::string& str)
{
  std::unordered_map<char, int> charCount;
  std::string uniqueSymbols;
  for (char c : str)
  {
    charCount[c]++;
  }
  for (char c : str)
  {
    if (charCount[c] > 1 && uniqueSymbols.find(c) == std::string::npos)
    {
      uniqueSymbols += c;
    }
  }
  return uniqueSymbols;
}
