#include <iostream>
#include "stringwork.hpp"
#include "spaceremoval.hpp"

int main()
{
  char * str = new char [10000]{};
  try {
    yartsev::readString(str);
  } catch (std::logic_error & e) {
    std::cerr << e.what() << "\n";
    delete [] str;
    return 2;
  } catch (std::bad_alloc & e) {
    std::cerr << e.what() << "\n";
    delete [] str;
  }
  char * ans1 = yartsev::removeSpaces(str);
  std::cout << ans1 << "\n";
  delete [] str;
  delete [] ans1;
  return 0;
}
