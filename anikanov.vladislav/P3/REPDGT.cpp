#include "REPDGT.h"
#include <iostream>
#include <cstring>

int hasDuplicateDigits(const char *str)
{
  int entrance[10] = {0};
  for (size_t i = 0; i < strlen(str); ++i) {
    if (std::isdigit(str[i])) {
      entrance[str[i] - '0']++;
    }
  }
  int max_count = 0;
  for (int i: entrance) {
    max_count = std::max(max_count, i);
  }
  return max_count;
}
