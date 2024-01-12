#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "concave.hpp"
#include <iomanip>
#include <cmath>

int main()
{
  using namespace jirkov;
  size_t count = 0;
  Shape* figureArray[1000] = { nullptr };
  bool wrongInput = false;
  std::string geometryFigure = "";
  bool scale = false;
  while (std::cin >> geometryFigure && !std::cin.eof())
  {
    if (geometryFigure == "RECTANGLE")
    {
      double firstLeft, secondLeft, firstRight, secondRight;
      std::cin >> firstLeft >> secondLeft >> firstRight >> secondRight;
      if (!std::cin || firstLeft > firstRight || secondLeft > secondRight)
      {
        wrongInput = true;
      }
      else
      {
        figureArray[count] = new Rectangle({ firstLeft, secondLeft }, { firstRight, secondRight });
        count++;
      }
    }
    else if (geometryFigure == "DIAMOND")
    {
      double firstTop, secondTop, firstMedium, secondMedium, firstUnder, secondUnder;
      std::cin >> firstTop >> secondTop >> firstMedium >> secondMedium >> firstUnder >> secondUnder;
      if (!std::cin)
      {
        wrongInput = true;
      }
      else
      {
        figureArray[count] = new Diamond({ firstTop, secondTop }, { firstMedium, secondMedium }, { firstUnder, secondUnder });
        try
        {
          figureArray[count]->getArea();
        }
        catch (const std::logic_error& e)
        {
          wrongInput = true;
          delete figureArray[count];
          count--;
        }
        count++;
      }
    }
    else if (geometryFigure == "CONCAVE")
    {
      double FirstA, FirstB, SecondA, SecondB, ThirdA, ThirdB, FourthA, FourthB;
      std::cin >> FirstA >> FirstB >> SecondA >> SecondB >> ThirdA >> ThirdB >> FourthA >> FourthB;
      if (!std::cin)
      {
        wrongInput = true;
      }
      else
      {
        figureArray[count] = new Concave({ FirstA, FirstB }, { SecondA, SecondB }, { ThirdA, ThirdB }, { FourthA, FourthB });
        try
        {
          figureArray[count]->getArea();
        }
        catch (const std::logic_error& e)
        {
          wrongInput = true;
          delete figureArray[count];
          count--;
        }
        count++;
      }
    }
    else if (geometryFigure == "SCALE")
    {
      double posx, posy, k;
      double LeftA, LeftB, RightA, RightB;
      std::cin >> posx >> posy >> k;
      if (!std::cin || k <= 0)
      {
        std::cerr << "Scale error\n";
        for (size_t i = 0; i < count; i++)
        {
          delete figureArray[i];
        }
        return 1;
      }
      else
      {
        if (count == 0)
        {
          std::cerr << "Scale is nothing";
          return 1;
        }
        double sumAreaBefore = 0;
        for (size_t i = 0; i < count; i++)
        {
          sumAreaBefore += figureArray[i]->getArea();
        }
        std::cout << std::fixed << std::setprecision(1) << sumAreaBefore;
        for (size_t j = 0; j < count; j++)
        {
          rectangle_t frame = figureArray[j]->getFrameRect();
          LeftA = frame.pos.x - 0.5 * frame.width;
          LeftB = frame.pos.y - 0.5 * frame.height;
          RightA = frame.pos.x + 0.5 * frame.width;
          RightB = frame.pos.y + 0.5 * frame.height;
          std::cout << std::fixed << std::setprecision(1) << ' ' << LeftA << ' ' << LeftB << ' ' << RightA << ' ' << RightB;
        }
        std::cout << "\n";
        for (size_t l = 0; l < count; l++)
        {
          rectangle_t begin = figureArray[l]->getFrameRect();
          figureArray[l]->move({ posx, posy });
          rectangle_t end = figureArray[l]->getFrameRect();
          double moveX = fabs(end.pos.x - begin.pos.x) * k;
          double moveY = fabs(end.pos.y - begin.pos.y) * k;
          figureArray[l]->scale(k);
          figureArray[l]->move(moveX, moveY);
        }
        double sumAreaAfter = 0;
        for (size_t i = 0; i < count; i++)
        {
          sumAreaAfter += figureArray[i]->getArea();
        }
        std::cout << std::fixed << std::setprecision(1) << sumAreaAfter;
        for (size_t j = 0; j < count; j++)
        {
          rectangle_t frame = figureArray[j]->getFrameRect();
          LeftA = frame.pos.x - 0.5 * frame.width;
          LeftB = frame.pos.y - 0.5 * frame.height;
          RightA = frame.pos.x + 0.5 * frame.width;
          RightB = frame.pos.y + 0.5 * frame.height;
          std::cout << std::fixed << std::setprecision(1) << ' ' << LeftA << ' ' << LeftB << ' ' << RightA << ' ' << RightB;
        }
        std::cout << "\n";
        scale = true;
        break;
      }
    }
  }
  if (count > 0)
  {
    for (size_t i = 0; i < count; i++)
    {
      delete figureArray[i];
    }
  }

  if (std::cin.eof() && scale == false)
  {
    std::cerr << "Geometry error\n";
    return 1;
  }
  if (wrongInput == true)
  {
    std::cerr << "Wrong input\n";
  }
}
