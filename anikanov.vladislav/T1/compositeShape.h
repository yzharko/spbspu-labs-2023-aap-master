#ifndef COMPOSITESHAPE_H
#define COMPOSITESHAPE_H
#include <iosfwd>
#include "shape.h"

class CompositeShape {
public:
  CompositeShape();

  CompositeShape(const CompositeShape &);

  ~CompositeShape();

  CompositeShape &operator=(CompositeShape another_cs);

  void add(Shape*);

  Shape* pop(size_t n = -1);

  void resize(size_t n = 0);

  long long getArea();

  RectangleT* getFrameRect();

  void move(PointT);

  void move(double x, double y);

  void scale(std::istream &, std::ostream &);

private:
  size_t shapes;
  size_t capacity;
  Shape **shapeptrs;
};

#endif
