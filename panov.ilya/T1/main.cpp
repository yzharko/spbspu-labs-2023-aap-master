#include <iostream>
#include "Circle.h"
#include "CompositeShape.h"

void ShapeInfo(Shape& s);

int main() {
  double x1 = 0.0, y1 = 0.0, r = 0.0;
  std::cout << "Enter the coordinates of the center and the radius of the circle:\n";
  std::cout << "Center: ";
  std::cin >> x1 >> y1;
  if (!std::cin) {
    std::cerr << "Incorrect input! Try again...";
    exit(-1);
  }
  std::cout << "Radius: ";
  std::cin >> r;
  if (!std::cin || r == 0) {
    std::cerr << "Incorrect input! Try again...";
    exit(-1);
  }
  Point center(x1, y1);
  Circle circle(center, r);


  ShapeInfo(circle);

  std::cout << "Scale 2:\n";
  circle.scale(2);

  ShapeInfo(circle);

  std::cout << "\n" << "move circle:\n";

  circle.move(1, 1);
  ShapeInfo(circle);

  int m = 0;
  std::cin >> m;
  CompositeShape shapes(m);
  Point c(2, 3);
  Point c1(1, 1);
  Point c2(2, 0);

  double a = 8.0, b = 3.0, d = 4.0;

  Shape* circle_d2 = new Circle(c2, 7);
  Shape* circle_d2Clone = circle_d2->clone();
  Shape* circle_d = new Circle(c, 5);

  shapes.addShape(circle_d);
  shapes.addShape(circle_d2Clone);

  ShapeInfo(shapes);

  std::cout << "\n";

  std::cout << "Array of shapes used in composition:\n";
  for (int i = 0; i < 3; i++) {
    ShapeInfo(*shapes[i]);
  }

  std::cout << "\n";

  std::cout << "Array of shapes used in composition with movement (1, 1):\n";

  circle_d->move(1, 1);
  circle_d2Clone->move(1, 1);

  for (int i = 0; i < 3; i++) {
    ShapeInfo(*shapes[i]);
  }

  std::cout << "\n";

  double n = 0.0;
  std::cin >> n;
  std::cout << "Array of shapes used in composition with scale " << n << ":\n";

  shapes.scale(n);

  ShapeInfo(shapes);
  for (int i = 0; i < 3; i++) {
    ShapeInfo(*shapes[i]);
  }

  return 0;
}

void ShapeInfo(Shape& s) {
  FrameRectangle frameRect = s.getFrameRectangle();
  double area = s.getArea();
  double x1 = frameRect.getPos().getX();
  double y1 = frameRect.getPos().getY();

  std::cout << s.getName() << " ";
  std::cout << std::fixed;
  std::cout.precision(1);
  std::cout << area << " ";
}