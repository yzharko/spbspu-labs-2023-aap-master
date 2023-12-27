#include <iostream>
#include "rectangle.hpp"

int main()
{
  sobolevsky::Rectangle rectangle({ 1.0, 1.0 }, { 3.0, 4.0 });
  std::cout << rectangle.getArea() << '\n';
  std::cout << "width: " << rectangle.getFrameRect().width << '\n';
  std::cout << "height: " << rectangle.getFrameRect().height << '\n';
  rectangle.move(3, 4);
  std::cout << rectangle.getFrameRect().pos.x << ' ' << rectangle.getFrameRect().pos.y << '\n';
  return 0;
}
