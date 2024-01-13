#include <iostream>
#include "noInt.hpp"
#include "newLine.hpp"

int main()
{
  using namespace popov;
  int len = 0;
  char * input = newLine(len);
  char * res = new char[len]{};
  noInt(res, input, len);
  std::cout << res << '\n';
  delete [] input;
  delete [] res;
  return 0;
}
