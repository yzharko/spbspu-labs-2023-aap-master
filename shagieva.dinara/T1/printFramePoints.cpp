#include "printFramePoints.hpp"
#include "base-types.hpp"
#include <iostream>

void shagieva::printFramePoints(const shagieva::Shape * const * const shapes, const size_t & shapeCount)
{
  for (size_t i = 0; i < shapeCount; ++i)
  {
    shagieva::rectangle_t frame = shapes[i]->getFrameRect();
    std::cout << frame.pos.x - frame.width / 2 << " "
              << frame.pos.y - frame.height / 2 << " "
              << frame.pos.x + frame.width / 2 << " "
              << frame.pos.y + frame.height / 2
              << ((i == (shapeCount - 1)) ? "\n" : " ");
  }
}
