#include <limits>
#include <algorithm>
#include <cctype>
#include "frqtopLine.hpp"

char khoroshkin::findFirstMax(std::map<char, int> Dict)
{
  std::pair<char, int> FirstMaxPair;
  int maxValue = std::numeric_limits< int >::min();
  for (const auto & pair : Dict)
  {
    if (maxValue < pair.second)
    {
      maxValue = pair.second;
      FirstMaxPair = pair;
    }
  }
  return FirstMaxPair.first;
}

char khoroshkin::findOtherMax(std::map<char, int> Dict, int previousMaxChar, char first, char second)
{
  std::pair<char, int> OtherMaxPair;
  int maxValue = std::numeric_limits< int >::min();
  for (const auto & pair : Dict)
  {
    if (maxValue < pair.second && pair.second <= previousMaxChar && pair.first != first && pair.first != second)
    {
      maxValue = pair.second;
      OtherMaxPair = pair;
    }
  }
  return OtherMaxPair.first;
}

void khoroshkin::generateNewString(std::map<char, int> dict, char * newString)
{
  char firstMaxChar = findFirstMax(dict);
  newString[0] = firstMaxChar;
  char secondMaxChar = findOtherMax(dict, dict[firstMaxChar], newString[0]);
  newString[1] = secondMaxChar;
  char thirdMaxChar = findOtherMax(dict, dict[secondMaxChar], newString[0], newString[1]);
  newString[2] = thirdMaxChar;
  std::sort(newString, newString+3);
  newString[3] = '\0';
}

void khoroshkin::getFrequency(const char * line, int length, char * newString)
{
  std::map<char, int> CharFrequency;
  for (int i = 0; i < length; i++)
  {
    if (std::isalpha(line[i]) && line[i] != ' ')
    {
      CharFrequency[std::tolower(line[i])]++;
    }
  }
  generateNewString(CharFrequency, newString);
}
