#include "regular.hpp"
#include <cmath>

popov::Regular::Regular(float x1, float y1, float x2, float y2,float x3, float y3):
  first_pos_{x1,y1},
  second_pos_{x2,y2},
  third_pos_{x3,y3};
float popov::Regular::getDistance(const point_t& other)
{
  return sqrt(abs(pow((x - other.x), 2) + pow((y - other.y), 2)));
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
  point_t pos.x = (first_pos_.x - width) / 2;
  point_t pos.y = (first_pos_.y - height) / 2;
  return {width, hight, pos};
}
void popov::Regular::move(float x, float y)
{
  first_pos_{first_pos_.x + x,first_pos_.y + y},
  second_pos_{second_pos_.x + x,second_pos_.y + y},
  third_pos_{third_pos_.x + x,third_pos_.y + y};
}
void popov::Regular::scale(float n)
{
  first_pos_{first_pos_.x * n,first_pos_.y * n},
  second_pos_{second_pos_.x * n,second_pos_.y * n},
  third_pos_{third_pos_.x * n,third_pos_.y * n};
}
