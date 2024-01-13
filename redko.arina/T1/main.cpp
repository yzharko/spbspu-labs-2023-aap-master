#include <iostream>
#include <iomanip>
#include "shape.hpp"
#include "parallelogram.hpp"
#include "rectangle.hpp"
#include "concave.hpp"
#include "shapeProcessing.hpp"

int main()
{
  redko::Shape ** shapes = new redko::Shape * [1000] {};
  redko::point_t * points = nullptr;
  int shapesCounter = 0;
  std::string type = "";
  bool someDescrIsWrong = false;

  while (std::cin >> type)
  {
    if (type == "SCALE")
    {
      if (shapesCounter == 0)
      {
        std::cerr << "no shapes to scale\n";
        delete[] shapes;
        return 1;
      }
      double x, y, coefficient;
      if (!(std::cin >> x >> y >> coefficient) || coefficient <= 0)
      {
        std::cerr << "wrong scale parameters\n";
        redko::deleteShapes(shapes, shapesCounter);
        return 1;
      }

      double areasSum = redko::countAreas(shapes, shapesCounter);
      double * frameXY = redko::getFrameCorners(shapes, shapesCounter);

      double distanceX = 0;
      double distanceY = 0;
      redko::rectangle_t frame = {};
      redko::rectangle_t movedFrame = {};
      for (int i = 0; i < shapesCounter; i++)
      {
        frame = shapes[i]->getFrameRect();
        shapes[i]->move({ x, y });
        movedFrame = shapes[i]->getFrameRect();
        distanceX = (frame.pos.x - movedFrame.pos.x) * coefficient;
        distanceY = (frame.pos.y - movedFrame.pos.y) * coefficient;
        shapes[i]->scale(coefficient);
        shapes[i]->move(distanceX, distanceY);
      }

      double scaledAreasSum = redko::countAreas(shapes, shapesCounter);
      double * scaledFrameXY = redko::getFrameCorners(shapes, shapesCounter);

      std::cout << std::fixed << std::setprecision(1) << areasSum;
      redko::printFrameCorners(frameXY, shapesCounter);
      std::cout << '\n' << scaledAreasSum;
      redko::printFrameCorners(scaledFrameXY, shapesCounter);
      std::cout << '\n';

      if (someDescrIsWrong)
      {
        std::cerr << "errors in the description of supported shapes\n";
      }
      redko::deleteShapes(shapes, shapesCounter);
      delete[] frameXY;
      delete[] scaledFrameXY;
      return 0;
    }

    if (!redko::isTypeCorrect(type))
    {
      continue;
    }

    if (type == "RECTANGLE")
    {
      points = redko::getRectanglePoints();
      if (redko::isRectangleCorrect(points))
      {
        shapes[shapesCounter++] = new redko::Rectangle(points[0], points[1]);
      }
      else
      {
        someDescrIsWrong = true;
      }
    }
    else if (type == "PARALLELOGRAM")
    {
      points = redko::getParallelogramPoints();
      if (redko::isParallelogramCorrect(points))
      {
        shapes[shapesCounter++] = new redko::Parallelogram(points[0], points[1], points[2]);
      }
      else
      {
        someDescrIsWrong = true;
      }
    }
    else if (type == "CONCAVE")
    {
      points = redko::getConcavePoints();
      if (redko::isConcaveCorrect(points))
      {
        shapes[shapesCounter++] = new redko::Concave(points[0], points[1], points[2], points[3]);
      }
      else
      {
        someDescrIsWrong = true;
      }
    }
    delete[] points;
  }
  std::cerr << "shapes was not scaled\n";
  redko::deleteShapes(shapes, shapesCounter);
  return 1;
}
