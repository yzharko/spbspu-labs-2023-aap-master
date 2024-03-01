#include "shapes-output.hpp"
#include <iostream>
#include <iomanip>
#include "base-types.hpp"

void yartsev::printFrameRect(yartsev::Shape * shape)
{
  yartsev::rectangle_t frameRect = shape->getFrameRect();
  yartsev::point_t bottomLeft = frameRect.getLowerPoint();
  yartsev::point_t topRight = frameRect.getTopPoint();
  std::cout << " " << std::fixed << std::setprecision(1) << bottomLeft.x_ << " " << bottomLeft.y_;
  std::cout << " " << std::fixed << std::setprecision(1) << topRight.x_ << " " << topRight.y_;
}
