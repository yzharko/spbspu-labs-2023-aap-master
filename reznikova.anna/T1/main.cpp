#include <iostream>
#include <string>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "ring.hpp"
#include "regular.hpp"
#include "set_figures.hpp"
#include "array_functions.hpp"
#include "scale_figures.hpp"
#include "string_process.hpp"

int main()
{
  using namespace reznikova;
  int scale_command = 0;
  Shape * figures[1000] = {0};
  std::string line = "";
  std::string name = "";
  int stored = 0;
  bool ifNoErrors = 1;

  while (!std::cin.eof())
  {
    std::cin >> name;
    getline(std::cin, line);
    if (name == "RING")
    {
      figures[stored++] = setRing(line, ifNoErrors);
    }
    else if (name == "REGULAR")
    {
      figures[stored++] = setRegular(line, ifNoErrors);
    }
    else if (name == "RECTANGLE")
    {
      figures[stored++] = setRectangle(line, ifNoErrors);
    }
    else if (name == "SCALE")
    {
      scale_command = 1;
      try
      {
        scaleFigures(figures, stored, line);
      }
      catch (const std::runtime_error &e)
      {
        std::cerr << e.what();
        return 1;
      }
      break;
    }
    if (ifNoErrors == 0)
    {
      ifNoErrors = 1;
      delete figures[stored-1];
      stored -= 1;
    }
  }
  freeArray(figures, stored);
  if (scale_command == 0)
  {
    std::cerr << "no scale command\n";
    return 1;
  }
  return 0;
}
