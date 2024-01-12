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
  bool checkScale = false;
  while (!std::cin.eof() && std::cin >> figure)
  {
    if (figure == "RECTANGLE")
    {
      double lx, ly, rx, ry;
      std::cin >> lx >> ly >> rx >> ry;
      if (!std::cin || lx > rx || ly > ry)
      {
        checkInput = true;
      }
      else
      {
        figures[figuresCount] = new Rectangle({ lx, ly }, { rx, ry });
        figuresCount++;
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
    else
    {
      figures[figuresCount] = new Square({ x, y }, side);
      try
      {
        figures[figuresCount]->getArea();
      }
      catch (const std::logic_error& ex)
      {
        checkInput = true;
        delete[] figures[figuresCount];
        figuresCount--;
      }
        figuresCount++;
      }
    }
    else if (figure == "TRIANGLE")
    {
      double x1, y1, x2, y2, x3, y3;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      if (!std::cin)
      {
        checkInput = true;
      }
      else
      {
        figures[figuresCount] = new Triangle({ x1, y1 }, { x2, y2 }, { x3, y3 });
        try
        {
          figures[figuresCount]->getArea();
        }
        catch (const std::logic_error& ex)
        {
          checkInput = true;
          delete[] figures[figuresCount];
          figuresCount--;
        }
        figuresCount++;
      }
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
        std::cout << std::fixed << std::setprecision(1) << ' ' << frameOfRect.pos.x << ' ' << frameOfRect.pos.y;
        std::cout << std::fixed << std::setprecision(1) << ' ' << frameOfRect.pos.x << ' ' << frameOfRect.pos.y;
      }
      std::cout << "\n";
      for (size_t i = 0; i < figuresCount; i++)
      {
        rectangle_t firstFrame = figures[i]->getFrameRect();
        figures[i]->move({ xp, yp });
        rectangle_t secFrame = figures[i]->getFrameRect();
        double replaceX = fabs(secFrame.pos.x - firstFrame.pos.x);
        double replaceY = fabs(secFrame.pos.y - firstFrame.pos.y);
        figures[i]->scale(k);
        figures[i]->move(replaceX, replaceY);
      }
      double areaSumm = 0;
      for (size_t i = 0; i < figuresCount; i++)
      {
        areaSumm += figures[i]->getArea();
      }
      std::cout << std::fixed << std::setprecision(1) << areaSumm;
      for (size_t i = 0; i < figuresCount; i++)
      {
        rectangle_t frameOfRect = figures[i]->getFrameRect();
        std::cout << std::fixed << std::setprecision(1) << ' ' << frameOfRect.pos.x << ' ' << frameOfRect.pos.y;
        std::cout << std::fixed << std::setprecision(1) << ' ' << frameOfRect.pos.x << ' ' << frameOfRect.pos.y;
      }
      std::cout << "\n";
      checkScale = true;
      break;
    }
  }
  if (figuresCount > 0)
  {
    for (size_t i = 0; i < figuresCount; i++)
    {
      delete[] figures[i];
    }
  }
  if (checkScale == true)
  {
    std::cerr << "cannot scale\n";
    return 1;
  }
  if (checkInput == true)
  {
    std::cerr << "problems with input\n";
  }
}
