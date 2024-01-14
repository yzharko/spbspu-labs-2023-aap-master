#ifndef STRING_HPP
#define STRING_HPP
#include "cstddef"
#include <istream>

namespace miheev
{
  size_t readString(char **receiver, std::istream& stream);
}

#endif
