#ifndef INPUT_ANALYSIS_HPP
#define INPUT_ANALYSIS_HPP
#include <string>
#include "composite_shape.hpp"
namespace seryj
{
  void writeAnswer(std::ostream& out, CompositeShape& cs);
  std::vector<std::string> readText(std::istream&);
  std::vector<Shape*> analyseText(std::vector<std::string>);
  void skipShape(std::vector<std::string>&);
}
#endif
