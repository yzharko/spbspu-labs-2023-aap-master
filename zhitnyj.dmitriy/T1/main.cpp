#include "ring.hpp"
#include "complex-quad.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

int main()
{
  std::vector<Shape*> shapes;
  std::string shapeType;

  try
  {
    while (std::cin >> shapeType)
    {
      if (shapeType == "RING")
      {
        float centerX, centerY, innerRadius, outerRadius;
        if (!(std::cin >> centerX >> centerY >> innerRadius >> outerRadius))
        {
          throw std::runtime_error("Invalid input for RING");
        }
        shapes.push_back(new Ring({ centerX, centerY }, innerRadius, outerRadius));
      }
      else if (shapeType == "COMPLEXQUAD")
      {
        float x0, y0, x1, y1, x2, y2, x3, y3;
        if (!(std::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3))
        {
          throw std::runtime_error("Invalid input for COMPLEXQUAD");
        }
        shapes.push_back(new ComplexQuad({ x0, y0 }, { x1, y1 }, { x2, y2 }, { x3, y3 }));
      }
      else if (shapeType == "SCALE")
      {
        float scaleCenterX, scaleCenterY, scaleFactor;
        if (!(std::cin >> scaleCenterX >> scaleCenterY >> scaleFactor))
        {
          throw std::runtime_error("Invalid input for SCALE command");
        }

        if (scaleFactor <= 0)
        {
          throw std::runtime_error("Scale factor must be positive");
        }

        double totalAreaBefore = 0.0;
        for (Shape* shape : shapes)
        {
          rectangle_t frameRect = shape->getFrameRect();
          totalAreaBefore += shape->getArea();
          std::cout << std::fixed << std::setprecision(1) << frameRect.pos.x - frameRect.width / 2 << " "
                    << frameRect.pos.y - frameRect.height / 2 << " "
                    << frameRect.pos.x + frameRect.width / 2 << " "
                    << frameRect.pos.y + frameRect.height / 2 << std::endl;
        }

        for (Shape* shape : shapes)
        {
          shape->scale(scaleFactor);
        }

        double totalAreaAfter = 0.0;
        for (Shape* shape : shapes)
        {
          rectangle_t frameRect = shape->getFrameRect();
          totalAreaAfter += shape->getArea();
          std::cout << std::fixed << std::setprecision(1) << frameRect.pos.x - frameRect.width / 2 << " "
                    << frameRect.pos.y - frameRect.height / 2 << " "
                    << frameRect.pos.x + frameRect.width / 2 << " "
                    << frameRect.pos.y + frameRect.height / 2 << std::endl;
        }

        std::cout << std::fixed << std::setprecision(1) << totalAreaBefore << " " << totalAreaAfter << std::endl;

        return 0;
      }
      else
      {
        std::cerr << "Warning: Unknown command" << std::endl;

        return 0;
      }
    }

    for (Shape* shape : shapes)
    {
      delete shape;
    }
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
    for (Shape* shape : shapes)
    {
      delete shape;
    }
    return 1;
  }

  return 0;
}
