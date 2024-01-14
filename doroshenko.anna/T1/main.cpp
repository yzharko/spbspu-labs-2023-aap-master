#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "concave.hpp"
#include <iomanip>
#include <cmath>

int main()
{
  using namespace doroshenko;
  std::string figure = "";
  bool wrIn = false;
  bool scale = false;
  size_t countFig = 0;
  Shape* geometricFigures[1000] = { 0 };
  while (std::cin>>figure && !std::cin.eof())
  {
    if (figure == "RECTANGLE")
    {
      double xL, yL, xR, yR;
      std::cin >> xL >> yL >> xR >> yR;
      if (!std::cin || xL > xR || yL > yR)
      {
        wrIn = true;
      }
      else
      {
        geometricFigures[countFig] = new Rectangle({ xL, yL }, { xR, yR });
        countFig++;
      }
    }

    else if (figure == "TRIANGLE")
    {
      double xFir, yFir, xSec, ySec, xThi, yThi;
      std::cin >> xFir >> yFir >> xSec >> ySec >> xThi >> yThi;
      if (!std::cin)
      {
        wrIn = true;
      }
      else
      {
        geometricFigures[countFig] = new Triangle({ xFir, yFir }, { xSec, ySec }, { xThi, yThi });
        try
        {
          geometricFigures[countFig]->getArea();
        }
        catch (const std::logic_error& e)
        {
          wrIn = true;
          delete geometricFigures[countFig];
          countFig--;
        }
        countFig++;
      }
    }

    else if (figure == "CONCAVE")
    {
      double xFir, yFir, xSec, ySec, xThi, yThi, xFou, yFou;
      std::cin >> xFir >> yFir >> xSec >> ySec >> xThi >> yThi >> xFou >> yFou;
      if (!std::cin)
      {
        wrIn = true;
      }
      else
      {
        geometricFigures[countFig] = new Concave({ xFir, yFir }, { xSec, ySec }, { xThi, yThi }, { xFou, yFou });
        try
        {
          geometricFigures[countFig]->getArea();
        }
        catch (const std::logic_error& e)
        {
          wrIn = true;
          delete geometricFigures[countFig];
          countFig--;
        }
        countFig++;
      }
    }

    else if (figure == "SCALE")
    {
      double posx, posy, coefficient;
      double xL, yL, xR, yR;
      try
      {
        std::cin >> posx >> posy >> coefficient;
      }
      catch(const std::logic_error& e)
      {
        std::cerr << e.what();
        for (size_t i = 0; i < countFig; i++)
        {
          delete geometricFigures[i];
        }
        return 1;
      }
      if (countFig == 0)
      {
        std::cerr << "There is nothing to scale";
        return 1;
      }
      double sumAreaBefore = 0;
      for (size_t i = 0; i < countFig; i++)
      {
        sumAreaBefore += geometricFigures[i]->getArea();
      }
      std::cout << std::fixed << std::setprecision(1) << sumAreaBefore;
      for (size_t j = 0; j < countFig; j++)
      {
        rectangle_t frame = geometricFigures[j]->getFrameRect();
        xL = frame.pos.x - 0.5 * frame.width;
        yL = frame.pos.y - 0.5 * frame.height;
        xR = frame.pos.x + 0.5 * frame.width;
        yR = frame.pos.y + 0.5 * frame.height;
        std::cout << std::fixed << std::setprecision(1) << ' ' << xL << ' ' << yL << ' ' << xR << ' ' << yR;
      }
      std::cout << "\n";
      for (size_t k = 0; k < countFig; k++)
      {
        rectangle_t frameBefore = geometricFigures[k]->getFrameRect();
        geometricFigures[k]->move({posx, posy});
        rectangle_t frameAfter = geometricFigures[k]->getFrameRect();
        double moveX = fabs(frameAfter.pos.x - frameBefore.pos.x)*coefficient;
        double moveY = fabs(frameAfter.pos.y - frameBefore.pos.y)*coefficient;
        geometricFigures[k]->scale(coefficient);
        geometricFigures[k]->move(moveX, moveY);
      }
      double sumAreaAfter = 0;
      for (size_t i = 0; i < countFig; i++)
      {
        sumAreaAfter += geometricFigures[i]->getArea();
      }
      std::cout << std::fixed << std::setprecision(1) << sumAreaAfter;
      for (size_t j = 0; j < countFig; j++)
      {
        rectangle_t frame = geometricFigures[j]->getFrameRect();
        xL = frame.pos.x - 0.5 * frame.width;
        yL = frame.pos.y - 0.5 * frame.height;
        xR = frame.pos.x + 0.5 * frame.width;
        yR = frame.pos.y + 0.5 * frame.height;
        std::cout << std::fixed << std::setprecision(1) << ' ' << xL << ' ' << yL << ' ' << xR << ' ' << yR;
      }
      std::cout << "\n";
      scale = true;
      break;
    }
  }
  if(countFig > 0)
  {
    for (size_t i = 0; i < countFig; i++)
    {
      delete geometricFigures[i];
    }
  }
  if (std::cin.eof() && scale == false)
  {
    std::cerr << "Figures were not scaled\n";
    return 1;
  }
  if (wrIn == true)
  {
    std::cerr << "Wrong input\n";
  }
}
