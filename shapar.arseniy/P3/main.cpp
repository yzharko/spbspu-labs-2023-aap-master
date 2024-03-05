#include <iostream>

int main() {

  char chr = 0;
  size_t read = 0;
  char * input = new char[10];
  std::cin >> std::noskipws;
  while ((std::cin >> chr) && (chr != '\n'))
  {
    input[read++] = chr;
  }
  std::cin >> std::skipws;
  std::cout << input << "\n";
  delete [] input;
  return 0;
}
