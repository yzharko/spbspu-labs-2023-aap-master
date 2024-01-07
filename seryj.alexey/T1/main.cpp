#include <iostream>
#include "input_output.hpp"
int main()
{
  std::string error = "";
  std::vector<std::string> text;
  CompositeShape cs;
  try
  {
    text = seryj::readText(std::cin);
    seryj::textToCompositeShape(text, cs);
  }
  catch (std::invalid_argument const& e)
  {
    std::cerr << e.what();
    return 2;
  }
  catch(std::logic_error const & e)
  {
    error = e.what();
  }
  try
  {
    seryj::writeAnswer(std::cout, cs);
    text.erase(text.begin(), text.end() - 3);
    cs.scale({ std::stod(text[0]), std::stod(text[1]) }, std::stod(text[2]));
  }
  catch (std::invalid_argument const& e)
  {
    std::cerr << e.what();
    return 2;
  }
  seryj::writeAnswer(std::cout, cs);
  if (error.length() > 0)
    std::cerr << error << '\n';
  return 0;
}
