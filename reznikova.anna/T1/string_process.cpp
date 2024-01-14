#include "string_process.hpp"
#include <iostream>
#include <string>
#include "base-types.hpp"

double reznikova::getNextValue(std::string& line)
{
  size_t ptr = 0;
  double value = std::stod(line, &ptr);
  line = line.substr(ptr);
  return value;
}

reznikova::point_t reznikova::getPointFromString(std::string& line)
{
  size_t fir_ptr = 0;
  size_t sec_ptr = 0;
  double x = std::stod(line, &fir_ptr);
  line = line.substr(fir_ptr);
  double y = std::stod(line, &sec_ptr);
  line = line.substr(sec_ptr);
  point_t point{x, y};
  return point;
}
