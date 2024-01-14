#include <cmath>
#include "Parallelogram.hpp"
#include " base-types.hpp"

kaseev::Parallelogram::Parallelogram(point_t A, point_t B, point_t C):
A(A),
B(B),
C(C)
{}

double kaseev::Parallelogram::getArea() const
{
  point_t vectorFSide = {B.x - A.x, B.y - A.y};
  point_t vectorSSide = {C.x - B.x, C.y - B.y};
  double sizeFSide = std::sqrt(vectorFSide.x * vectorFSide.x + vectorSSide.y * vectorSSide.y);
  double sizeSSide = std::sqrt(vectorSSide.x * vectorSSide.x + vectorSSide.y * vectorSSide.y);
  double vectorCross = vectorFSide.x * vectorSSide.y - vectorFSide.y * vectorSSide.x;
  if (sizeFSide == 0 || sizeSSide == 0)
  {
    return 0.0;
  }
  else
  {
    double sin = vectorCross / (sizeSSide * sizeFSide);
    return (sizeFSide * sizeSSide) * sin;
  }
}

rectangle_t kaseev::Parallelogram::getFrameRect() const
{
  double height = std::abs(std::max(std::max(A.y, B.y), C.y) - std::min(std::min(A.y, B.y), C.y));
  double width = std::abs(std::max(std::max(A.x, B.x), C.x) - std::min(std::min(A.x, B.x), C.x));
  point_t cos = { ((std::max(std::max(A.x, B.x), C.x) + std::min(std::min(A.x, B.x), C.x)) * 0.5),((std::max(std::max(A.y, B.y), C.y) + std::min(std::min(A.y, B.y), C.y)) * 0.5) };
  rectangle_t frameRect = { width, height, cos };
  return frameRect;
}

void kaseev::Parallelogram::move(double nx, double ny)
{
  A = {A.x + nx, A.y + ny};
  B = {B.x + nx, B.y + ny};
  C = {C.x + nx, C.y + ny};
}

void kaseev::Parallelogram::move(point_t nCenter)
{
  double oldX = (A.x + B.x) / 2;
  double oldY = (A.y + C.y) / 2;
  move(nCenter.x - oldX, nCenter.y - oldY);
}

void kaseev::Parallelogram::scale(double k)
{
  double CenterY = (std::max(std::max(A.y, B.y), C.y) + std::min(std::min(A.y, B.y), C.y)) * 0.5;
  double CenterX = (std::max(std::max(A.x, B.x), C.x) + std::min(std::min(A.x, B.x), C.x)) * 0.5;
  A = { (CenterX + (A.x - CenterX) * k), (CenterY + (A.y - CenterY) * k) };
  B = { (CenterX + (B.x - CenterX) * k), (CenterY + (B.y - CenterY) * k) };
  C = { (CenterX + (C.x - CenterX) * k), (CenterY + (C.y - CenterY) * k) };
}
