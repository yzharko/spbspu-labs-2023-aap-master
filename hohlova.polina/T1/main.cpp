#include <iostream>
#include <iomanip>
#include "shape.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "triangle.hpp"

int main()
{
  using namespace hohlova;
  std::string figure = "";
  size_t figuresCount = 0;
  Shape* figures[1000] = { 0 };
  bool checkInput = false;
  while (!std::cin.eof())
  {
    std::cin >> figure;
    if (figure == "RECTANGLE")
    {
      double lx, ly, rx, ry;
      std::cin >> lx >> ly >> rx >> ry;
      if (!std::cin || lx > rx || ly > ry)
      {
        checkInput = true;
      }
      try
      {
        point_t lpos = { lx, ly };
        point_t rpos = { rx, ry };
        Shape* rectangle = new Rectangle(lpos, rpos);
        figures[figuresCount] = rectangle;
        figuresCount++;
      }
      catch (const std::exception& ex)
      {
        checkInput = true;
      }
    }
    else if (figure == "SQUARE")
    {
      double x, y, side;
      std::cin >> x >> y >> side;
      if (!std::cin || side <= 0)
      {
        checkInput = true;
      }
      figures[figuresCount] = new Square({ x, y }, side);
      try
      {
        figures[figuresCount]->getArea();
      }
      catch (const std::exception& ex)
      {
        std::cerr << ex.what();
        delete[] figures[figuresCount];
        figuresCount--;
      }
      figuresCount++;
    }
    else if (figure == "TRIANGLE")
    {
      double x1, y1, x2, y2, x3, y3;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      if (!std::cin)
      {
        checkInput = true;
      }
      figures[figuresCount] = new Triangle({ x1, y1 }, { x2, y2 }, { x3, y3 });
      try
      {
        figures[figuresCount]->getArea();
      }
      catch (const std::exception& ex)
      {
        checkInput = true;
        delete[] figures[figuresCount];
        figuresCount--;
      }
      figuresCount++;
    }
    else if (figure == "SCALE")
    {
      double xp, yp, k;
      std::cin >> xp >> yp >> k;
      if (!std::cin || k < 0)
      {
        std::cerr << "cannot scale\n";
        for (size_t i = 0; i < figuresCount; i++)
        {
          delete[] figures[i];
        }
        return 1;
      }
      else if (figuresCount == 0)
      {
        std::cerr << "no figures\n";
        return 1;
      }
      double areaSum = 0;
      for (size_t i = 0; i < figuresCount; i++)
      {
        areaSum += figures[i]->getArea();
      }
      std::cout << std::fixed << std::setprecision(1) << areaSum;
      for (size_t i = 0; i < figuresCount; i++)
      {
        rectangle_t frameOfRect = figures[i]->getFrameRect();
        std::cout << std::fixed << std::setprecision(1) << ' ' << frameOfRect.pos_.x_ << ' ' << frameOfRect.pos_.y_;
        std::cout << std::fixed << std::setprecision(1) << ' ' << frameOfRect.pos_.x_ << ' ' << frameOfRect.pos_.y_;
        delete figures[i];
}
      std::cout << "\n";
      break;
    }
  }
  if (checkInput == true)
  {
    std::cerr << "problems with input\n";
  }
}

