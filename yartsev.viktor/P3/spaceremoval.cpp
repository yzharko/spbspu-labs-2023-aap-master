#include "spaceremoval.hpp"
#include <cstring>
#include <cctype>

char * yartsev::removeSpaces(const char * str) 
{
  size_t str_length = strlen(str);
  char * new_str = new char [str_length + 1]{};
  size_t new_str_length = 0;
  for (int i = 0; i < str_length; i++) {
    if (isblank(str[i]) && new_str_length != 0 && !isblank(new_str[new_str_length - 1])) {
      new_str[new_str_length++] = ' ';
    } else if (!isblank(str[i])) {
      new_str[new_str_length++] = str[i];
    }
  }
  if (isblank(new_str[new_str_length - 1])) {
    new_str_length--;
  }
  new_str[new_str_length] = '\0';
  return new_str;
}
