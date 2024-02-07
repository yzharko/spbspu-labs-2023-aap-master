#include "concave.hpp"
#include <cmath>
#include <iostream>

popov::Concave::Concave(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4):
  A_{x1,y1},
  B_{x2,y2},
  C_{x3,y3},
  D_{x4,y4};
float popov::Concave::getArea()
{
  float AB = sqrt((B_.x - A_.x) * (B_.x - A_.x) + (B_.y - A_.y) * (B_.y - A_.y));
  float AC = sqrt((C_.x - A_.x) * (C_.x - A_.x) + (C_.y - A_.y) * (C_.y - A_.y));
  float BD = sqrt((B_.x - D_.x) * (B_.x - D_.x) + (B_.y - D_.y) * (B_.y - D_.y));
  float CD = sqrt((C_.x - D_.x) * (C_.x - D_.x) + (C_.y - D_.y) * (C_.y - D_.y));
  float CB = sqrt((C_.x - B_.x) * (C_.x - B_.x) + (C_.y - B_.y) * (C_.y - B_.y));
  float F = (AB + AC + CB) / 2;
  float W = (BD + CD + CB) / 2;
  float FS = sqrt(F * (F - AB) * (F - AC) * (F - CB));
  float WS = sqrt(W * (W - BD) * (W - CD) * (W - CB));
  return FS - WS;
}
popov::rectangle_t popov::Concave::getFrameRect()
{
  float left = std::min(std::min(A_.x, B_.x), C_.x);
  float right = std::max(std::max(A_.x, B_.x), C_.x);
  float up = std::max(std::max(A_.y, B_.y), C_.y);
  float down = std::min(std::min(A_.y, B_.y), C_.y);
  float width = right - left;
  float height = up - down;
  point_t pos.x = (right + left) / 2;
  point_t pos.y = (up + down) / 2;
  return {width, height, pos};
}
void popov::Concave::move(float x, float y)
{
  A_{A_.x + x, A_.y + y},
  B_{B_.x + x, B_.y + y},
  C_{C_.x + x, C_.y + y},
  D_{D_.x + x, D_.y + y};
}
void popov::Concave::scale(float n)
{
  A_{(A_.x - D_.x) * n + D_.x, (A_.y - D_.y) * n + D_.y},
  B_{(B_.x - D_.x) * n + D_.x, (B_.y - D_.y) * n + D_.y},
  C_{(C_.x - D_.x) * n + D_.x, (C_.y - D_.y) * n + D_.y};
}
