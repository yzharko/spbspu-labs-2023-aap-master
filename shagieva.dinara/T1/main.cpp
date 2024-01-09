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
  float x1, y1, x2, y2, x3, y3, x4, y4;

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
      shapes[shapeCount++] = new shagieva::ComplexQuad(shagieva::point_t{ x1, y1 }, shagieva::point_t{ x2, y2 }, shagieva::point_t{ x3, y3 }, shagieva::point_t{ x4, y4 });
    }
    else if (figureType == "REGULAR")
    {
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      shapes[shapeCount++] = new shagieva::Regular(shagieva::point_t{ x1, y1 }, shagieva::point_t{ x2, y2 }, shagieva::point_t{ x3, y3 });
    }
  }

  float totalAreaBeforeScaling = 0.0;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    shagieva::rectangle_t frame = shapes[i]->getFrameRect();
    totalAreaBeforeScaling += shapes[i]->getArea();
  }
  std::cout << totalAreaBeforeScaling << " ";

  for (size_t i = 0; i < shapeCount; ++i)
  {
    shagieva::rectangle_t frame = shapes[i]->getFrameRect();
    std::cout << std::fixed << std::setprecision(1)
      << frame.pos.x - frame.width / 2 << " " << frame.pos.y - frame.height / 2
      << " " << frame.pos.x + frame.width / 2 << " " << frame.pos.y + frame.height / 2 << " ";
  }
  std::cout << "\n";

  float scaleCenterX, scaleCenterY, scaleFactor;
  std::cin >> scaleCenterX >> scaleCenterY >> scaleFactor;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    shagieva::Shape * shape = shapes[i];
    shape->scale({ scaleCenterX, scaleCenterY }, scaleFactor);
  }

  float totalAreaAfterScaling = 0.0;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    shagieva::rectangle_t frame = shapes[i]->getFrameRect();
    totalAreaAfterScaling += shapes[i]->getArea();
  }
  std::cout << totalAreaAfterScaling << " ";

  for (size_t i = 0; i < shapeCount; ++i)
  {
    shagieva::rectangle_t frame = shapes[i]->getFrameRect();
    std::cout << std::fixed << std::setprecision(1)
      << frame.pos.x - frame.width / 2 << " " << frame.pos.y - frame.height / 2
      << " " << frame.pos.x + frame.width / 2 << " " << frame.pos.y + frame.height / 2 << " ";
  }
  std::cout << "\n";

  for (size_t i = 0; i < shapeCount; ++i)
  {
    delete shapes[i];
  }
  delete[] shapes;

  return 0;
}
