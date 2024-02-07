#include <cstring>
#include "readLine.hpp"

using namespace nikiforov;
int main()
{
  char* userStr = new char[0] {};
  const char* staticStr = "abs";
  std::cin >> std::noskipws;

  size_t userLen = 0;
  size_t staticLen = strlen(staticStr);

  userStr = nikiforov::readLine(std::cin, userStr, userLen);

  std::cin >> std::skipws;
  if (userLen == 0)
  {
    std::cerr << "Too short sequence\n";
    delete[] userStr;
    return 1;
  }
  std::cout << '\n' << nikiforov::resComparison(userStr, staticStr, userLen, staticLen) << '\n';
  delete[] userStr;
  return 0;
}
