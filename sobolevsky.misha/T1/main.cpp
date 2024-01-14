#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "parallelogram.hpp"

bool isParallelogramCorrect(sobolevsky::point_t point1, sobolevsky::point_t point2, sobolevsky::point_t point3)
{
  double baseFigure = point1.x * (point3.y - point1.y) + point1.x * (point2.y - point3.y);
  baseFigure = abs((baseFigure + point3.x * (point1.y - point2.y)) / 2.0);
  return (point2.y == point3.y || point1.y == point2.y) && (baseFigure != 0);
}

int main()
{
  struct CompositeShape
  {
    size_t shapes;
    size_t capacity;
    sobolevsky::Shape * shapeptrs;
  };

  size_t arraySize = 10;
  sobolevsky::Shape ** figuers = new sobolevsky::Shape * [arraySize];
  size_t counter = 0;

  std::string figureType;
  while (std::cin)
  {
    std::cin >> figureType;
    if (std::cin.eof())
    {
      for (size_t i = 0; i < counter; i++)
      {
        delete figuers[i];
      }
      delete[] figuers;
      return 1;
    }
    if (counter == arraySize)
    {
      arraySize += 10;
      sobolevsky::Shape ** newArray = new sobolevsky::Shape * [arraySize];
      std::copy(figuers, figuers + arraySize - 10, newArray);
      for (size_t i = 0; i < (arraySize - 10); i++)
      {
        delete figuers[i];
      }
      delete[] figuers;
      figuers = newArray;
    }

    if (figureType == "RECTANGLE")
    {
      double x1, x2, y1, y2;
      if ((std::cin >> x1 >> y1 >> x2 >> y2) && (x1 < x2) && (y1 < y2))
      {
        figuers[counter++] = new sobolevsky::Rectangle({x1, y1}, {x2, y2});
      }
      else
      {
        std::cerr << "ERROR ERROR\n";
      }
    }
    else if (figureType == "DIAMOND")
    {
      double x1, x2, x3, y1, y2, y3;
      if (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
      {
        figuers[counter++] = new sobolevsky::Diamond({x1, y1}, {x2, y2}, {x3, y3});
      }
      else
      {
        std::cerr << "ERROR ERROR\n";
      }
    }
    else if (figureType == "PARALLELOGRAM")
    {
      double x1, x2, x3, y1, y2, y3;
      if ((std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3))
      {
        figuers[counter++] = new sobolevsky::Parallelogram({x1, y1}, {x2, y2}, {x3, y3});
      }
      else
      {
        std::cerr << "ERROR ERROR\n";
      }
    }
    else if (figureType == "SCALE")
    {
      double xx, yy, n;

      if (counter == 0)
      {
        std::cerr << "no bitches\n";
        for (size_t i = 0; i < counter; i++)
        {
          delete figuers[i];
        }
        delete[] figuers;
        return 1;
      }
      else if (std::cin >> xx >> yy >> n)
      {
        if (n <= 0)
        {
          std::cerr << "scale shoulde be >0\n";
          for (size_t i = 0; i < counter; i++)
          {
            delete figuers[i];
          }
          delete[] figuers;
          return 1;
        }

        std::cout << std::fixed << std::setprecision(1);

        double sumArea = 0;
        for (size_t i = 0; i < counter; i++)
        {
          double area = figuers[i]->getArea();
          if (area == -4.0)
          {
            area = 4.0;
          }
          sumArea += area;
        }
        std::cout << sumArea << " ";
        for (size_t i = 0; i < counter; i++)
        {
          std::cout << ((figuers[i]->getFrameRect().pos.x) - ((figuers[i]->getFrameRect().width) / 2)) << " ";
          std::cout << ((figuers[i]->getFrameRect().pos.y) - ((figuers[i]->getFrameRect().height) / 2)) << " ";
          std::cout << ((figuers[i]->getFrameRect().pos.x) + ((figuers[i]->getFrameRect().width) / 2)) << " ";
          if (i == (counter - 1))
          {
            std::cout << ((figuers[i]->getFrameRect().pos.y) + ((figuers[i]->getFrameRect().height) / 2));
          }
          else
          {
            std::cout << ((figuers[i]->getFrameRect().pos.y) + ((figuers[i]->getFrameRect().height) / 2)) << " ";
          }
        }
        std::cout << "\n";

        for (size_t i = 0; i < counter; i++)
        {
          sobolevsky::point_t oldCenter = figuers[i]->getFrameRect().pos;
          figuers[i]->move({xx, yy});
          sobolevsky::point_t newCenter;
          newCenter.x = fabs(oldCenter.x - xx) * n;
          newCenter.y = fabs(oldCenter.y - yy) * n;
          figuers[i]->scale(n);
          figuers[i]->move(newCenter.x, newCenter.y);
        }

        sumArea = 0;
        for (size_t i = 0; i < counter; i++)
        {
          sumArea += figuers[i]->getArea();
        }
        std::cout << sumArea << " ";
        for (size_t i = 0; i < counter; i++)
        {
          std::cout << ((figuers[i]->getFrameRect().pos.x) - ((figuers[i]->getFrameRect().width) / 2)) << " ";
          std::cout << ((figuers[i]->getFrameRect().pos.y) - ((figuers[i]->getFrameRect().height) / 2)) << " ";
          std::cout << ((figuers[i]->getFrameRect().pos.x) + ((figuers[i]->getFrameRect().width) / 2)) << " ";
          if (i == (counter - 1))
          {
            std::cout << ((figuers[i]->getFrameRect().pos.y) + ((figuers[i]->getFrameRect().height) / 2));
          }
          else
          {
            std::cout << ((figuers[i]->getFrameRect().pos.y) + ((figuers[i]->getFrameRect().height) / 2)) << " ";
          }
        }
        std::cout << "\n";
        for (size_t i = 0; i < counter; i++)
        {
          delete figuers[i];
        }
        delete[] figuers;
        return 0;
      }
      else
      {
        std::cerr << "AAAAAAAAAAA\n";
        for (size_t i = 0; i < counter; i++)
        {
          delete figuers[i];
        }
        delete[] figuers;
        return 1;
      }
    }
    else
    {
      continue;
    }
  }
  for (size_t i = 0; i < counter; i++)
  {
    delete figuers[i];
  }
  delete[] figuers;
  return 0;
}
