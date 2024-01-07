#ifndef FRQTOPLINE_HPP
#define FRQTOPLINE_HPP
#include <map>

namespace khoroshkin
{
  char findFirstMax(std::map<char, int> Dict);
  char findOtherMax(std::map<char, int> Dict, int previousMaxChar, char first = '\0', char second = '\0');
  void generateNewString(std::map<char, int> Dict, char * newString);
  void getFrequency(const char * line, int length, char * newString);
}

#endif
