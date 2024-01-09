#include <iostream>
#include <cstring>
#include <string.h>
#include <algorithm>
#include "dinString.hpp"

int main()
{
  using namespace mihalchenko;

  char element = 0;

  DinString s1(1);
  DinString s2(1);

  std::cin >> std::noskipws;

  while ((std::cin >> element) && (element != '\n'))
  {
    if (s1.getCounterCurrent() < s1.getSize())
    {
      s1.dinAppend(element);
    }
    else
    {
      try
      {
        s1.dinResize();
        s1.dinAppend(element);
      }
      catch (const std::exception &e)
      {
        std::cerr << e.what() << '\n';
        return 1;
      }
    }
  }

  if (s1.getCounterCurrent() == 0)
  {
    std::cerr << "Wrong input\n";
    return 2;
  }

  std::cin >> std::noskipws;

  while ((std::cin >> element) && (element != '\n'))
  {
    if (s2.getCounterCurrent() < s2.getSize())
    {
      s2.dinAppend(element);
    }
    else
    {
      try
      {
        s2.dinResize();
        s2.dinAppend(element);
      }
      catch (const std::exception &e)
      {
        std::cerr << e.what() << '\n';
        return 1;
      }
    }
  }

  if (s2.getCounterCurrent() == 0)
  {
    std::cerr << "Wrong input\n";
    return 2;
  }

  char *resultStr = nullptr;

  size_t sizeDin1 = std::find(s1.getDinstr(), s1.getDinstr() + s1.getSize(), '\0') - s1.getDinstr();
  size_t sizeDin2 = std::find(s2.getDinstr(), s2.getDinstr() + s2.getSize(), '\0') - s2.getDinstr();
  size_t minLength = 0;

  try
  {
    (sizeDin1 > sizeDin2) ? (minLength = sizeDin2) : (minLength = sizeDin1);
    resultStr = new char[minLength];
    minLength = findIdenticalChars(s1.getDinstr(), s2.getDinstr(), sizeDin1, sizeDin2, resultStr);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }

  for (size_t i = 0; i < minLength; i++)
  {
    std::cout << resultStr[i];
  }
  std::cout << std::endl;

  if (resultStr != nullptr)
  {
    delete[] resultStr;
  }

  return 0;
}
