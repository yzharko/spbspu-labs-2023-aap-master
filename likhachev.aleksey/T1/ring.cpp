#include "ring.hpp"

likhachev::Ring::Ring(point_t pos, double outerRad, double innerRad):
  outerRad_(outerRad),
  innerRad_(innerRad),
  pos_(pos)
{
  if (outerRad_ <= 0 || innerRad_ <= 0 || outerRad_ <= innerRad_) {
    throw std::logic_error("The parameters are not logically incorrect\n");
  }
}

likhachev::Ring::Ring(double posX, double posY, double outerRad, double innerRad):
  outerRad_(outerRad),
  innerRad_(innerRad),
  pos_(likhachev::point_t(posX, posY))
{
  if (outerRad_ <= 0 || innerRad_ <= 0) {
    throw std::logic_error("The parameters are not logically incorrect\n");
  }
}

double likhachev::Ring::getArea() const
{
  const double PI = 3.141592653589793;
  double outerArea = PI * outerRad_ * outerRad_;
  double innerArea = PI * innerRad_ * innerRad_;

  return outerArea - innerArea;
}

likhachev::rectangle_t likhachev::Ring::getFrameRect() const
{
  double width = outerRad_ * 2;
  double height = outerRad_ * 2;
  likhachev::point_t pos(pos_);

  return rectangle_t(width, height, pos);
}

void likhachev::Ring::move(const point_t& offset)
{
  move(offset.x - pos_.x, offset.y - pos_.y);
}

void likhachev::Ring::move(double offsetX, double offsetY)
{
   likhachev::point_t offset(offsetX, offsetY);
   pos_ += offset;
}

void likhachev::Ring::scale(double multiplier)
{
  outerRad_ *= multiplier;
  innerRad_ *= multiplier;
}

likhachev::point_t likhachev::Ring::getPos() const
{
  return pos_;
}

double likhachev::Ring::getOuterRad() const
{
  return outerRad_;
}

double likhachev::Ring::getInnerRad() const
{
  return innerRad_;
}
