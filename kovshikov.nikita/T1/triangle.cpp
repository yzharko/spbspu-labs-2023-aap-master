#include "triangle.hpp"
#include "rectangle.hpp"

Triangle::Triangle(point_t vertexA, point_t vertexB, point_t vertexC):
  vertexA_(vertexA),
  vertexB_(vertexB),
  vertexC_(vertexC)
{};

double Triangle::getArea()
{
  double sideAb = sqrt(pow(vertexA_.x - vertexB_.x, 2) + pow(vertexA_.y - vertexB_.y, 2));
  double sideBc = sqrt(pow(vertexB_.x - vertexC_.x, 2) + pow(vertexB_.y - vertexC_.y, 2));
  double sideCa = sqrt(pow(vertexC_.x - vertexA_.x, 2) + pow(vertexC_.y - vertexA_.y, 2));
  double p = (sideAb + sideBc + sideCa) / 2;
  return sqrt(p * (p - sideAb) * (p - sideBc) * (p - sideCa));
}
rectangle_t Triangle::getFrameRect()
{
  double minX = std::min({vertexA_.x, vertexB_.x, vertexC_.x});
  double minY = std::min({vertexA_.y, vertexB_.y, vertexC_.y});
  double maxX = std::max({vertexA_.x, vertexB_.x, vertexC_.x});
  double maxY = std::max({vertexA_.y, vertexB_.y, vertexC_.y});
  point_t lowerLeft = {minX, minY};
  point_t upperRight = {maxX, maxY};
  Rectangle rectangle(lowerLeft, upperRight);
  return rect.getFrameRect();
}
void Triangle::move(point_t newPos)
{
  posX = (vertexA_.x + vertexB_.x + vertexC_.x) / 3;
  posY = (vertexA_.y + vertexB_.y + vertexC_.y) / 3;
  double xPlus = newPos.x - posX;
  double yPlus = newPos.y - posY;
  move(xPlus, yPlus);
}
void Triangle::move(double xPlus, double yPlus)
{
  vertexA.x += xPlus;
  vertexA.y += yPlus;
  vertexB.x += xPlus;
  vertexB.y += yPlus;
  vertexC.x += xPlus;
  vertexC.y += yPlus;
}
void Triangle::scale(double multiplier)
{
  vertexA.x *= multiplier;
  vertexA.y *= multip lier;
  vertexB.x *= multiplier;
  vertexB.y *= multiplier;
  vertexC.x *= multiplier;
  vertexC.y *= multiplier;
  pos.x *= multiplier;
  pos.y *= multiplier;
}
