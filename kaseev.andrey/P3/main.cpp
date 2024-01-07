#include <iostream>
#include "WorkWithString.hpp"

int main()
{
  const char* str1 = kaseev::readLine();
  const char* str2 = "def ";
  if (str1[0] == '\0')
  {
    std::cerr << "Wrong input";
    delete[] str1;
    return 1;
  }
  try
  {
    char *newStr = kaseev::interleaveStrings(str1, str2);
    delete[] str1;
    if (newStr == nullptr)
    {
      throw std::logic_error("Impossible to convert");
    }
    std::cout << newStr;
    delete[] newStr;
    return 0;
  }
  catch (std::exception &err)
  {
    std::cerr << err.what() << "\n";
    return 1;
  }
}
