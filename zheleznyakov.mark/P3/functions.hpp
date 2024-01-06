#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <cstddef>

namespace zheleznyakov
{
  size_t readLine(char * input);
  bool findSymbol(const char * str, int c);
  size_t findNonDuplicateChars(char * dest, char * str1, const char * str2, size_t size1, size_t size2);
  size_t removeLetters(char * dest, char * str, size_t size);
};
#endif
