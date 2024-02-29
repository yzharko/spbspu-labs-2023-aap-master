#include "shapes-output.hpp"
#include <iostream>
#include "base-types.hpp"

void printFrameRect(yartsev::Shape * shape)
{
  yartsev::rectangle_t frameRect = shape->getFrameRect();
  yartsev::point_t bottomLeft = frameRect.getLowerPoint();
  yartsev::point_t topRight = frameRect.getTopPoint();
  std::cout << frameRect.getArea() << " ";
  std::cout << bottomLeft.x_ << " " << bottomLeft.y_ << " ";
  std::cout << topRight.x_ << " " << topRight.y_ << "\n";
}