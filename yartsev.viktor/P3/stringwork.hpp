#ifndef STRINGWORK_HPP
#define STRINGWORK_HPP
#include <cstddef>

namespace yartsev {
  void readString(char * str);
  size_t resizeString(char *& str, const size_t curr_size);
}

#endif