#include <iostream>
#include "rectangle.hpp"

int main()
{
  psarev::Rectangle testRect({ 0.0, 0.0 }, {5.0, 7.0});
  rectangle_t testRectFrame = testRect.getFrameRect();
  std::cout << testRect.getArea() << " " << testRectFrame.width << " " << testRectFrame.height << '\n';

  testRect.move({ 5.0,5.0 });
  std::cout << "Move figure center to { 5.0, 5.0 }\n";
  testRectFrame = testRect.getFrameRect();
  std::cout << testRectFrame.pos.x << " " << testRectFrame.pos.y << '\n';

  testRect.move(4, 4);
  std::cout << "Change coordinates by 4 (x) and 4 (y) points\n";
  testRectFrame = testRect.getFrameRect();
  std::cout << testRectFrame.pos.x << " " << testRectFrame.pos.y << '\n';

  std::cout << "Scaling figure by 4.0 coefficient\n";
  testRect.scale(4.0);
  testRectFrame = testRect.getFrameRect();
  std::cout << testRectFrame.width << " " << testRectFrame.height << '\n';
}
