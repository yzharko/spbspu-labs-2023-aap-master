#include "triangle.hpp"

normalH.x = vertexC.x;
normalH.y = vertexA.y;
normal = sqrt(pow(normalH.x - vertexC.x, 2) + pow(normalH.y - vertexC.y, 2));
sideAb = sqrt(pow(vertexA.x - vertexB.x, 2) + pow(vertexA.y - vertexB.y, 2));
mindO.x = (vertexC.x + vertexB.x) / 2;
mindO.y = (vertexC.y + vertexB.y) / 2;
sectionAo = sqrt(pow(mindO.x - vertexA.x, 2) + pow(mindO.y - vertexA.y, 2));
pos.x = vertexA.x * 2 / 3 * sectionAo;
pos.y = vertexA.y * 2 / 3 * sectionAo;

double Triangle::getArea()
{
  return (0,5 * normal * sideAb);
}
rectangle_t Triangle::getFrameRect()
{
  rectangle_t frame;
  frame.width = sideAb;
  frame.height = normal;
  return frame;
}
void Triangle::move(point_t newPos)
{
  pos.x = newPos.x;
  pos.y = newPos.y;
}
void Triangle::move(double xPlus, double yPlus)
{
  pos.x += xPlus;
  pos.y += yPlus;
}
void Triangle::scale(double multiplier)
{
  vertexA.x *= multiplier;
  vertexA.y *= multiplier;
  vertexB.x *= multiplier;
  vertexB.y *= multiplier;
  vertexC.x *= multiplier;
  vertexC.y *= multiplier;
  pos.x *= multiplier;
  pos.y *= multiplier;
}
