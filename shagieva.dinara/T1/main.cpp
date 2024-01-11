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
  bool figureIsWrong = 0;
  bool scaleIsEntered = 0;

  while (std::cin)
  {
    if (shapeCount == capacity)
    {
      capacity *= 2;
      shagieva::Shape ** newShapes = new shagieva::Shape * [capacity];
      for (size_t i = 0; i < shapeCount; ++i)
      {
        newShapes[i] = shapes[i];
        delete[] shapes[i];
      }
      delete[] shapes;
      shapes = newShapes;
    }

    std::string figureType;
    std::cin >> figureType;

    if (figureType == "SCALE" && shapeCount == 0)
    {
      std::cerr << "Nothing to scale.\n";
      delete[] shapes;
      return 1;
    }

    if (figureType == "SCALE")
    {
      scaleIsEntered = true;
      break;
    }

    if (figureType == "RECTANGLE")
    {
      double x1, y1, x2, y2;
      std::cin >> x1 >> y1 >> x2 >> y2;
      if (x1 < x2 && y1 < y2)
      {
        shapes[shapeCount++] = new shagieva::Rectangle(shagieva::point_t{ x1, y1 }, shagieva::point_t{ x2, y2 });
      }
      else
      {
        figureIsWrong = true;
      }
    }

    else if (figureType == "COMPLEXQUAD")
    {
      double x1, y1, x2, y2, x3, y3, x4, y4;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
      shapes[shapeCount++] = new shagieva::Complexquad(shagieva::point_t{ x1, y1 },
        shagieva::point_t{ x2, y2 },
        shagieva::point_t{ x3, y3 },
        shagieva::point_t{ x4, y4 });
    }

    else if (figureType == "REGULAR")
    {
      double x1, y1, x2, y2, x3, y3;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      shapes[shapeCount++] = new shagieva::Regular(shagieva::point_t{ x1, y1 }, shagieva::point_t{ x2, y2 },
        shagieva::point_t{ x3, y3 });
    }

    else
    {
      figureIsWrong = true;
    }
  }

  if (!scaleIsEntered)
  {
    std::cerr << "Scale command is not entered.\n";
    for (size_t i = 0; i < shapeCount; ++i)
    {
      delete shapes[i];
    }
    delete[] shapes;
    return 1;
  }

  double scaleCenterX, scaleCenterY, scaleFactor;
  std::cin >> scaleCenterX >> scaleCenterY >> scaleFactor;

  if (scaleFactor <= 0.0)
  {
    std::cerr << "Invalid scale factor entered.\n";
    for (size_t i = 0; i < shapeCount; ++i)
    {
      delete shapes[i];
    }
    delete[] shapes;
    return 1;
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
              << frame.pos.y + frame.height / 2
              << ((i == (shapeCount - 1)) ? "\n" : " ");
  }

  for (size_t i = 0; i < shapeCount; ++i)
  {
    shagieva::rectangle_t frameBeforeMoving = shapes[i]->getFrameRect();
    shapes[i]->move({ scaleCenterX, scaleCenterY });
    shagieva::rectangle_t frameAfterMoving = shapes[i]->getFrameRect();
    shapes[i]->scale(scaleFactor);
    double dx = (frameBeforeMoving.pos.x - frameAfterMoving.pos.x) * scaleFactor;
    double dy = (frameBeforeMoving.pos.y - frameAfterMoving.pos.y) * scaleFactor;
    shapes[i]->move(dx, dy);
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
              << frame.pos.y + frame.height / 2
              << ((i == (shapeCount - 1)) ? "\n" : " ");
  }

  if (figureIsWrong)
  {
    std::cerr << "Invalid figure entered.\n";
  }

  for (size_t i = 0; i < shapeCount; ++i)
  {
    delete shapes[i];
  }
  delete[] shapes;

  return 0;
}
