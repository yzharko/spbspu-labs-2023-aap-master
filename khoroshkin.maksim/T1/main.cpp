#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "complexquad.hpp"
#include "helpfulFuncs.hpp"

int main()
{
  using namespace khoroshkin;
  size_t initialSize = 10;
  Shape ** allFigures = new Shape * [initialSize];
  size_t figuresCounter = 0;
  bool scaleCommandWas = false;
  std::string type;
  while (std::cin >> type)
  {
    if (figuresCounter == initialSize)
    {
      allFigures = expandArray(allFigures, figuresCounter, initialSize);
    }

    if (type == "RECTANGLE")
    {
      double x1, y1, x2, y2;
      if (std::cin >> x1 >> y1 >> x2 >> y2 && isRectangleCorrect(x1,y1,x2,y2))
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
      if (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 && isComplexquad(x1,y1,x2,y2,x3,y3,x4,y4))
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
      if (figuresCounter == 0)
      {
        std::cerr << "Error: nothing to scale";
        for (size_t i = 0; i < figuresCounter; ++i)
        {
          delete allFigures[i];
        }
        delete[] allFigures;
        return 1;
      }
      if (std::cin >> x >> y >> scale && scale > 0)
      {
        std::cout << std::fixed << std::setprecision(1);
        double summOfFigures = 0;
        for (size_t i = 0; i < figuresCounter; ++i)
        {
          summOfFigures += allFigures[i]->getArea();
        }
        std::cout << summOfFigures << " ";
        for (size_t i = 0; i < figuresCounter; ++i)
        {
          std::cout << allFigures[i]->getFrameRect().pos.x - allFigures[i]->getFrameRect().width / 2 << " ";
          std::cout << allFigures[i]->getFrameRect().pos.y - allFigures[i]->getFrameRect().height / 2 << " ";
          std::cout << allFigures[i]->getFrameRect().pos.x + allFigures[i]->getFrameRect().width / 2 << " ";
          if (i == figuresCounter - 1)
          {
            std::cout << allFigures[i]->getFrameRect().pos.y + allFigures[i]->getFrameRect().height / 2;
          }
          else
          {
            std::cout << allFigures[i]->getFrameRect().pos.y + allFigures[i]->getFrameRect().height / 2 << " ";
          }
        }
        std::cout << "\n";
        for (size_t i = 0; i < figuresCounter; ++i)
        {
          point_t initialPos = allFigures[i]->getFrameRect().pos;
          allFigures[i]->move({x, y});
          point_t diffPos;
          diffPos.x = fabs(initialPos.x - allFigures[i]->getFrameRect().pos.x) * scale;
          diffPos.y = fabs(initialPos.y - allFigures[i]->getFrameRect().pos.y) * scale;
          allFigures[i]->scale(scale);
          allFigures[i]->move(diffPos.x, diffPos.y);
        }
        summOfFigures = 0;
        for (size_t i = 0; i < figuresCounter; ++i)
        {
          summOfFigures += allFigures[i]->getArea();
        }
        std::cout << summOfFigures << " ";
        for (size_t i = 0; i < figuresCounter; ++i)
        {
          std::cout << allFigures[i]->getFrameRect().pos.x - allFigures[i]->getFrameRect().width / 2 << " ";
          std::cout << allFigures[i]->getFrameRect().pos.y - allFigures[i]->getFrameRect().height / 2 << " ";
          std::cout << allFigures[i]->getFrameRect().pos.x + allFigures[i]->getFrameRect().width / 2 << " ";
          if (i == figuresCounter - 1)
          {
            std::cout << allFigures[i]->getFrameRect().pos.y + allFigures[i]->getFrameRect().height / 2;
          }
          else
          {
            std::cout << allFigures[i]->getFrameRect().pos.y + allFigures[i]->getFrameRect().height / 2 << " ";
          }
        }
        std::cout << "\n";
        scaleCommandWas = true;
      }
      else
      {
        std::cerr << "Error: wrong scale input\n";
        for (size_t i = 0; i < figuresCounter; ++i)
        {
          delete allFigures[i];
        }
        delete[] allFigures;
        return 1;
      }
    }
    else if (std::all_of(type.begin(), type.end(), [](char c) { return std::isalpha(c); }))
    {
      std::cerr << "Error: unsupported figure\n";
      continue;
    }
    else
    {
      continue;
    }
  }
  for (size_t i = 0; i < figuresCounter; ++i)
  {
    delete allFigures[i];
  }
  delete[] allFigures;
  if (!scaleCommandWas)
  {
    std::cerr << "Error: missing scale command";
    return 1;
  }
  return 0;
}
