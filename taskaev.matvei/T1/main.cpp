#include <iostream>
#include "ellipse.hpp"
#include "Shape.hpp"
#include "concave.hpp"
#include "rectangle.hpp"
#include "baseTypes.hpp"

int main()
{
  std::string figur = "";
  Shape* figurs[1000]{};
  int ind = 0;
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
        Shape* rectangle = new taskaev::Rectangle({ x1,y1 }, { x2,y2 });
        figurs[ind++] = rectangle;
      }
      catch (const std::logic_error& e)
      {
        std::cerr << e.what();
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
        Shape* ellipse = new taskaev::Ellipse({ x, y }, radVer, radGor);
	figurs[ind++] = ellipse;
      }
      catch (const std::logic_error& e)
      {
	std::cerr << e.what();
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
        Shape* concave = new taskaev::Concave({x1, x2}, {x2, y2}, {x3, y3}, {x4, y4});
        figurs[ind++] = concave;
      }
      catch (const std::logic_error& e)
      {
        std::cerr << e.what();
      }
    }
  }
  return 0;
}

