#include "errorsPrint.h"
#include <iostream>
#include <cstring>

void printErrorByErrcode(std::ostream &cout, const char *code)
{
  if (strcmp(code, "1") != 0) {
    return wrongCountParams(cout);
  }
  if (strcmp(code, "2") != 0) {
    return invalidInput(cout);
  }
  if (strcmp(code, "3") != 0) {
    return invalidFirstArgument(cout);
  }
}

void wrongCountParams(std::ostream &cout)
{
  cout << "Wrong count of params\n";
}

void invalidInput(std::ostream &cout)
{
  cout << "Invalid input\n";
}

void invalidFirstArgument(std::ostream &cout)
{
  cout << "Invalid first argument\n";
}
