#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "polygon.hpp"

int main()
{
  Rectangle rectangle({3.0, 2.0}, {7.0, 5.0});
  std::cout << rectangle.getArea() << "\n";
  rectangle_t frameRectangle = rectangle.getFrameRect();
  std::cout << frameRectangle.width << " " << frameRectangle.height << " ";
  std::cout << frameRectangle.pos.x << " " << frameRectangle.pos.y << "\n";
  rectangle.move({0.0, 0.0});
  rectangle.move(1.0, -1.0);
  rectangle.scale(3.5);

  Triangle triangle({3.0, 2.0}, {5.0, 7.0}, {8.0, 5.0});
  std::cout << triangle.getArea() << "\n";
  rectangle_t frameTriangle = triangle.getFrameRect();
  std::cout << frameTriangle.width << " " << frameTriangle.height << " ";
  std::cout << frameTriangle.pos.x << " " << frameTriangle.pos.y << "\n";
  triangle.move({0.0, 0.0});
  triangle.move(1.0, -1.0);
  triangle.scale(3.5);

  int num = 5;
  std::cin >> num;
  point_t points[num] = {};
  points[0] = {5.0, 9.0};
  points[1] = {12.0, 5.0};
  points[2] = {8.0, 2.0};
  points[3] = {4.0, 3.0};
  points[4] = {3.0, 6.0};
  Polygon polygon(num, points);
  std::cout << polygon.getArea() << "\n";
  rectangle_t framePolygon = polygon.getFrameRect();
  std::cout << framePolygon.width << " " << framePolygon.height << " ";
  std::cout << framePolygon.pos.x << " " << framePolygon.pos.y << "\n";
  polygon.move({0.0, 0.0});
  polygon.move(1.0, -1.0);
  polygon.scale(3.5);

}
