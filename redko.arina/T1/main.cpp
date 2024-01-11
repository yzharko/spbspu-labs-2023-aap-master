#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "shape.hpp"
#include "parallelogram.hpp"
#include "rectangle.hpp"
#include "concave.hpp"

int main()
{
  redko::Shape** shapes = new redko::Shape * [1000] {};
  redko::point_t* points = nullptr;
  int shapesCounter = 0;
  std::string shape, type = "";
  bool some_descr_is_wrong = false;
  bool shapes_are_scaled = false;
  double x, y;
  std::stringstream shapeStream("");

  while (!std::cin.eof())
  {
    std::getline(std::cin, shape);
    shapeStream << shape;
    shapeStream >> type;
    if (type == "SCALE")
    {
      if (shapesCounter == 0)
      {
        std::cerr << "no shapes to scale\n";
        delete[] shapes;
        return 1;
      }
      double coefficient;
      if (!(shapeStream >> x >> y >> coefficient) || coefficient <= 0)
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
      if (some_descr_is_wrong)
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
    points = new redko::point_t[4] {};
    int i = 0;
    bool descr_is_wrong = false;

    if (type == "RECTANGLE")
    {
      while (shapeStream >> x)
      {
        if (i > 1 || !(shapeStream >> y))
        {
          some_descr_is_wrong = true;
          descr_is_wrong = true;
          break;
        }
        points[i++] = { x, y };
      }
      if (points[0].x > points[1].x || points[0].y > points[1].y)
      {
        some_descr_is_wrong = true;
      }
      else if (!descr_is_wrong && i == 2)
      {
        shapes[shapesCounter++] = new redko::Rectangle(points[0], points[1]);
      }
    }
    else if (type == "PARALLELOGRAM")
    {
      while (shapeStream >> x)
      {
        if (i > 2 || !(shapeStream >> y))
        {
          some_descr_is_wrong = true;
          descr_is_wrong = true;
          break;
        }
        points[i++] = { x, y };
      }
      if (points[0].y != points[1].y && points[2].y != points[0].y)
      {
        some_descr_is_wrong = true;
      }
      else if (!descr_is_wrong && i == 3)
      {
        shapes[shapesCounter++] = new redko::Parallelogram(points[0], points[1], points[2]);
      }
    }
    else if (type == "CONCAVE")
    {
      while (shapeStream >> x)
      {
        if (i > 3 || !(shapeStream >> y))
        {
          some_descr_is_wrong = true;
          descr_is_wrong = true;
          break;
        }
        points[i++] = { x, y };
      }
      double firstTriangle = points[0].x * (points[1].y - points[3].y) + points[1].x * (points[3].y - points[0].y);
      firstTriangle = std::abs((firstTriangle + points[3].x * (points[0].y - points[1].y)) / 2.0);
      double secondTriangle = points[0].x * (points[3].y - points[2].y) + points[3].x * (points[2].y - points[0].y);
      secondTriangle = std::abs((secondTriangle + points[2].x * (points[0].y - points[3].y)) / 2.0);
      double thirdTriangle = points[3].x * (points[1].y - points[2].y) + points[1].x * (points[2].y - points[3].y);
      thirdTriangle = std::abs((thirdTriangle + points[2].x * (points[3].y - points[1].y)) / 2.0);
      double fourthTriangle = points[0].x * (points[1].y - points[2].y) + points[1].x * (points[2].y - points[0].y);
      fourthTriangle = std::abs((fourthTriangle + points[2].x * (points[0].y - points[1].y)) / 2.0);
      double sumOfTriangles = firstTriangle + secondTriangle + thirdTriangle;
      if (firstTriangle * secondTriangle * thirdTriangle * fourthTriangle == 0 || sumOfTriangles != fourthTriangle)
      {
        some_descr_is_wrong = true;
      }
      else if (!descr_is_wrong && i == 4)
      {
        shapes[shapesCounter++] = new redko::Concave(points[0], points[1], points[2], points[3]);
      }
    }
    delete[] points;
    shapeStream.str(std::string());
    shapeStream.clear();
  }
  if (!shapes_are_scaled)
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
