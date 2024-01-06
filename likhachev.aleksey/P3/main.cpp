#include <iostream>
#include "sequences.hpp"

int main()
{
  char *line = nullptr;
  int size = 0;
  char *noDigitsline = nullptr;
  int ndlSize = 0;
  char subString[10]{"abc"};
  try
  {
    line = likhachev::readSequence(size);

    if (size == 0) {
      std::cerr << "There are no symbols here, my dude :L ";
      delete[] line;
      return 1;
    }

    int hasSame = likhachev::strDoesHasSame(line, size, subString, 3);
    noDigitsline = likhachev::strRemoveDigits(size, line, ndlSize);

    std::cout << "\n";
    std::cout << "String";
    if (!hasSame) {
      std::cout << " do not";
    }
    std::cout << " have a common characters.\n";

    std::cout << "The string received after deleting the digits: ";
    likhachev::outLine(noDigitsline, ndlSize);

    delete[] line;
    delete[] noDigitsline;
    return 0;
  }
  catch (std::logic_error const& e)
  {
    std::cerr << e.what();
    delete[] line;
    delete[] noDigitsline;
    return 1;
  }
}
