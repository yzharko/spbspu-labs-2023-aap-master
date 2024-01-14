#ifndef INPUT_AR_HPP
#define INPUT_AR_HPP
#include <iosfwd>

namespace lisitsyna
{
  size_t input_ar(std::ifstream& in, int* values, size_t sizeMatrix);
}
#endif
