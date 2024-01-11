#include <iostream>
#include "maxLen.hpp"

int main()
{
  psarev::maxLen myMaxLen;
  std::cin.exceptions(std::istream::failbit);
  int value = 0;

  do {
    try {
      std::cin >> value;
      myMaxLen(value);
    }
    catch (const std::logic_error& e)
    {
      std::cerr << e.what();
      return 2;
    }
    catch (const std::istream::failure& e)
    {
      std::cerr << "Error: Wrong input!\n";
      return 1;
    }
  } while (value != 0);

  std::cout << myMaxLen() << "\n";
  return 0;
}
