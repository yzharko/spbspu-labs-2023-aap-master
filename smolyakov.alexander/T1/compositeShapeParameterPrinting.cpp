#include <iomanip>
#include <iostream>
#include "compositeShapeParameterPrinting.hpp"
#include "compositeShape.hpp"

void smolyakov::printCompositeShapeParameters(std::ostream &stream, const CompositeShape& compositeShape)
{
  for (size_t i = 0; i < compositeShape.shapes; i++)
  {
    rectangle_t frame = compositeShape.shapeptrs[i]->getFrameRect();
    stream << std::setprecision(1) << frame.pos.x - frame.width / 2.0 << ' '
      << frame.pos.y - frame.height / 2.0 << ' '
      << frame.pos.x + frame.width / 2.0 << ' '
      << frame.pos.y + frame.height / 2.0;
    stream << (i + 1 == compositeShape.shapes ? '\n' : ' ');
  }
}
