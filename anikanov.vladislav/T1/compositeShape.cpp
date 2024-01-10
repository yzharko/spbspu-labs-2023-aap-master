#include "compositeShape.h"

#include "iostream"
#include "shape.h"

CompositeShape::CompositeShape()
{
  shapes = 0;
  capacity = 1;
  shapeptrs = new Shape *[capacity];
}

CompositeShape::CompositeShape(const CompositeShape &another)
{
  shapes = another.shapes;
  capacity = another.capacity;
  shapeptrs = new Shape *[capacity];
  for (size_t i = 0; i < shapes; ++i) {
    shapeptrs[i] = another.shapeptrs[i];
  }
}

CompositeShape::~CompositeShape()
{
  delete[] shapeptrs;
}

CompositeShape &CompositeShape::operator=(const CompositeShape another)
{
  if (this == &another) {
    return *this;
  }
  shapes = another.shapes;
  capacity = another.capacity;
  delete[] shapeptrs;
  shapeptrs = new Shape *[capacity];
  for (size_t i = 0; i < shapes; ++i) {
    shapeptrs[i] = another.shapeptrs[i];
  }
  return *this;
}

void CompositeShape::add(Shape *shape)
{
  if (capacity == shapes) {
    resize();
  }
  shapeptrs[shapes++] = shape;
}

Shape *CompositeShape::pop(long long n)
{
  if (n == -1) {
    Shape *shape = shapeptrs[shapes];
    shapeptrs[shapes--] = nullptr;
    return shape;
  }
  Shape *shape = shapeptrs[n];
  shapeptrs[n] = nullptr;
  for (size_t i = n; i < --shapes; ++i) {
    shapeptrs[i] = shapeptrs[i + 1];
    shapeptrs[i + 1] = nullptr;
  }
  return shape;
}

void CompositeShape::resize(size_t n)
{
  size_t new_capacity;
  if (n == 0) {
    new_capacity = capacity * 2;
  } else if (n <= capacity) {
    return;
  } else {
    new_capacity = n;
  }
  Shape *new_shapeptrs[new_capacity];
  for (size_t i = 0; i < shapes; ++i) {
    new_shapeptrs[i] = shapeptrs[i];
  }
  delete[] shapeptrs;
  shapeptrs = new Shape *[new_capacity];
  for (size_t i = 0; i < shapes; ++i) {
    shapeptrs[i] = new_shapeptrs[i];
  }
  capacity = new_capacity;
}

long long CompositeShape::getArea()
{
  long long sum = 0;
  for (size_t i = 0; i < shapes; ++i) {
    sum += shapeptrs[i]->getArea();
  }
  return sum;
}

RectangleT *CompositeShape::getFrameRect()
{
  RectangleT *recs = new RectangleT[shapes];
  for (size_t i = 0; i < shapes; ++i) {
    recs[i] = shapeptrs[i]->getFrameRect();
  }
  return recs;
}

void CompositeShape::move(PointT point)
{
  for (size_t i = 0; i < shapes; ++i) {
    shapeptrs[i]->move(point);
  }
}

void CompositeShape::move(double x, double y)
{
  PointT point(x, y);
  move(point);
}

void CompositeShape::scale(std::ostream &out, PointT center, unsigned int k)
{
  out << getArea();
  RectangleT *points = getFrameRect();
  for (size_t i = 0; i < shapes; ++i) {
    out << " " << points[i];
  }
  out << "\n";
  delete[] points;
  PointT pos;
  for (size_t i = 0; i < shapes; ++i) {
    shapeptrs[i]->scale(k);
    pos = shapeptrs[i]->getCPoint();
    double dx = getDX(pos, center) * (k - 1);
    double dy = getDY(pos, center) * (k - 1);
    shapeptrs[i]->move(pos + PointT(dx, dy));
  }
  out << getArea();
  points = getFrameRect();
  for (size_t i = 0; i < shapes; ++i) {
    out << " " << points[i];
  }
  out << "\n";
  delete[] points;
}

double CompositeShape::getDX(PointT fp, PointT sp)
{
  return fp.x - sp.x;
}

double CompositeShape::getDY(PointT fp, PointT sp)
{
  return fp.y - sp.y;
}
