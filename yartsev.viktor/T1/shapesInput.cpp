#include "shapesInput.hpp"
#include <iostream>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "ellipse.hpp"

void yartsev::inputFigure(std::string name, yartsev::Shape ** shape, size_t * shapesAmount)
{
  yartsev::Shape * ptr = nullptr;
  if (name == "RECTANGLE") {
    double bottomLeftX, bottomLeftY, topRightX, topRightY;
    std::cin >> bottomLeftX >> bottomLeftY >> topRightX >> topRightY;
    yartsev::point_t bottomLeft(bottomLeftX, bottomLeftY);
    yartsev::point_t topRight(topRightX, topRightY);
  } else if (name == "CIRCLE") {
    double x, y, radius;
    std::cin >> x >> y >> radius;
    yartsev::point_t center(x, y);
    try {
      ptr = new yartsev::Circle(center, radius);
    } catch (const std::logic_error & e) {
      delete ptr;
      throw;
    }
  } else if (name == "ELLIPSE") {
    double x, y, radiusY, radiusX;
    std::cin >> x >> y >> radiusY >> radiusX;
    yartsev::point_t center(x, y);
    try {
      ptr = new yartsev::Ellipse(center, radiusX, radiusY);
    } catch (const std::logic_error & e) {
      delete ptr;
      throw;
    }
  }
  *shape = ptr;
  if (ptr != nullptr) {
    (*shapesAmount)++;
  }
}
