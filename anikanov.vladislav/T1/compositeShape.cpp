#include "compositeShape.hpp"

#include <iostream>
#include <iomanip>
#include "shape.hpp"

using namespace anikanov;

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
  for (size_t i = 0; i < shapes; ++i) {
    delete shapeptrs[i];
  }
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

float CompositeShape::getArea()
{
  float sum = 0;
  for (size_t i = 0; i < shapes; ++i) {
    sum += shapeptrs[i]->getArea();
  }
  return sum;
}

rectangle_t *CompositeShape::getFrameRect()
{
  rectangle_t *recs = new rectangle_t[shapes];
  for (size_t i = 0; i < shapes; ++i) {
    recs[i] = shapeptrs[i]->getFrameRect();
  }
  return recs;
}

void CompositeShape::move(point_t point)
{
  for (size_t i = 0; i < shapes; ++i) {
    shapeptrs[i]->move(point);
  }
}

void CompositeShape::move(float x, float y)
{
  point_t point(x, y);
  move(point);
}

void CompositeShape::scale(std::ostream &out, point_t center, float k)
{
  if (k < 0) {
    throw std::logic_error("Invalid coeff scale");
  }
  if (shapes == 0){
    throw std::logic_error("No correct figures");
  }
  out << std::fixed << std::setprecision(1);
  out << getArea();
  rectangle_t *points = getFrameRect();
  for (size_t i = 0; i < shapes; ++i) {
    out << " " << points[i];
  }
  out << "\n";
  delete[] points;
  for (size_t i = 0; i < shapes; ++i) {
    shapeptrs[i]->scale(k, center);
  }
  out << getArea();
  points = getFrameRect();
  for (size_t i = 0; i < shapes; ++i) {
    out << " " << points[i];
  }
  out << "\n";
  delete[] points;
}

float CompositeShape::getDX(point_t fp, point_t sp)
{
  return fp.x - sp.x;
}

float CompositeShape::getDY(point_t fp, point_t sp)
{
  return fp.y - sp.y;
}
