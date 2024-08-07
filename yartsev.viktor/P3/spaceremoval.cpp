#include "spaceremoval.hpp"
#include <cstring>
#include <cctype>
#include <new>

char * yartsev::removeSpaces(const char * str)
{
  size_t str_length = strlen(str);
  size_t new_str_length = 0;
  char * new_str = nullptr;
  try {
    new_str = new char [str_length + 1]{};
  } catch (const std::bad_alloc & e) {
    return nullptr;
  }
  for (size_t i = 0; i < str_length; i++) {
    if (isblank(str[i]) && new_str_length != 0 && !isblank(new_str[new_str_length - 1])) {
      new_str[new_str_length++] = ' ';
    } else if (!isblank(str[i])) {
      new_str[new_str_length++] = str[i];
    }
  }
  if (new_str_length != 0 && isblank(new_str[new_str_length - 1])) {
    new_str_length--;
  }
  new_str[new_str_length] = '\0';
  return new_str;
}
