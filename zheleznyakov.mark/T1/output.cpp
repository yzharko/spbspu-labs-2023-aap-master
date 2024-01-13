#include "output.hpp"

void zheleznyakov::printRects(rectangle_t *rectangles, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    const rectangle_t currentRectangle = rectangles[i];
    const double borderLeftxBottomX = currentRectangle.pos.x - (currentRectangle.width / 2);
    const double borderLeftBottomY = currentRectangle.pos.y - (currentRectangle.height / 2);
    const double borderRightTopX = currentRectangle.pos.x + (currentRectangle.width / 2);
    const double borderRightTopY = currentRectangle.pos.y + (currentRectangle.height / 2);
    std::cout << std::fixed << std::setprecision(1)
              << borderLeftxBottomX << ' ' << borderLeftBottomY << ' '
              << borderRightTopX << ' ' << borderRightTopY << (i == size - 1 ? " " : "");
  }
}