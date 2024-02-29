#include "shapesInput.hpp"
#include <iostream>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "ellipse.hpp"

void inputFigure(std::string name, yartsev::Shape ** shape)
{
  if (name == "RECTANGLE") {
    double bottomLeftX, bottomLeftY, topRightX, topRightY;
    std::cin >> bottomLeftX >> bottomLeftY >> topRightX >> topRightY;
    yartsev::point_t bottomLeft(bottomLeftX, bottomLeftY);
    yartsev::point_t topRight(topRightX, topRightY);
    yartsev::Rectangle rez(bottomLeft, topRight);
    *shape = &rez;
  } else if (name == "CIRCLE") {
    double x, y, radius;
    std::cin >> x >> y >> radius;
    yartsev::point_t center(x, y);
    yartsev::Circle rez(center, radius);
    *shape = &rez;
  } else if (name == "ELLIPSE") {
    double x, y, radiusY, radiusX;
    std::cin >> x >> y >> radiusY >> radiusX;
    yartsev::point_t center(x, y);
    yartsev::Ellipse rez(center, radiusX, radiusY);
    *shape = &rez;
  }
}
