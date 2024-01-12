#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "concave.hpp"
#include <iomanip>

int main()
{
  using namespace jirkov;
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
    else if (figure == "DIAMOND")
    {
      if (!std::cin)
      {
        wrIn = true;
      }
      else
      {
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
          delete[] geometricFigures[countFig];
          countFig--;
        }
        countFig++;
      }
    }
    else if (figure == "SCALE")
    {
      double posx, posy, coefficient;
      double xL, yL, xR, yR;
      std::cin >> posx >> posy >> coefficient;
      if (!std::cin || coefficient < 0)
      {
        std::cerr << "Wrong scale parameters\n";
        return 1;
      }
      else
      {
        double sumAreaBefore = 0;
        for (size_t i = 0; i < countFig; i++)
        {
          sumAreaBefore += geometricFigures[i]->getArea();
        }
        std::cout << std::fixed << std::setprecision(1) << sumAreaBefore;
        for (size_t j = 0; j < countFig; j++)
        {
          rectangle_t frame = geometricFigures[j]->getFrameRect();
          xL = frame.pos_.x_ - 0.5 * frame.width_;
          yL = frame.pos_.y_ - 0.5 * frame.height_;
          xR = frame.pos_.x_ + 0.5 * frame.width_;
          yR = frame.pos_.y_ + 0.5 * frame.height_;
          std::cout << std::fixed << std::setprecision(1) << ' ' << xL << ' ' << yL << ' ' << xR << ' ' << yR;
        }
        std::cout << "\n";
        for (size_t k = 0; k < countFig; k++)
        {
          geometricFigures[k]->move({ 0 - posx, 0 - posy });
          geometricFigures[k]->scale(coefficient);
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
          xL = frame.pos_.x_ - 0.5 * frame.width_;
          yL = frame.pos_.y_ - 0.5 * frame.height_;
          xR = frame.pos_.x_ + 0.5 * frame.width_;
          yR = frame.pos_.y_ + 0.5 * frame.height_;
          std::cout << std::fixed << std::setprecision(1) << ' ' << xL << ' ' << yL << ' ' << xR << ' ' << yR;
        }
        std::cout << "\n";
        scale = true;
        break;
      }
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
  if(countFig > 0)
  {
    for (size_t i = 0; i < countFig; i++)
    {
      delete geometricFigures[i];
    }
  }
}
