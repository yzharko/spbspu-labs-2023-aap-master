#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "concave.hpp"
#include <iomanip>

int main()
{
  using namespace doroshenko;
  std::string figure;
  size_t size = 20;
  size_t plusSize = 20;
  size_t countFig = 0;
  Shape** geometricFigures = new Shape * [size];
  while (!std::cin.eof())
  {
    std::cin >> figure;
    if (figure == "RECTANGLE")
    {
      double xL, yL, xR, yR;
      std::cin >> xL >> yL >> xR >> yR;
      if (!std::cin)
      {
        std::cerr << "Wrong input\n";
      }
      else
      {
        point_t pointL = { xL, yL };
        point_t pointR = { xR, yR };
        geometricFigures[countFig] = new Rectangle(pointL, pointR);
        countFig++;
      }
    }

    else if (figure == "TRIANGLE")
    {
      double xFir, yFir, xSec, ySec, xThi, yThi;
      std::cin >> xFir >> yFir >> xSec >> ySec >> xThi >> yThi;
      point_t pointFir = { xFir, yFir };
      point_t pointSec = { xSec, ySec };
      point_t pointThi = { xThi, yThi };
      geometricFigures[countFig] = new Triangle(pointFir, pointSec, pointThi);
      try
      {
        geometricFigures[countFig]->getArea();
      }
      catch (const std::logic_error&e)
      {
        //std::cout << e.what();
        delete[] geometricFigures[countFig];
        countFig--;
      }
      countFig++;
    }

    else if (figure == "CONCAVE")
    {
      double xFir, yFir, xSec, ySec, xThi, yThi, xFou, yFou;
      std::cin >> xFir >> yFir >> xSec >> ySec >> xThi >> yThi >> xFou >> yFou;
      point_t pointFir = { xFir, yFir };
      point_t pointSec = { xSec, ySec };
      point_t pointThi = { xThi, yThi };
      point_t pointFou = { xFou, yFou };
      geometricFigures[countFig] = new Concave(pointFir, pointSec, pointThi, pointFou);
      try
      {
        geometricFigures[countFig]->getArea();
      }
      catch (const std::logic_error& e)
      {
        //std::cout << e.what();
        delete[] geometricFigures[countFig];
        countFig--;
      }
      countFig++;
    }

    else if (figure == "SCALE")
    {
      double posx, posy, coefficient;
      double xL, yL, xR, yR;
      std::cin >> posx >> posy >> coefficient;
      double sumAreaBefore = 0;
      for (size_t i = 0; i < countFig; i++)
      {
        sumAreaBefore += geometricFigures[i]->getArea();
      }
      std::cout << std::fixed << std::setprecision(1) << sumAreaBefore << ' ';
      for (size_t j = 0; j < countFig; j++)
      {
        rectangle_t frame = geometricFigures[j]->getFrameRect();
        xL = frame.pos_.x_ - 0.5 * frame.width_;
        yL = frame.pos_.y_ - 0.5 * frame.height_;
        xR = frame.pos_.x_ + 0.5 * frame.width_;
        yR = frame.pos_.y_ + 0.5 * frame.height_;
        //std::cout << frame.pos_.x_ << ' ' << frame.pos_.y_ << ' ' << frame.width_ << ' ' << frame.height_;
        std::cout << std::fixed << std::setprecision(1) << xL << ' ' << yL << ' ' << xR << ' ' << yR << ' ';
      }
      std::cout << "\n";
      for (size_t k = 0; k < countFig; k++)
      {
        geometricFigures[k]->scale(coefficient);
      }
      double sumAreaAfter = 0;
      for (size_t i = 0; i < countFig; i++)
      {
        sumAreaAfter += geometricFigures[i]->getArea();
      }
      std::cout << std::fixed << std::setprecision(1) << sumAreaAfter << ' ';
      for (size_t j = 0; j < countFig; j++)
      {
        rectangle_t frame = geometricFigures[j]->getFrameRect();
        xL = frame.pos_.x_ - 0.5 * frame.width_;
        yL = frame.pos_.y_ - 0.5 * frame.height_;
        xR = frame.pos_.x_ + 0.5 * frame.width_;
        yR = frame.pos_.y_ + 0.5 * frame.height_;
        std::cout << std::fixed << std::setprecision(1) << xL << ' ' << yL << ' ' << xR << ' ' << yR << ' ';
      }
      std::cout << "\n";
    }

    if (countFig == size)
    {
      size_t newSize = size + plusSize;
      Shape** newArray = new Shape * [newSize];
      for (size_t i = 0; i < size; i++)
      {
        newArray[i] = geometricFigures[i];
      }
      for (size_t j = size; j < newSize; j++)
      {
        newArray[j] = nullptr;
      }
      delete[] geometricFigures;
      geometricFigures = newArray;
    }
  }
}
