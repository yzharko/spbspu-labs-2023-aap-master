#include <iostream>
#include "EQUAL_CHARS_FINDER.hpp"
int main()
{
  try
  {
    size_t real_size = 0;
    char* line = seryj::readLine(real_size);
    size_t answer = seryj::counterOfEqualPairs(line, real_size);
    std::cout << "Found " << answer << " pair" << (answer != 1 ? "s" : "") << " of equal symbols\n";
    delete[] line;
    return 0;
  }
  catch (std::logic_error const& e)
  {
    std::cerr << e.what();
    return 1;
  }
}
