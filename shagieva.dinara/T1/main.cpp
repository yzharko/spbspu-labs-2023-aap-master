#include <iostream>
#include <string>
#include <iomanip>
#include "rectangle.hpp"
#include "complexquad.hpp"
#include "regular.hpp"

int main()
{
  size_t capacity = 10;
  shagieva::Shape ** shapes = new shagieva::Shape * [capacity];
  size_t shapeCount = 0;

  std::string figureType;
  double x1, y1, x2, y2, x3, y3, x4, y4;

  while (true)
  {
    std::cin >> figureType;
    if (figureType == "SCALE")
    {
      break;
    }
    if (shapeCount == capacity)
    {
      capacity *= 2;
      shagieva::Shape ** newShapes = new shagieva::Shape * [capacity];
      for (size_t i = 0; i < shapeCount; ++i)
      {
        newShapes[i] = shapes[i];
      }
      delete[] shapes;
      shapes = newShapes;
    }

    if (figureType == "RECTANGLE")
    {
      std::cin >> x1 >> y1 >> x2 >> y2;
      shapes[shapeCount++] = new shagieva::Rectangle(shagieva::point_t{ x1, y1 }, shagieva::point_t{ x2, y2 });
    }
    else if (figureType == "COMPLEXQUAD")
    {
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
      shapes[shapeCount++] = new shagieva::Complexquad(shagieva::point_t{ x1, y1 },
        shagieva::point_t{ x2, y2 },
        shagieva::point_t{ x3, y3 },
        shagieva::point_t{ x4, y4 });
    }
    else if (figureType == "REGULAR")
    {
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      shapes[shapeCount++] = new shagieva::Regular(shagieva::point_t{ x1, y1 }, shagieva::point_t{ x2, y2 },
        shagieva::point_t{ x3, y3 });
    }
  }

  std::cout << std::fixed << std::setprecision(1);

  double totalAreaBeforeScaling = 0.0;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    totalAreaBeforeScaling += shapes[i]->getArea();
  }
  std::cout << totalAreaBeforeScaling << " ";

  for (size_t i = 0; i < shapeCount; ++i)
  {
    shagieva::rectangle_t frame = shapes[i]->getFrameRect();
    std::cout << frame.pos.x - frame.width / 2 << " "
              << frame.pos.y - frame.height / 2 << " "
              << frame.pos.x + frame.width / 2 << " "
              << frame.pos.y + frame.height / 2 << " ";
  }
  std::cout << "\n";

  double scaleCenterX, scaleCenterY, scaleFactor;
  std::cin >> scaleCenterX >> scaleCenterY >> scaleFactor;

  if (scaleFactor <= 0)
  {
    std::cerr << "Invalid scale factor entered.\n";
    return 1;
  }

  for (size_t i = 0; i < shapeCount; ++i)
  {
    shagieva::Shape * shape = shapes[i];
    shape->move({ scaleCenterX, scaleCenterY });
    shape->scale(scaleFactor);
  }

  double totalAreaAfterScaling = 0.0;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    totalAreaAfterScaling += shapes[i]->getArea();
  }
  std::cout << totalAreaAfterScaling << " ";

  for (size_t i = 0; i < shapeCount; ++i)
  {
    shagieva::rectangle_t frame = shapes[i]->getFrameRect();
    std::cout << frame.pos.x - frame.width / 2 << " "
              << frame.pos.y - frame.height / 2 << " "
              << frame.pos.x + frame.width / 2 << " "
              << frame.pos.y + frame.height / 2 << " ";
  }
  std::cout << "\n";

  for (size_t i = 0; i < shapeCount; ++i)
  {
    delete shapes[i];
  }
  delete[] shapes;

  return 0;
}
