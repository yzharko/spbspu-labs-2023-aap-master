#ifndef FUNCS_HPP
#define FUNCS_HPP
#include <cstddef>
#include <fstream>
namespace seryj
{
  size_t fillArray(size_t max_size, size_t to_read, std::ifstream &, int *);
}
#endif
