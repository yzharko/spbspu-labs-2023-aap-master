#include <iostream>
#include <string>
#include <sstream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "complexquad.hpp"

int main()
{
  std::string inputLine;
  while (std::getline(std::cin, inputLine))
  {
    if (std::cin.eof())
    {
      return 1;
    }
    std::string type;
    std::istringstream input(inputLine);
    input >> type;
    if (type == "RECTANGLE")
    {
      double leftLow1, leftLow2, rightHigh1, rightHigh2;
      input >> leftLow1 >> leftLow2 >> rightHigh1 >> rightHigh2;

    }
    else if (type == "CIRCLE")
    {
      double center1, center2, radius;
      if (radius <= 0)
      {

      }
      input >> center1 >> center2 >> radius;

    }
    else if (type == "COMPLEXQUAD")
    {
      double firstSide1, firstSide2, secondSide1, secondSide2;
      input >> firstSide1 >> firstSide2 >> secondSide1 >> secondSide2;

    }
    else
    {
      std::cout << inputLine;
    }
  }
  return 0;
}
