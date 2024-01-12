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

int main()
{
  using namespace reznikova;
  bool scale_command = 0;
  Shape * figures[1000] = {0};
  std::string name = "";
  int stored = 0;
  bool ifNoErrors = 1;

  while (!std::cin.eof())
  {
    std::cin >> name;
    if (name == "RING")
    {
      figures[stored++] = setRing(std::cin, ifNoErrors);
    }
    else if (name == "REGULAR")
    {
      figures[stored++] = setRegular(std::cin, ifNoErrors);
    }
    else if (name == "RECTANGLE")
    {
      figures[stored++] = setRectangle(std::cin, ifNoErrors);
    }
    else if (name == "SCALE")
    {
      scale_command = 1;
      try
      {
        scaleFigures(figures, stored, std::cin);
      }
      catch (const std::runtime_error &e)
      {
        std::cerr << e.what();
        return 1;
      }
      freeArray(figures, stored);
      break;
    }

    if (ifNoErrors == 0)
    {
      ifNoErrors = 1;
      delete figures[stored-1];
      stored -= 1;
    }
  }

  if (scale_command == 0)
  {
    freeArray(figures, stored+1);
    std::cerr << "no scale command\n";
    return 1;
  }
  return 0;
}
