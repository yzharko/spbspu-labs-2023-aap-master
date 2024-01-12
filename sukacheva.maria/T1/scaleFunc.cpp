#include "scaleFunc.hpp"
#include <iostream>
#include <iomanip>

void sukacheva::getCoordinates(sukacheva::rectangle_t frameRect) {
  double x1, y1, x2, y2 = 0;
  x1 = frameRect.pos.x - frameRect.width / 2.0;
  y1 = frameRect.pos.y - frameRect.height / 2.0;
  x2 = frameRect.pos.x + frameRect.width / 2.0;
  y2 = frameRect.pos.y + frameRect.height / 2.0;
  std::cout << std::fixed << std::setprecision(1) << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2;
}
