#ifndef COMPOSITE_SHAPE_PARAMETER_PRINTING
#define COMPOSITE_SHAPE_PARAMETER_PRINTING
#include <ostream>
#include "compositeShape.hpp"

namespace smolyakov
{
  void printCompositeShapeParameters(std::ostream& stream, const CompositeShape& compositeShape);
}

#endif
