#include "shape.hpp"
#include "rectangle.hpp"
#include "Diamond.hpp"
#include <iostream>

int main()
{
  Rectangle rectangle({1.0, 4.0}, {9.0, 4.0});
  std::cout << rectangle.getArea() << "\n";
//  rectangle_t frameRectangle = rectangle.getFrameRect();
  rectangle.move({0.0, 0.0});
  rectangle.move(1.0, -1.0);
  rectangle.scale(3.5);

//  int num = 5;
//  points[0] = {5.0, 9.0};
//  points[1] = {12.0, 5.0};
//  points[2] = {8.0, 2.0};
//  points[3] = {4.0, 3.0};
//  points[4] = {3.0, 6.0};

}
