#include <iostream>
#include <cctype>
#include <algorithm>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "regular.hpp"
#include "validation.hpp"
#include "output.hpp"

int main()
{
  using namespace zheleznyakov;
  size_t shapesSize = 1;
  Shape **shapes = new Shape *[shapesSize];
  size_t currentShapeIndex = 0;
  std::string currentCommand = "";
  while (std::cin >> currentCommand)
  {
    if (currentShapeIndex == shapesSize)
    {
      Shape **newShapes = new Shape *[shapesSize + 1];
      for (size_t i = 0; i < shapesSize; ++i)
      {
        newShapes[i] = shapes[i];
      }
      delete[] shapes;
      shapes = newShapes;
      shapesSize++;
    }
    if (currentCommand == "RECTANGLE")
    {
      double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
      if (std::cin >> x1 >> y1 >> x2 >> y2 && checkIsRectangleCoords(x1, y1, x2, y2))
      {
        shapes[currentShapeIndex++] = new Rectangle(point_t{x1, y1}, point_t{x2, y2});
      }
      else
      {
        std::cerr << "Error: cannot read RECTANGLE\n";
      }
    }
    else if (currentCommand == "DIAMOND")
    {
      double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
      if (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 &&
          checkIsRighrTriangle(point_t{x1, y1}, point_t{x2, y2}, point_t{x3, y3}))
      {
        shapes[currentShapeIndex++] = new Diamond(point_t{x1, y1}, point_t{x2, y2}, point_t{x3, y3});
      }
      else
      {
        std::cerr << "Error: cannot read DIAMOND\n";
      }
    }
    else if (currentCommand == "REGULAR")
    {
      double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
      if (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 &&
          checkIsRighrTriangle(point_t{x1, y1}, point_t{x2, y2}, point_t{x3, y3}))
      {
        shapes[currentShapeIndex++] = new Regular(point_t{x1, y1}, point_t{x2, y2}, point_t{x3, y3});
      }
      else
      {
        std::cerr << "Error: cannot read REGULAR\n";
      }
    }
    else if (currentCommand == "SCALE")
    {
      double scaleCenterX = 0;
      double scaleCenterY = 0;
      double scaleCoefficent = 0;
      rectangle_t *rectanglesPreScale = new rectangle_t[currentShapeIndex];
      rectangle_t *rectanglesPostScale = new rectangle_t[currentShapeIndex];
      if (std::cin >> scaleCenterX >> scaleCenterY >> scaleCoefficent && currentShapeIndex > 0)
      {
        double totalAreaPreScale = 0, totalAreaPostScale = 0;
        size_t rectangleScaleIndex = 0;
        for (size_t i = 0; i < currentShapeIndex; i++)
        {
          Shape *currentShape = shapes[i];
          totalAreaPreScale += currentShape->getArea();
          rectanglesPreScale[rectangleScaleIndex] = currentShape->getFrameRect();
          point_t scaleCenterPoint{scaleCenterX, scaleCenterY};
          rectangle_t preScaleCurrentRect = rectanglesPreScale[rectangleScaleIndex];
          double newX = scaleCenterPoint.x + (preScaleCurrentRect.pos.x - scaleCenterPoint.x) * scaleCoefficent;
          double newY = scaleCenterPoint.x + (preScaleCurrentRect.pos.y - scaleCenterPoint.y) * scaleCoefficent;
          currentShape->scale(scaleCoefficent);
          rectangle_t currentRectangle = currentShape->getFrameRect();
          double movementDiffX = newX - currentRectangle.pos.x;
          double movementDiffY = newY - currentRectangle.pos.y;
          currentShape->move(movementDiffX, movementDiffY);
          rectanglesPostScale[rectangleScaleIndex] = currentShape->getFrameRect();
          totalAreaPostScale += currentShape->getArea();
          rectangleScaleIndex++;
        }
        std::cout << std::fixed << std::setprecision(1) << totalAreaPreScale << ' ';
        zheleznyakov::printRects(rectanglesPreScale, rectangleScaleIndex);
        std::cout << '\n';
        std::cout << std::fixed << std::setprecision(1) << totalAreaPostScale << ' ';
        zheleznyakov::printRects(rectanglesPostScale, rectangleScaleIndex);
        std::cout << '\n';
        delete[] rectanglesPreScale;
        delete[] rectanglesPostScale;
        delete[] shapes;
        return 0;
      }
      else
      {
        delete[] shapes;
        std::cerr << "Error: cannot read or execute SCALE\n";
      }
    }
  }
  return 0;
}
