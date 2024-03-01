#include "shapesInput.hpp"
#include <iostream>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "ellipse.hpp"

void yartsev::inputFigure(std::string name, yartsev::Shape ** shape, size_t * shapesAmount)
{
  (*shapesAmount)++;
  if (name == "RECTANGLE") {
    double bottomLeftX, bottomLeftY, topRightX, topRightY;
    std::cin >> bottomLeftX >> bottomLeftY >> topRightX >> topRightY;
    yartsev::point_t bottomLeft(bottomLeftX, bottomLeftY);
    yartsev::point_t topRight(topRightX, topRightY);
    yartsev::Shape * ptr = new yartsev::Rectangle(bottomLeft, topRight);
    *shape = ptr;
  } else if (name == "CIRCLE") {
    double x, y, radius;
    std::cin >> x >> y >> radius;
    yartsev::point_t center(x, y);
    yartsev::Shape * ptr = new yartsev::Circle(center, radius);
    *shape = ptr;
  } else if (name == "ELLIPSE") {
    double x, y, radiusY, radiusX;
    std::cin >> x >> y >> radiusY >> radiusX;
    yartsev::point_t center(x, y);
    yartsev::Shape * ptr = new yartsev::Ellipse(center, radiusX, radiusY);
    *shape = ptr;
  } else {
    (*shapesAmount)--;
  }
}
