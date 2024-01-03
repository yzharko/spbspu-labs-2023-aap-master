#include <iostream>
#include "comparison.hpp"
#include "delvow.hpp"
#include "addarr.hpp"
#include "delzero.hpp"

int main()
{
  std::cin >> std::noskipws;
  size_t sizeStr = 1;
  char* str = new char[1]{};
  bool endin = 1;
  while (endin)
  {
    try
    {
      addarr(std::cin, str, sizeStr, endin);
    }
    catch (const std::exception& ex)
    {
      std::cerr << "Could not read an element of the string\n";
      return 1;
    }
  }
  delzero(str, sizeStr);
  std::cout << "[HAS-SAM]: " << arr::comparison(str, sizeStr, "abc") << '\n';
  arr::delVow(str, sizeStr);
  std::cout << "[RMV-VOW]: ";
  std::cin >> std::skipws;
  delete[] str;
  return 0;
}
