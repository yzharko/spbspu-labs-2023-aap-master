#ifndef INPUTSTRING_HPP
#define INPUTSTRING_HPP
#include <iosfwd>

namespace sukacheva
{
  char* inputString(std::istream& in, size_t& read);
}

#endif
