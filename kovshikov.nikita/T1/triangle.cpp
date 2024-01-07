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
  return rectangle.getFrameRect();
}
void Triangle::move(point_t newPos)
{
  point_t pos = getPos();
  double xPlus = newPos.x - pos.x;
  double yPlus = newPos.y - pos.y;
  move(xPlus, yPlus);
}
void Triangle::move(double xPlus, double yPlus)
{
  vertexA_.x += xPlus;
  vertexA_.y += yPlus;
  vertexB_.x += xPlus;
  vertexB_.y += yPlus;
  vertexC_.x += xPlus;
  vertexC_.y += yPlus;
}
void Triangle::scale(double multiplier)
{
  point_t pos = getPos();
  changeVertex(multiplier, pos, vertexA_);
  changeVertex(multiplier, pos, vertexB_);
  changeVertex(multiplier, pos, vertexC_);
}
point_t Triangle::getPos()
{
  posX = (vertexA_.x + vertexB_.x + vertexC_.x) / 3;
  posY = (vertexA_.y + vertexB_.y + vertexC_.y) / 3;
  return point_t{ posX, posY };
}
double Triangle::changeVertex(const double multiplier, const point_t pos, point_t &vertex)
{
  double changeX = (vertex.x - pos.x) * multiplier;
  vertex.x += changeX;
  double changeY = (vertex.y - pos.y) * multiplier;
  vertex.y += changeY;
}
