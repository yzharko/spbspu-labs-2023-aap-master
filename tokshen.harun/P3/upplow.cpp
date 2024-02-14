#include "upplow.hpp"
#include <cctype>
#include <cstddef>

namespace toksen
{
  void convertToLower(const char* source, char* destination, size_t size) {

    for (size_t i = 0; i < size; i++) {
      destination[i] = tolower(source[i]);
    }
      destination[size] = '\0';
    }
}
