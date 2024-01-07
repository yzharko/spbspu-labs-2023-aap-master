#include <iostream>
#include "base-types.hpp"
#include "rectangle.hpp"

int main()
{
  zheleznyakov::point_t leftTopPoint{ 3.0, 4.0 };
  zheleznyakov::point_t rightBottomPoint{ 7.0, 8.0 };
  zheleznyakov::Rectangle rectangle(leftTopPoint, rightBottomPoint);
  std::cout << rectangle.getArea() << '\n';
  std::cout << rectangle.getFrameRect().width << ' ' << rectangle.getFrameRect().height << '\n';
  rectangle.move(3, 4);
  std::cout << rectangle.getFrameRect().pos.x << ' ' << rectangle.getFrameRect().pos.y << '\n';
  return 0;
}