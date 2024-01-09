#include <iostream>
#include <string>
#include <sstream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "complexquad.hpp"

int main()
{
  size_t initialSize = 10;
  Shape ** allFigures = new Shape * [initialSize];
  size_t figuresCounter = 0;
  std::string type;
  while (std::cin >> type)
  {
    if (figuresCounter == initialSize)
    {
      initialSize += initialSize;
      Shape ** tempStorage = new Shape * [initialSize];
      std::copy(allFigures, allFigures + figuresCounter, tempStorage);
      delete[] allFigures;
      allFigures = tempStorage;
    }

    if (type == "RECTANGLE")
    {
      double x1, y1, x2, y2;
      if (std::cin >> x1 >> y1 >> x2 >> y2)
      {
        allFigures[figuresCounter++] = new khoroshkin::Rectangle(point_t{x1, y1}, point_t{x2, y2});
      }
      else
      {
        std::cerr << "Error: wrong rectangle input\n";
      }
    }
    else if (type == "CIRCLE")
    {
      double x, y, radius;
      if (std::cin >> x >> y >> radius && radius > 0)
      {
        allFigures[figuresCounter++] = new khoroshkin::Circle(point_t{x, y}, radius);
      }
      else
      {
        std::cerr << "Error: wrong circle input\n";
      }
    }
    else if (type == "COMPLEXQUAD")
    {
      double x1, y1, x2, y2, x3, y3, x4, y4;
      if (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
      {
        allFigures[figuresCounter++] = new khoroshkin::Complexquad(point_t{x1, y1},\
        point_t{x2, y2}, point_t{x3, y3}, point_t{x4, y4});
      }
      else
      {
        std::cerr << "Error: wrong complexquad input\n";
      }
    }
    else if (type == "SCALE")
    {
      double x, y, scale;
      if (std::cin >> x >> y >> scale && scale > 0)
      {
        for (size_t i = 0; i < figuresCounter; ++i)
        {
          allFigures[i]->scale(scale);
        }

        for (size_t i = 0; i < figuresCounter; ++i)
        {
          std::cout << allFigures[i]->getArea() << " " << allFigures[i]->getFrameRect().pos.x << " ";
          std::cout << allFigures[i]->getFrameRect().pos.y << " ";
          std::cout << allFigures[i]->getFrameRect().width << " " << allFigures[i]->getFrameRect().height << "\n";
        }
      }
      else
      {
        std::cerr << "Error: wrong scale input\n";
      }
    }
    else
    {
      std::cerr << "Error: unsupported figure\n";
    }
  }
  for (size_t i = 0; i < figuresCounter; ++i)
  {
    delete[] allFigures[i];
  }
  return 0;
}
