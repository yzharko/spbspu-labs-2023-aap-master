#include "function.hpp"
#include <cctype>
#include <iostream>

void function(char* input) {
  if (input == nullptr || input[0] == '\0') {
    exit(1);
  }

  int len = 0;
  while (input[len] != '\0') {
    len++;
  }

  int index = 0;

  for (int i = 0; i < len; i++) {
    char c = input[i];
    if (char(c) && c != 'A' && c != 'O' && c != 'E' && c != 'I' && c != 'U' && c != 'Y' &&
      c != 'a' && c != 'o' && c != 'e' && c != 'i' && c != 'u' && c != 'y') {
      input[index++] = c;
    }
    else if (c == ' ') {
      input[index++] = c;
    }
  }

  input[index] = '\0';
}
