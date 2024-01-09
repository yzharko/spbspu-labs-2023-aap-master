#ifndef FUNCTIONINPUT_HPP
#define FUNCTIONINPUT_HPP
#include <cstddef>
#include <fstream>
namespace litsinger
{
  size_t inputArray(std::ifstream & input, int * matrix, size_t sizeMatrix);
}
#endif
