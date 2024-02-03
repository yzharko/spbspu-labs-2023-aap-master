#ifndef EXCLUDESECSTRING_HPP
#define EXCLUDESECSTRING_HPP
#include <iosfwd>

namespace reznikova
{
  char * ExcludeSecString(char * first_str, char * sec_str, size_t first_size, size_t sec_size);
}

#endif
