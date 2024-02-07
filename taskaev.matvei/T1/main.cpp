#include <iostream>
#include <string>
#include "ellipse.hpp"
#include "Shape.hpp"
#include "concave.hpp"
#include "rectangle.hpp"
#include "baseTypes.hpp"

int main()
{
  using namespace taskaev;
  std::string figur = "";
  while (!std::cin.eof())
  {
    std::cin >> figur;
    if (figur == "RECTANGLE")
    {
      double x1;
      double y1;
      double x2;
      double y2;
      std::cin >> x1 >> y1 >> x2 >> y2;
      try
      {
        Shape* rectangle = new Rectangle({x1, y1}, {x2, y2});
      }
      catch (const std::logic_error& e)
      {
        std::cerr << e.what();
        delete[] rectangle;
        return 1;
      }
    }
    else if (figur == "ELLIPSE")
    {
      double x;
      double y;
      double radVer;
      double radGor;
      std::cin >> x >> y >> radVer >> radGor;
      try
      {
        Shape* ellipse = new Ellipse({x, y}, radVer, radGor);
      }
      catch (const std::logic_error& e)
      {
        std::cerr << e.what();
        delete[] ellipse;
        return 1;
      }
    }
    else if (figur == "CONCAVE")
    {
      double x1;
      double y1;
      double x2;
      double y2;
      double x3;
      double y3;
      double x4;
      double y4;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
      try
      {
        Shape* concave = new Concave({x1, y1}, {x2, y2}, {x3, y3}, {x4, y4});
      }
      catch (const std::logic_error& e)
      {
        std::cerr << e.what();
        delete[] concave;
        return 1;
      }
    }
  }
  return 0;
}
