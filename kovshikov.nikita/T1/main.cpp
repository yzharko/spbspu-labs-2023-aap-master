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
  bool isAtLeastOneFigure = false;
  while (std::cin >> shape)   // учесть ошибку из-за прерывания программы
  {
    if (shape == "RECTANGLE")
    {
       double lowerLeftX, lowerLeftY, upperRightX, upperRightY;
       std::cin >> lowerLeftX >> lowerLeftY >> upperRightX >> upperRightY;
       if (!std::cin || lowerLeftX >= upperRightX || lowerLeftY >= upperRightY)
       {
         isCorrectlyDescribe = false;
         continue;
       }
       geometricShapes[count++] = new Rectangle({lowerLeftX, lowerLeftY}, {upperRightX, upperRightY});
       isAtLeastOneFigure = true;
    }
    else if (shape == "TRIANGLE") // в классе треугольник проверить существует ли он
    {
      double vertexAX, vertexAY, vertexBX, vertexBY, vertexCX, vertexCY;
      std::cin >> vertexAX >> vertexAY >> vertexBX >> vertexBY >> vertexCX >> vertexCY;
      bool isAEquallyB = vertexAX == vertexBX && vertexAY == vertexBY;
      bool isAEquallyC = vertexAX == vertexCX && vertexAY == vertexCY;
      bool isCEquallyB = vertexCX == vertexBX && vertexCY == vertexBY;
      if(!std::cin || isAEquallyB || isAEquallyC || isCEquallyB)
      {
        isCorrectlyDescribe = false;
        continue;
      }

      geometricShapes[count++] = new Triangle({vertexAX, vertexAY}, {vertexBX, vertexBY}, {vertexCX, vertexCY});
      isAtLeastOneFigure = true;
      double check = geometricShapes[count - 1]->getArea();
      if(check == 0.0)
      {
        isCorrectlyDescribe = false;
        count -= 1;
        delete geometricShapes[count];
      }
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
          break;
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
          geometricShapes[count++] = new Polygon(nPointsPolygon, points);
          isAtLeastOneFigure = true;
          try
          {
            geometricShapes[count - 1]->getArea();
           }
          catch(const std::logic_error& e)
          {
            std::cerr << e.what();
            isCorrectlyDescribe = false;
            count -= 1;
            delete geometricShapes[count];
            std:: cout << "error";
          }
          break;
        }
      }
    }
    else if (shape == "SCALE")
    {
      if(isAtLeastOneFigure == false)
      {
        std::cerr << "Nothing to scale";
        return 1;
      }
      double posX, posY, multiplier;
      std::cin >> posX >> posY >> multiplier;
      if (!std::cin || multiplier < 0)
      {
        std::cerr << "The coefficient must be greater than zero!";
        for (size_t i = 0; i < count; i++)
        {
          delete geometricShapes[i];
        }
        return 1;
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
        /*double newPosX = 0 - posX;
        double newPosY = 0 - posY;
        geometricShapes[i]->move({newPosX, newPosY});
        geometricShapes[i]->scale(multiplier);*/
        rectangle_t BeforeFrame = geometricShapes[i]->getFrameRect();
       // double BeforelowerLeftX = BeforeFrame.pos.x - 0.5 * BeforeFrame.width;
       // double BeforelowerLeftY = BeforeFrame.pos.y - 0.5 * BeforeFrame.height;
        geometricShapes[i]->move({posX, posY});
        rectangle_t AfterFrame = geometricShapes[i]->getFrameRect();
      //  double AfterlowerLeftX = AfterFrame.pos.x - 0.5 * AfterFrame.width;
       // double AfterlowerLeftY = AfterFrame.pos.y - 0.5 * AfterFrame.height;
        geometricShapes[i]->scale(multiplier);
        double changeX = (BeforFrame.pos.x - AfterFrame.pos.x) * multiplier;
        double changeY = (BeforFrame.pos.y - AfterFrame.pos.y) * multiplier;
        geometricShapes[i]->move(changeX, changeY);
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
      std::cout << std::fixed << std::setprecision(1) << totalAreaAfter << " ";
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
  }
  if (std::cin.eof() && isScale == false)
  {
    std::cerr << "no scaling parameters were given";
    for (size_t i = 0; i < count; i++)
    {
      delete geometricShapes[i];
    }
    return 1;
  }
  for (size_t i = 0; i < count; i++)
  {
    delete geometricShapes[i];
  }
  return 0;
}

