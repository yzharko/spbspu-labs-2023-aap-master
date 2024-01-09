#ifndef INPUTSTRING_HPP
#define INPUTSTRING_HPP
#include <iosfwd>

namespace reznikova
{
  char * readString(std::istream & in, size_t & size);
  char * addCapacity(char * string, size_t size, size_t add_size);
}

#endif
