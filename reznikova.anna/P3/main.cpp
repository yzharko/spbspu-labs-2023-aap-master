#include <iostream>
#include <cstring>
#include "InputString.hpp"
#include "ExcludeSecString.hpp"

int main() {

  size_t size = 30;

  char * first_string = nullptr;
  try
  {
    first_string = reznikova::readString(std::cin, size);
  }
  catch (const std::runtime_error & e)
  {
    delete [] first_string;
    std::cerr << e.what() << "\n";
    return 1;
  }

  char second_string[3] = {'a', 'b', ' '};
  size_t first_size = strlen(first_string);
  size_t second_size = strlen(second_string);
  char * result_string = reznikova::ExcludeSecString(first_string, second_string, first_size, second_size);

  std::cout << result_string << "\n";

  delete [] first_string;
  delete [] result_string;

  return 0;
}
