#include <iostream>
#include <iomanip>
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "polygon.hpp"

int main()
{
  using namespace kovshikov;
  std::string shape;
  size_t count = 0;
  Shape * geometricShapes[1000] = {nullptr}; // массив указателей на shape?
  bool isCorrectlyDescribe = true;
  bool isScale = false;
  while (std::cin >> shape)   // учесть ошибку из-за прерывания программы
  {
    if (shape == "RECTANGLE")
    {
       double lowerLeftX, lowerLeftY, upperRightX, upperRightY;
       std::cin >> lowerLeftX >> lowerLeftY >> upperRightX >> upperRightY;
       if (!std::cin)
       {
         isCorrectlyDescribe = false;
         continue;
       }
       *geometricShapes[count++] = Rectangle({lowerLeftX, lowerLeftY}, {upperRightX, upperRightY});
       std::cout << count;
    }
    else if (shape == "TRIANGLE") // в классе треугольник проверить существует ли он
    {
      double vertexAX, vertexAY, vertexBX, vertexBY, vertexCX, vertexCY;
      std::cin >> vertexAX >> vertexAY >> vertexBX >> vertexBY >> vertexCX >> vertexCY;
      if(!std::cin)
      {
        isCorrectlyDescribe = false;
        continue;
      }
      *geometricShapes[count++] = Triangle({vertexAX, vertexAY}, {vertexBX, vertexBY}, {vertexCX, vertexCY});
      std::cout << count;
    }
    else if (shape == "POLYGON")
    {
      size_t sizePolygon = 20;
      int addPolygon = 20;
      point_t * points = new point_t[sizePolygon];
      double coordinateX, coordinateY;
      size_t nPointsPolygon = 0;
      while(std::cin >> coordinateX >> coordinateY)
      {
        points[nPointsPolygon].x = coordinateX;
        points[nPointsPolygon++].y = coordinateY;
        if (!std::cin)
        {
          isCorrectlyDescribe = false;
          continue;
        }
        if (nPointsPolygon == sizePolygon)
        {
          point_t * newArray = new point_t[sizePolygon + addPolygon];
          for (size_t i = 0; i < nPointsPolygon; i++)
          {
            newArray[i] = points[i];     // нужно ли для каждой координаты или хватит точки????
          }
          delete[] points;
          points = newArray;
          newArray = nullptr;
        }
        if(std::cin.peek() == '\n')
        {
          *geometricShapes[count++] = Polygon(nPointsPolygon, points);
          std::cout << count;
          continue;
        }
      }
    }
    else if (shape == "SCALE")
    {
      std::cout << "ura";
      std::cout << count; /////////////////
      double posX, posY, multiplier;
      std::cin >> posX >> posY >> multiplier;
      if (!std::cin || multiplier < 0)
      {
        continue;
      }
      double totalAreaBefore = 0;
      for (size_t i = 0; i < count; i++)
      {
        totalAreaBefore += geometricShapes[i]->getArea();
      }
      std::cout << std::fixed << std::setprecision(1) << totalAreaBefore << " ";
      for (size_t i = 0; i < count; i++)
      {
        rectangle_t frame = geometricShapes[i]->getFrameRect();
        double lowerLeftX = frame.pos.x - 0.5 * frame.width;
        double lowerLeftY = frame.pos.y - 0.5 * frame.height;
        double upperRightX = frame.pos.x + 0.5 * frame.width;
        double upperRightY = frame.pos.y + 0.5 * frame.height;
        std::cout << std::fixed << std::setprecision(1) << lowerLeftX << " " << lowerLeftY << " ";
        std::cout << std::fixed << std::setprecision(1) << upperRightX << " " << upperRightY;
        if (i != count - 1)
        {
          std::cout << " ";
        }
      }
      std::cout << "\n";
      for (size_t i = 0; i < count; i++)
      {
        geometricShapes[i]->move(posX, posY);
        geometricShapes[i]->scale(multiplier);
      }
      if (isCorrectlyDescribe == false)
      {
        std::cerr << "some figure was incorrectly described!!!";
      }
      double totalAreaAfter = 0;
      for (size_t i = 0; i < count; i++)
      {
        totalAreaAfter += geometricShapes[i]->getArea();
      }
      std::cout << std::fixed << std::setprecision(1) << totalAreaBefore << " ";
      for (size_t i = 0; i < count; i++)
      {
        rectangle_t frame = geometricShapes[i]->getFrameRect();
        double lowerLeftX = frame.pos.x - 0.5 * frame.width;
        double lowerLeftY = frame.pos.y - 0.5 * frame.height;
        double upperRightX = frame.pos.x + 0.5 * frame.width;
        double upperRightY = frame.pos.y + 0.5 * frame.height;
        std::cout << std::fixed << std::setprecision(1) << lowerLeftX << " " << lowerLeftY << " ";
        std::cout << std::fixed << std::setprecision(1) << upperRightX << " " << upperRightY;
        if (i != count - 1)
        {
          std::cout << " ";
        }
      }
      std::cout << "\n";
      isScale = true;
      break;
    }
    else if (std::cin.eof() && isScale == false)
    {
      std::cerr << "no scaling parameters were given";
      return 1;
    }
  }
  return 0;
}

