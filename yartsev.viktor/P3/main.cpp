#include <iostream>
#include "stringwork.hpp"
#include "spaceremoval.hpp"
#include "unitetwo.hpp"

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
    return 1;
  }
  char * ans1 = yartsev::removeSpaces(str);
  char uni_str[] = "def_";
  char * ans2 = yartsev::uniteTwoStrings(str, uni_str);
  std::cout << ans1 << "\n";
  std::cout << ans2 << "\n";
  delete [] str;
  delete [] ans1;
  delete [] ans2;
  return 0;
}
