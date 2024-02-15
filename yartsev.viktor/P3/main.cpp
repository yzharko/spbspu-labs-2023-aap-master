#include <iostream>
#include "stringwork.hpp"
#include "spaceremoval.hpp"
#include "unitestrings.hpp"

int main()
{
  char * str = new char [10000]{};
  try {
    yartsev::readString(str);
  } catch (const std::exception & e) {
    std::cerr << e.what() << "\n";
    delete [] str;
    return 1;
  }
  char * ans_spc_rmv = yartsev::removeSpaces(str);
  const char * uni_str = "abacaba";
  char * ans_uni_two = yartsev::uniteStrings(str, uni_str);
  if (ans_spc_rmv == nullptr) {
    std::cerr << "Not enougth memory to store string for [SPC-RMV]\n";
  }
  if (ans_uni_two == nullptr) {
    std::cerr << "Not enougth memory to store string for [UNI-TWO]\n";
  }
  if (ans_spc_rmv != nullptr && ans_uni_two != nullptr) {
    std::cout << ans_spc_rmv << "\n";
    std::cout << ans_uni_two << "\n";
  }
  delete [] str;
  delete [] ans_spc_rmv;
  delete [] ans_uni_two;
  return 0;
}
