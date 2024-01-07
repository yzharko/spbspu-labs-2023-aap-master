#include "regular.hpp"
#include <cmath>

popov::Regular::Regular(float x1, float y1, float x2, float y2,float x3, float y3):
  first_pos_{x1,y1},
  second_pos_{x2,y2},
  third_pos_{x3,y3};
float popov::Regular::getDistance(const point_t& other)
{
  return sqrt(abs(pow((x_ - other.x_), 2) + pow((y_ - other.y_), 2)));
}
float popov::Regular::getArea()
{
  float k = first_pos_.getDistance(second_pos_);
  float perimeter = ((2 * k) * 4);
  return 0.5 * perimeter * k;
}
popov::rectangle_t popov::Rectangle::getFrameRect()
{
  float width = first_pos_.getDistance(second_pos_) * 2;
  float height = first_pos_.getDistance(second_pos_) * 2;
  point_t pos.x = first_pos_.x - width / 2);
  point_t pos.y = first_pos_.y - height / 2);
  return {width, hight, pos};
}
void popov::Regular::move(float x, float y)
{
  first_pos_{x1 + x,y1 + y},
  second_pos_{x2 + x,y2 + y},
  third_pos_{x3 + x,y3 + y};
}
void scale(float n)
{
  first_pos_{x1 * n,y1 * n},
  second_pos_{x2 * n,y2 * n},
  third_pos_{x3 * n,y3 * n};
}
