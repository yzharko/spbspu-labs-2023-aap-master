#ifndef READLINE_HPP
#define READLINE_HPP
#include <iostream>
#include "comparisonLine.hpp"

namespace rejepbayev {
  char* readLine(std::istream& input, char* str, size_t& userLen);
}

#endif
