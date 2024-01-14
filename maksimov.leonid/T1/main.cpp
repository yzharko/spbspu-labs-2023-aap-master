#include <iostream>
#include <iomanip>
#include "rectangle.hpp"
#include "square.hpp"
#include "base-types.hpp"

int main()
{
  std::string figure = "";
  size_t count = 0;
  Shape* geometricFigures[1000] = { 0 };
  while (std::cin >> figure && !std::cin.eof())
  {
    if (figure == "RECTANGLE")
    {
      double x1, y1, x2, y2;
      std::cin >> x1 >> y1 >> x2 >> y2;
      geometricFigures[count++] = new Rectangle(x1, y1, x2, y2);
      figure = "";
    }
    if (figure == "SQUARE")
    {
      double x1, y1, width;
      std::cin >> x1 >> y1 >> width;
      geometricFigures[count++] = new Square(x1, y1, width);
      figure = "";
    }
    if (figure == "SCALE")
    {
      double posX, posY, k;
      std::cin >> posX >> posY >> k;
      std::cout << std::fixed << std::setprecision(1);
      for (size_t i = 0; i < count; i++)
      {
        std::cout << double(geometricFigures[i]->getArea()) << ' ' << geometricFigures[i]->getFrameRect().pos.x - (geometricFigures[i]->getFrameRect().width / 2) << ' ' << geometricFigures[i]->getFrameRect().pos.y - (geometricFigures[i]->getFrameRect().height / 2) << ' '
        << geometricFigures[i]->getFrameRect().pos.x + (geometricFigures[i]->getFrameRect().width / 2) << ' ' << geometricFigures[i]->getFrameRect().pos.y + (geometricFigures[i]->getFrameRect().height / 2) << '\n';
        geometricFigures[i]->scale(k);
        std::cout << geometricFigures[i]->getArea() << ' ' << geometricFigures[i]->getFrameRect().pos.x - (geometricFigures[i]->getFrameRect().width / 2) << ' ' << geometricFigures[i]->getFrameRect().pos.y - (geometricFigures[i]->getFrameRect().height / 2) << ' '
        << geometricFigures[i]->getFrameRect().pos.x + (geometricFigures[i]->getFrameRect().width / 2) << ' ' << geometricFigures[i]->getFrameRect().pos.y + (geometricFigures[i]->getFrameRect().height / 2) << '\n';
      }
    }
  }
}
