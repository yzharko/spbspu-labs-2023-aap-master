#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <map>

namespace khoroshkin
{
  int inputLine(char *& line, size_t capacity);
  char findFirstMax(std::map<char, int> dict);
  char findOtherMax(std::map<char, int> dict, int previousMaxChar, char first = '\0', char second = '\0');
  char * generateNewString(std::map<char, int> dict);
  char * getFrequency(char * line, int length);
  char * generateNewWithTwo(char * firstLine, char * secondLine, size_t size1, size_t size2);
}

#endif
