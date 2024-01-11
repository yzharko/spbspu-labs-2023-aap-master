#include <iostream>
#include <string>
#include <iomanip>
#include "base-types.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "parallelogram.hpp"
#include "rectangle.hpp"

int main() {
  using namespace sukacheva;
  bool ifScale = 0;
  std::string nameOfFigure = "";
  Shape* figures[1000]{};
  int index = 0;
  while (!std::cin.eof())
  {
    std::cin >> nameOfFigure;
    if (nameOfFigure == "RECTANGLE")
    {
      double x1, y1, x2, y2 = 0;
      std::cin >> x1 >> y1 >> x2 >> y2;
      try
      {
        point_t point1 = { x1, y1 };
        point_t point2 = { x2, y2 };
        Shape* rectangle = new Rectangle(point2, point1);
        figures[index] = rectangle;
        index += 1;
      }
      catch (const std::logic_error& e)
      {
        std::cerr << e.what();
      }
    }
    else if (nameOfFigure == "CIRCLE")
    {
      double x, y, radius = 0;
      std::cin >> x >> y >> radius;
      try
      {
        point_t point1 = { x, y };
        Shape* circle = new Circle(point1, radius);
        figures[index] = circle;
        index += 1;
      }
      catch (const std::logic_error& e)
      {
        std::cerr << e.what();
      }
    }
    else if (nameOfFigure == "PARALLELOGRAM")
    {
      double x1, y1, x2, y2, x3, y3 = 0;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      try
      {
        point_t point1 = { x1, y1 };
        point_t point2 = { x2, y2 };
        point_t point3 = { x3, y3 };
        Shape* parallelogram = new Parallelogram(point1, point2, point3);
        figures[index] = parallelogram;
        index += 1;
      }
      catch (const std::logic_error& e)
      {
        std::cerr << e.what();
      }
    }
    else if (nameOfFigure == "SCALE")
    {
      double x, y, k = 0;
      std::cin >> x >> y >> k;
      if ( k < 0 || index == 0)
      {
        std::cerr << "Incorrect input of figures";
        for (int i = 0; i < index; i++)
        {
          delete figures[i];
        }
        return 2;
      }
      else {
        double x1, y1, x2, y2 = 0;
        double x3, y3, x4, y4 = 0;
        point_t center{ x, y };
        double firstArea = 0;
        double newArea = 0;
        for (int i = 0; i < index; i++)
        {
          firstArea += figures[i]->getArea();
        }
        std::cout << std::fixed << std::setprecision(1) << firstArea;

        for (int i = 0; i < index; i++)
        {
          rectangle_t frameRect = figures[i]->getFrameRect();
          x1 = frameRect.pos_.x_ - frameRect.width_ / 2.0;
          y1 = frameRect.pos_.y_ - frameRect.height_ / 2.0;
          x2 = frameRect.pos_.x_ + frameRect.width_ / 2.0;
          y2 = frameRect.pos_.y_ + frameRect.height_ / 2.0;
          std::cout << std::fixed << std::setprecision(1) << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2;
        }

        std::cout << "\n";

        for (int i = 0; i < index; i++)
        {
          figures[i]->scale(center, k);
          newArea += figures[i]->getArea();
        }
        std::cout << std::fixed << std::setprecision(1) << newArea;

        for (int i = 0; i < index; i++)
        {
          rectangle_t newFrameRect = figures[i]->getFrameRect();
          x3 = newFrameRect.pos_.x_ - newFrameRect.width_ / 2.0;
          y3 = newFrameRect.pos_.y_ - newFrameRect.height_ / 2.0;
          x4 = newFrameRect.pos_.x_ + newFrameRect.width_ / 2.0;
          y4 = newFrameRect.pos_.y_ + newFrameRect.height_ / 2.0;
          std::cout << std::fixed << std::setprecision(1) << ' ' << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4;
          delete figures[i];
        }
        std::cout << "\n";
        ifScale = 1;
        break;
      }
    }
    if (!ifScale)
    {
      for (int i = 0; i < index; i++)
      {
        delete figures[i];
      }
      std::cerr << "No scale command";
      return 2;
    }
  };
  return 0;
}
