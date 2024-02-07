#include "RMVVOW.h"
#include <cctype>

bool isVowel(char c)
{
  c = std::tolower(c);
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void dropVowels(char *to_copy, const char *line)
{
  size_t j = 0;
  for (size_t i = 0; i < strlen(line) && line[i] != '\0'; ++i) {
    if (!isVowel(line[i])) {
      to_copy[j++] = line[i];
    }
  }
  to_copy[j] = '\0';
}
