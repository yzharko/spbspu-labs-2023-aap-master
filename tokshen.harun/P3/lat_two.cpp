#ifndef LAT_TWO_HPP
#define LAT_TWO_HPP
#include <cctype>
#include "lat_two.hpp"

namespace toksen
{
  bool contains(char* str, char c, size_t len) {
    for (int i = 0; i < len; ++i) {
    if (str[i] == c) return true;
    }
    return false;
    }

    void sortString(char* str, size_t len) {
      for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
          if (str[i] > str[j]) {
          char temp = str[i];
          str[i] = str[j];
          str[j] = temp;
          }
        }
      }
    }

    char* mergeLatinLetters(char* str1, char* str2) {
      int len1 = 0, len2 = 0;
      while (str1[len1] != '\0') ++len1;
      while (str2[len2] != '\0') ++len2;

      char* merged = new char[len1 + len2 + 1];
      int k = 0;

      for (int i = 0; i < len1; ++i) {
        if (isalpha(str1[i]) && !contains(merged, str1[i], k)) {
          merged[k++] = str1[i];
        }
      }

      for (int i = 0; i < len2; ++i) {
        if (isalpha(str2[i]) && !contains(merged, str2[i], k)) {
          merged[k++] = str2[i];
        }
      }

      merged[k] = '\0';
      sortString(merged, k);
      return merged;
    }
}
#endif
