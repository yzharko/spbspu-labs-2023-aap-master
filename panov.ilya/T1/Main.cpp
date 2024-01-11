#include <iostream>
#include "Circle.h"
#include "Diamond.h"
#include "Shape.h"

void ShapeInfo(Shape& s);
int main() {
  double x1 = 0.0, y1 = 0.0, r = 0.0;
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
  double x2 = 0.0, y2 = 0.0, d1 = 0, d2 = 0;
  std::cout << "Enter the coords for diagonal interception of diamond, diagonals:\n";
  std::cout << "Coords: ";
  std::cin >> x2 >> y2;
  if (!std::cin) {
    std::cerr << "Incorrect input!Try again…";
    exit(-1);
  }
  std::cout << "Diagonal 1: ";
  std::cin >> d1;
  if (!std::cin || d1 <= 0) {
    std::cerr << "Incorrect input!Try again…";
    exit(-1);
  }
  std::cout << "Diagonal 2: ";
  std::cin >> d2;
  if (!std::cin || d2 == 0) {
    std::cerr << "Incorrect input!Try again…";
    exit(-1);
  }
  Point pos(x2, y2);
  Diamond diamond(pos, d1, d2);
  circle.getName();
  diamond.getName();
  ShapeInfo(circle);
  ShapeInfo(diamond);
  std::cout << "Scale 2\n";
  circle.scale(2);
  diamond.scale(2);
  ShapeInfo(circle);
  ShapeInfo(diamond);
  std::cout << "\n" << "move circle \n";
  circle.move(1, 1);
  ShapeInfo(circle);
  ShapeInfo(diamond);
  std::cout << "\n" << "move diamond  \n";
  diamond.move(1, 1);
  ShapeInfo(circle);
  ShapeInfo(diamond);
  std::cout << "\n";
  std::cout << "Clone of shape  \n";
  Shape* c_rho = diamond.clone();
  ShapeInfo(circle);
  ShapeInfo(diamond);
  std::cout << "\n";
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