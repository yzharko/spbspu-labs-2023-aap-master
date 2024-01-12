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
  bool shapesAreScaled = false;

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
        for (int i = 0; i < shapesCounter; i++)
        {
          delete shapes[i];
        }
        delete[] shapes;
        return 1;
      }
      double areasSum = 0;
      double scaledAreasSum = 0;
      double distanceX = 0;
      double distanceY = 0;
      redko::rectangle_t frame = {};
      redko::rectangle_t movedFrame = {};
      double* frameXY = new double[shapesCounter * 4];
      double* scaledFrameXY = new double[shapesCounter * 4];
      for (int i = 0; i < shapesCounter; i++)
      {
        areasSum += shapes[i]->getArea();
        frame = shapes[i]->getFrameRect();
        frameXY[4 * i] = frame.pos.x - frame.width / 2.0;
        frameXY[4 * i + 1] = frame.pos.y - frame.height / 2.0;
        frameXY[4 * i + 2] = frame.pos.x + frame.width / 2.0;
        frameXY[4 * i + 3] = frame.pos.y + frame.height / 2.0;

        shapes[i]->move({ x, y });
        movedFrame = shapes[i]->getFrameRect();
        distanceX = (frame.pos.x - movedFrame.pos.x) * coefficient;
        distanceY = (frame.pos.y - movedFrame.pos.y) * coefficient;
        shapes[i]->scale(coefficient);
        shapes[i]->move(distanceX, distanceY);

        scaledAreasSum += shapes[i]->getArea();
        frame = shapes[i]->getFrameRect();
        scaledFrameXY[4 * i] = frame.pos.x - frame.width / 2.0;
        scaledFrameXY[4 * i + 1] = frame.pos.y - frame.height / 2.0;
        scaledFrameXY[4 * i + 2] = frame.pos.x + frame.width / 2.0;
        scaledFrameXY[4 * i + 3] = frame.pos.y + frame.height / 2.0;
      }
      std::cout << std::fixed << std::setprecision(1) << areasSum;
      for (int i = 0; i < shapesCounter * 4; i++)
      {
        std::cout << ' ' << frameXY[i];
      }
      std::cout << '\n' << scaledAreasSum;
      for (int i = 0; i < shapesCounter * 4; i++)
      {
        std::cout << ' ' << scaledFrameXY[i];
      }
      std::cout << '\n';
      if (someDescrIsWrong)
      {
        std::cerr << "errors in the description of supported shapes\n";
      }
      for (int i = 0; i < shapesCounter; i++)
      {
        delete shapes[i];
      }
      delete[] shapes;
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
  if (!shapesAreScaled)
  {
    std::cerr << "shapes was not scaled\n";
    for (int i = 0; i < shapesCounter; i++)
    {
      delete shapes[i];
    }
    delete[] shapes;
    return 1;
  }
}
