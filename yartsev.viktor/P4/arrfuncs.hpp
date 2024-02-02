#ifndef ARRFUNCS_HPP
#define ARRFUNCS_CPP
#include <fstream>

namespace yartsev {
  int readArray(int * matrix, int cols, int rows, std::ifstream & in);
}

#endif