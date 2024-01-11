#include <iostream>
#include <iomanip>
#include "Shape.h"
#include "Point.h"
#include "Circle.h"

int main()
{
  Circle ring1;
  std::cout << "Degenerate ring ring1:\n";
  std::cout << ring1.getCenter().getX() << ' ' << ring1.getCenter().getY() << '\n';
  std::cout << "Ring1 radii:\n";
  std::cout << ring1.getRadBig() << ' ' << ring1.getRadSmall() << '\n';
  Point cntr2(2, -5);
  Ring ring2(cntr2, 4, 2);
  std::cout << "\nRing2 Center (x, y):\n";
  std::cout << ring2.getCenter().getX() << ' ' << ring2.getCenter().getY() << '\n';
  std::cout << "Ring2 radii:\n";
  std::cout << ring2.getRadBig() << ' ' << ring2.getRadSmall() << '\n';
  std::cout << "Ring2 square:\n";
  double area2 = ring2.getArea();
  std::cout << area2 << '\n';
  FrameRectangle rect = ring2.getFrameRectangle();
  std::cout << "ring2 is shifted by 2 in x and -1 in y:\n";
  ring2.move(2, -1);
  std::cout << ring2.getCenter().getX() << ' ' << ring2.getCenter().getY() << '\n';
  std::cout << "Ring2 radii:\n";
  std::cout << ring2.getRadBig() << ' ' << ring2.getRadSmall() << '\n';
  std::cout << "\nInformation about ring2 (name, area, left corner coordinate, right corner coordinate):\n";
  FigInfo<Ring>(ring2);
  std::cout << '\n';
  std::cout << "ring2 has been increased 3 times:\n";
  ring2.scale(3);
  FigInfo<Ring>(ring2);
  std::cout << "\n";
  Shape* ringShape = ring2.clone();
  Point a(0, 5), b(0, 0), c(10, -1), d(1, 1);
  std::cout << "\nInformation about the degenerate concave1:\n";
  Concave concave1;
  FigInfo<Concave>(concave1);
  Concave concave2(a, b, c, d);
  std::cout << "\nInformation about concave2 (a(0, 5), b(0, 0), c(10, -1), d(1, 1)):\n";
  FigInfo<Concave>(concave2);
  concave2.move(3, 3);
  concave2.scale(3);
  std::cout << "\nconcave2 shifted by 3 in x and y, increased by 3 times:\n";
  FigInfo<Concave>(concave2);
  std::cout << "\n";
  Shape* concaveShape = concave2.clone();
  CompositeShape compShape(3);
  compShape.addShape(ring2);
  compShape.addShape(concave2);
  Point a1(0, 0), b1(0, 0), c1(0, 0), d1(0, 0);
  Concave concave3(a1, b1, c1, d1);
  compShape.addShape(concave3);
  std::cout << "\ncompShape composite shape elements (ring2 and concave2)\n";
  compShape.listShapes();
  std::cout << "The compShape elements are offset by 2 in x and y:\n";
  compShape.move(2, 2);
  compShape.listShapes();
  std::cout << "compShape elements are reduced by 2 times (scale 0.5):\n";
  compShape.scale(0.5);
  compShape.listShapes();
  delete ringShape;
  delete concaveShape;
}
template <typename T>
void FigInfo(T figure) {
  std::cout << figure.getName() << ' ';
  std::cout << std::fixed;
  std::cout.precision(1);
  std::cout << figure.getArea() << ' ';
  std::cout << figure.getFrameRectangle().getLeftCorner().getX() << ' ';
  std::cout << figure.getFrameRectangle().getLeftCorner().getY() << ' ';
  std::cout << figure.getFrameRectangle().getRightCorner().getX() << ' ';
  std::cout << figure.getFrameRectangle().getRightCorner().getY();
}