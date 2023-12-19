#include <iostream>
#include "rectangle.hpp"
#include "ring.hpp"
#include "triangle.hpp"

int main()
{
  psarev::Rectangle testRect({ 1.0, 1.0 }, { 3.0, 4.0 });
  rectangle_t testRectFrame = testRect.getFrameRect();
  std::cout << "Area - " << testRect.getArea() << '\n';

  testRect.move({ 5.0, 2.0 });
  testRectFrame = testRect.getFrameRect();
  std::cout << "New center in { " << testRectFrame.pos.x << ", " << testRectFrame.pos.y << " }\n";

  testRect.move(4, -3);
  testRectFrame = testRect.getFrameRect();
  std::cout << "New center in { " << testRectFrame.pos.x << ", " << testRectFrame.pos.y << " }\n";

  testRect.scale(4.0);
  std::cout << "New area - " << testRect.getArea() << '\n';

  psarev::Ring testRing({ 2.0, 3.0 }, 20.0, 15.0);
  rectangle_t testRingFrame = testRing.getFrameRect();
  std::cout << "Area - " << testRing.getArea() << '\n';

  testRing.move({ 5.0, 2.0 });
  testRingFrame = testRing.getFrameRect();
  std::cout << "New center in { " << testRingFrame.pos.x << ", " << testRingFrame.pos.y << " }\n";

  testRing.move(4, -3);
  testRingFrame = testRing.getFrameRect();
  std::cout << "New center in { " << testRingFrame.pos.x << ", " << testRingFrame.pos.y << " }\n";

  testRing.scale(4.0);
  std::cout << "New area - " << testRing.getArea() << '\n';

  psarev::Triangle testTrian({ 0.0, 0.0 }, { 1.0, 1.0 }, { 0.0, 1.0 });
  rectangle_t testTrianFrame = testTrian.getFrameRect();
  std::cout << "Area - " << testTrian.getArea() << '\n';

  testTrian.move({ 5.0, 2.0 });
  testTrianFrame = testTrian.getFrameRect();
  std::cout << "New center in { " << testTrianFrame.pos.x << ", " << testTrianFrame.pos.y << " }\n";

  testTrian.move(4, -3);
  testTrianFrame = testTrian.getFrameRect();
  std::cout << "New center in { " << testTrianFrame.pos.x << ", " << testTrianFrame.pos.y << " }\n";

  testTrian.scale(4.0);
  std::cout << "New area - " << testTrian.getArea() << '\n';
}
