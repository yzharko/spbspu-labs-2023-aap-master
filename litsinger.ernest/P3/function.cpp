#include "function.hpp"
#include <cctype>

int FindSymvol(const std::string& input, char a)
{
  size_t count = 0;
  for (char c : input)
  {
    if (a == c)
    {
      count++;
    }
  }
  return count;
}
std::string CreateString(const std::string& input) 
{
  std::string result;
  for (char c : input) 
  {
    if (FindSymvol(input, c) >= 2 && FindSymvol(result, c) == 0)
    {
      result += c;
    }
  }
  return result;
}
