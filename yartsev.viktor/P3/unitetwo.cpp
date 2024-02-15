#include "unitetwo.hpp"
#include <cstring>
#include <new>

char * yartsev::uniteTwoStrings(const char * a, const char * b)
{
  char * new_str = nullptr;
  try {
    new_str = new char [strlen(a) + strlen(b) + 1]{};
  } catch (const std::bad_alloc & e) {
    return nullptr;
  }
  size_t new_str_length = 0;
  size_t ptr_a = 0;
  size_t ptr_b = 0;
  while ((a[ptr_a] != '\0') || (b[ptr_b] != '\0')) {
    if (b[ptr_b] == '\0') {
      new_str[new_str_length++] = a[ptr_a++];
    } else if (a[ptr_a] == '\0') {
      new_str[new_str_length++] = b[ptr_b++];
    } else if (ptr_a <= ptr_b) {
      new_str[new_str_length++] = a[ptr_a++];
    } else {
      new_str[new_str_length++] = b[ptr_b++];
    }
  }
  return new_str;
}
