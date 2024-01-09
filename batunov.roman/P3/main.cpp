#include <iostream>
#include <string>
#include <cstdlib>
#include "commonSymbols.hpp"
#include "untils.hpp"

int main()
{
  std::string str;
  std::getline(std::cin, str);
  std::string* str1 = new(std::nothrow) std::string("abc ef");
  if (str1 == nullptr)
  {
    std::cerr << "Error: memory cannot be allocated.\n";
    exit(1);
  }
  std::string* str2 = new(std::nothrow) std::string(str);
  if (str2 == nullptr)
  {
    std::cerr << "Error: memory cannot be allocated.\n";
    exit(1);
  }
  if (str2->empty())
  {
    std::cerr << "Error: empty string.\n";
    exit(1);
  }
  std::string result1 = batunov::findCommonSymbols(*str1, *str2);
  std::cout << "Var 1:\n" << result1 << std::endl;
  delete str1;
  delete str2;
  std::string result2 = batunov::getUniqueSymbols(str);
  std::cout << "Var 2:\n" << result2 << std::endl;
  return 0;
}
