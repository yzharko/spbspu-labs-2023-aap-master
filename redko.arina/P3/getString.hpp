#ifndef GETSTRING_HPP
#define GETSTRING_HPP
#include <istream>

namespace redko
{
  char * getString(std::istream & in, int & len);
}

#endif
