#include <iostream>
#include <string>
#include <ostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "parallelogram.hpp"
#include "regular.hpp"
#include "functions.hpp"
#include "base-types.hpp"

int main()
{
  size_t shapesSize = 5;
  Shape** shapes = new Shape * [shapesSize];
  size_t figsNow = 0;

  try
  {
    while (true)
    {
      std::string command;
      std::cin >> command;

      if (std::cin.eof() || command == "EXIT")
      {
        break;
      }

      if (figsNow >= shapesSize)
      {
        shapesSize += 5;
        Shape** temp = new Shape * [shapesSize];
        for (size_t i = 0; i < figsNow; ++i)
        {
          temp[i] = shapes[i];
        }
         delete[] shapes;
         shapes = temp;
      }

      if (command == "RECTANGLE")
      {
        double x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        shapes[figsNow++] = new toksen::Rectangle({ x1, y1 }, { x2, y2 });
      }
      else if (command == "REGULAR")
      {
        double x1, y1, x2, y2, x3, y3;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        shapes[figsNow++] = new toksen::Regular({ x1, y1 }, { x2, y2 }, { x3, y3 });
      }
      else if (command == "PARALLELOGRAM")
      {
        double x1, y1, x2, y2, x3, y3;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        shapes[figsNow++] = new toksen::Parallelogram({ x1, y1 }, { x2, y2 }, { x3, y3 });
      }
      else if (command == "SCALE")
      {
        size_t index;
        double scaleFactor;
        std::cin >> index >> scaleFactor;
        if (index < figsNow)
        {
          toksen::scaleShape(shapes[index], scaleFactor);
        }
        else
        {
          std::cerr << "Invalid shape index" << std::endl;
        }
      }
      else if (command == "MOVE")
      {
        size_t index;
        double dx, dy;
        std::cin >> index >> dx >> dy;
        if (index < figsNow)
        {
          toksen::moveShape(shapes[index], dx, dy);
        }
        else
        {
          std::cerr << "Invalid shape index" << std::endl;
        }
      }
      else
      {
        std::cerr << "Unknown command" << std::endl;
      }
    }

    for (size_t i = 0; i < figsNow; ++i)
    {
      if (toksen::Rectangle* rect = dynamic_cast<toksen::Rectangle*>(shapes[i]))
      {
        toksen::printRectangle(*rect);
      }
      else if (toksen::Regular* reg = dynamic_cast<toksen::Regular*>(shapes[i]))
      {
        toksen::printRegular(*reg);
      }
      else if (toksen::Parallelogram* para = dynamic_cast<toksen::Parallelogram*>(shapes[i]))
      {
        toksen::printParallelogram(*para);
      }
      else
      {
        std::cerr << "Unknown shape" << std::endl;
      }
    }
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  toksen::freeMemory(shapes, figsNow);
  return 0;
}
