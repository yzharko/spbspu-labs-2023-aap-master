#include "scale_figures.hpp"
#include <iostream>
#include "shape.hpp"
#include "array_functions.hpp"
#include "string_process.hpp"


void reznikova::scaleFigures(Shape ** figures, const int stored, std::string& line)
{
  point_t center = getPointFromString(line);
  double n = getNextValue(line);

  if (n <= 0)
  {
    freeArray(figures, stored);
    throw std::runtime_error("Negative Coeff Scale\n");
  }
  if (stored == 0)
  {
    throw std::runtime_error("nothing to scale\n");
  }

  outputSum(figures, stored);

  for (int i = 0; i < stored; i++)
  {
    rectangle_t frame_rect = figures[i]->getFrameRect();
    outputFrame(frame_rect);
    figures[i]->scale(n);
  }
  std::cout << "\n";

  outputSum(figures, stored);

  for (int i = 0; i < stored; i++)
  {
    rectangle_t frame_rect = figures[i]->getFrameRect();
    frame_rect.pos.x += frame_rect.pos.x - center.x;
    frame_rect.pos.y += frame_rect.pos.y - center.y;
    outputFrame(frame_rect);
  }
  std::cout << "\n";
}
