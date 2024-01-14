#include "commonSymbols.hpp"

std::string batunov::findCommonSymbols(const std::string& str1, const std::string& str2)
{
  std::string commonSymbols;
  for (char c : str1)
  {
    if (str2.find(c) != std::string::npos && commonSymbols.find(c) == std::string::npos)
    {
      commonSymbols += c;
    }
  }
  return commonSymbols;
}
