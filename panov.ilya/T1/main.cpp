#include <iostream>
#include "Circle.h"
#include "Diamond.h"
#include "Shape.h"

void ShapeInfo(Shape& s);
int main() {
  double x1 = 0.0, y1 = 0.0, r = 0.0;
  double t1 = 0.0, t2 = 0.0, t3 = 0.0, t4 = 0.0;
  std::cout << "Enter the coords for rectangle:\n";
  std::cout << "Center coords: ";
  std::cin >> t1 >> t2;
  if (!std::cin) {
    std::cerr << "Incorrect input!Try again…";
    exit(-1);
  }
  std::cout << "width and height:";
  std::cin >> t3 >> t4;
  std::cout << "Enter the coordinates of the center and the radius of the circle : \n";
  std::cout << "Center: ";
  std::cin >> x1 >> y1;
  if (!std::cin) {
    std::cerr << "Incorrect input!Try again…";
    exit(-1);
  }
  std::cout << "Radius: ";
  std::cin >> r;
  if (!std::cin || r == 0) {
    std::cerr << "Incorrect input!Try again…";
    exit(-1);
  }
  Point center(x1, y1);
  Circle circle(center, r);
  double x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0, x4 = 0.0, y4 = 0.0;
  std::cout << "Enter the coords for diagonal interception of diamond, diagonals:\n";
  std::cout << "Coords: ";
  std::cin >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  if (!std::cin) {
    std::cerr << "Incorrect input!Try again…";
    exit(-1);
  }
  Point center2(t1, t2);
  Point pos1(x2, y2);
  Point pos2(x3, y3);
  Point pos3(x4, y4);
  Diamond diamond(pos1, pos2, pos3);
  FrameRectangle framerectangle(center2, t3, t4);
  circle.getName();
  diamond.getName();
  framerectangle.show();
  circle.show();
  diamond.show();
  std::cout << "Scale 2\n";
  framerectangle.scale(2);
  circle.scale(2);
  diamond.scale(2);
  framerectangle.show();
  circle.show();
  diamond.show();
  std::cout << "\n" << "move rectangle  \n";
  framerectangle.move(1, 1);
  framerectangle.show();
  std::cout << "\n" << "move circle \n";
  circle.move(1, 1);
  circle.show();
  std::cout << "\n" << "move diamond  \n";
  diamond.move(1, 1);
  diamond.show();
  return 0;
}
void ShapeInfo(Shape& s) {
  FrameRectangle frameRect = s.getFrameRectangle();
  double area = s.getArea();
  double x1 = frameRect.getLeftCorner().getX();
  double y1 = frameRect.getLeftCorner().getY();
  double x2 = frameRect.getRightCorner().getX();
  double y2 = frameRect.getRightCorner().getY();
  std::cout << s.getName() << " ";
  std::cout << std::fixed;
  std::cout.precision(1);
  std::cout << area << " ";
  std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
}
