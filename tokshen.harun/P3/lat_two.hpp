#ifndef LAT_WTO_HPP
#define LAT_TWO_HPP
#include <cctype>
#include <cstddef>

namespace toksen
{
  bool contains(char* str, char c, size_t len);
  void sortString(char* str, size_t len);
  char* mergeLatinLetters(char* str1, char* str2);
}
#endif
