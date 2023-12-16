#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "complexquad.hpp"

int main()
{
  khoroshkin::Rectangle rectangle({1.0, 1.0}, {3.0, 4.0});
  std::cout << rectangle.getArea();
  rectangle_t frameRect1 = rectangle.getFrameRect();
  std::cout << frameRect1.width << " " << frameRect1.height << " " << frameRect1.pos.x << " " << frameRect1.pos.y;
  rectangle.move({2.0, 2.0});
  rectangle.move(-2, -2);
  rectangle.scale(10);
  std::cout << "\n";

  khoroshkin::Circle circle({2.0, 3.0}, 15.0);
  std::cout << circle.getArea();
  rectangle_t frameRect2 = circle.getFrameRect();
  std::cout << frameRect2.width << " " << frameRect2.height << " " << frameRect2.pos.x << " " << frameRect2.pos.y;
  circle.move({2.0, 2.0});
  circle.move(-2, -2);
  circle.scale(10);
  std::cout << "\n";

  khoroshkin::Complexquad complexquad({0.0, 0.0}, {10.0, 10.0}, {2.0, 0.0}, {3.0, 0.0});
  std::cout << complexquad.getArea();
  rectangle_t frameRect3 = complexquad.getFrameRect();
  std::cout << frameRect3.width << " " << frameRect3.height << " " << frameRect3.pos.x << " " << frameRect3.pos.y;
  complexquad.move({2.0, 2.0});
  complexquad.move(-2, -2);
  complexquad.scale(10);
  std::cout << "\n";

  return 0;
}
