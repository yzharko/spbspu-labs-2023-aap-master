#include <iostream>
#include "input_output.hpp"
int main()
{
  std::vector<std::string> text = seryj::readText(std::cin);
  CompositeShape cs(seryj::analyseText(text));
  seryj::writeAnswer(std::cout, cs);
  text.erase(text.begin(), text.end() - 3);
  cs.scale({ std::stod(text[0]), std::stod(text[1]) }, std::stod(text[2]));
  seryj::writeAnswer(std::cout, cs);
  return 0;
}
