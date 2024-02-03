#include "array_functions.hpp"
#include <iomanip>
#include <iostream>
#include "shape.hpp"

void reznikova::freeArray(Shape ** figures, const int stored)
{
  for (int i = 0; i < stored; i++)
  {
    delete figures[i];
  }
}

void reznikova::outputSum(Shape ** figures, const int stored)
{
  double sum_area = 0;
  for (int i = 0; i < stored; i++)
  {
    sum_area += figures[i]->getArea();
  }
  std::cout << std::fixed << std::setprecision(1) << sum_area;
}

void reznikova::outputFrame(rectangle_t frame_rect)
{
  double leftpoint_x = (frame_rect.pos.x - frame_rect.width/2);
  double leftpoint_y = (frame_rect.pos.y - frame_rect.height/2);
  double rightpoint_x = (frame_rect.pos.x + frame_rect.width/2);
  double rightpoint_y = (frame_rect.pos.y + frame_rect.height/2);
  std::cout << std::fixed << std::setprecision(1) << ' ' << leftpoint_x << ' ' << leftpoint_y;
  std::cout << std::fixed << std::setprecision(1) << ' ' << rightpoint_x << ' ' << rightpoint_y;
}
