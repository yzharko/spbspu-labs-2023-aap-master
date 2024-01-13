#include<iostream>
#include"BaseTypes.hpp"
#include "Rectangle.hpp"
#include"Square.hpp"
#include "Ring.hpp"
int main()
{
  Rectangle test1(2, 2, base_types::point_t{ 0,0 });
  std::cout << test1.getArea() << " ";
  rectangle_t frameRect1 = test1.getFrameRect();
  std::cout << frameRect1.width << " " << frameRect1.height << " " << frameRect1.pos.x << " " << frameRect1.pos.y;
  test1.move({ -5, 11 });
  test1.move(1, 1);
  test1.scale(10);
  std::cout << "\n";
  Ring test2(2, 3, 17, 16);
  std::cout << test2.getArea() << " ";
  rectangle_t frameRect2 = test2.getFrameRect();
  std::cout << frameRect2.width << " " << frameRect2.height << " " << frameRect2.pos.x << " " << frameRect2.pos.y;
  test2.move({ -3, 14 });
  test2.move(3, 3);
  test2.scale(2);
  std::cout << "\n";
  Square test3(6, 9, 3);
  std::cout << test3.getArea() << " ";
  rectangle_t frameRect3 = test3.getFrameRect();
  std::cout << frameRect3.width << " " << frameRect3.height << " " << frameRect3.pos.x << " " << frameRect3.pos.y;
  test3.move({ -2, 4 });
  test3.move(6, 6);
  test3.scale(5);
  std::cout << "\n";
  return 0;
}