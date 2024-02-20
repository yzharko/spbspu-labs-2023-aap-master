#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

namespace toksen
{
  void freeMemory(Shape** shapes, size_t size);
  void printRectangle(const Rectangle& rectangle);
  void printRegular(const Regular& regular);
  void printParallelogram(const Parallelogram& parallelogram);
  void scaleShape(Shape* shape, double scaleFactor);
  void moveShape(Shape* shape, double dx, double dy);
}
#endif
