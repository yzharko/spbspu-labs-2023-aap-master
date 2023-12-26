#include "compositeShape.h"

#include "iostream"
#include "shape.h"

CompositeShape::CompositeShape()
{
  size_t shapes = 0;
  size_t capacity = 1;
  Shape **shapeptrs = new Shape *[capacity];
}

CompositeShape::CompositeShape(const CompositeShape &another)
{
  shapes = another.shapes;
  capacity = another.capacity;
  shapeptrs = new Shape *[capacity];
  for (int i = 0; i < shapes; ++i) {
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
  for (int i = 0; i < shapes; ++i) {
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

Shape* CompositeShape::pop(size_t n)
{
  if (n == -1) {
    Shape *shape = shapeptrs[shapes];
    shapeptrs[shapes--] = nullptr;
    return shape;
  }
  Shape *shape = shapeptrs[n];
  shapeptrs[n] = nullptr;
  for (int i = n; i < --shapes; ++i) {
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
  for (int i = 0; i < shapes; ++i) {
    new_shapeptrs[i] = shapeptrs[i];
  }
  delete[] shapeptrs;
  shapeptrs = new Shape *[new_capacity];
  for (int i = 0; i < shapes; ++i) {
    shapeptrs[i] = new_shapeptrs[i];
  }
  capacity = new_capacity;
}

long long CompositeShape::getArea()
{
  long long sum = 0;
  for (int i = 0; i < shapes; ++i) {
    sum += shapeptrs[i]->getArea();
  }
  return sum;
}

RectangleT *CompositeShape::getFrameRect()
{
  RectangleT *recs = new RectangleT[shapes];
  for (int i = 0; i < shapes; ++i) {
    recs[i] = shapeptrs[i]->getFrameRect();
  }
  return recs;
}

void CompositeShape::move(PointT point)
{
  for (int i = 0; i < shapes; ++i) {
    shapeptrs[i]->move(point);
  }
}

void CompositeShape::move(double x, double y)
{
  PointT point(x, y);
  move(point);
}

void CompositeShape::scale(std::istream &in, std::ostream &out)
{
  out << getArea();
  RectangleT *points = getFrameRect();
  for (int i = 0; i < shapes; ++i) {
    out << " " << points[i];
  }
  out << "\n";
  delete[] points;
  double k;
  for (int i = 0; i < shapes; ++i) {
    if(!(in >> k) || k < 0){
      throw std::runtime_error("Invalid Input");
    }
    shapeptrs[i]->scale(k);
  }
  out << getArea();
  points = getFrameRect();
  for (int i = 0; i < shapes; ++i) {
    out << " " << points[i];
  }
  out << "\n";
  delete[] points;
}
