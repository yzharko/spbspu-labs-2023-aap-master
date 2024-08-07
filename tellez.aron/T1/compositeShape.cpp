#include "compositeShape.hpp"
#include <limits>
#include <stdexcept>
#include "isoscale.hpp"

using namespace tellez;

CompositeShape::~CompositeShape()
{
  freeMemory(shapes, size_);
}

CompositeShape::CompositeShape(size_t capacity):
  shapes(new Shape * [capacity]),
  capacity_(capacity),
  size_(0)
{}

size_t CompositeShape::size() const
{
  return size_;
}

bool CompositeShape::empty() const
{
  return size_ == 0;
}

void CompositeShape::scale(scale_t scale)
{
  if (scale.ds > 0)
  {
    scaleWithoutVerify(scale);
  }
  else
  {
    throw std::logic_error("bad scale size");
  }
}

void CompositeShape::scaleWithVerify(scale_t scale)
{
  for (size_t i = 0; i < size_; i++)
  {
    isoScaleWithVerify(shapes[i], scale);
  }
}

void CompositeShape::scaleWithoutVerify(scale_t scale)
{
  for (size_t i = 0; i < size_; i++)
  {
    isoScaleWithoutVerify(shapes[i], scale);
  }
}

void CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes[i]->move(dx, dy);
  }
}

void CompositeShape::move(point_t position)
{
  move(position.x - getFrameRect().pos.x, position.y - getFrameRect().pos.y);
}

double CompositeShape::getArea() const
{
  double sum = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    sum = sum + shapes[i]->getArea();
  }
  return sum;
}

rectangle_t CompositeShape::getFrameRect() const
{
  double A = std::numeric_limits< double >::min();
  double B = std::numeric_limits< double >::min();
  double C = std::numeric_limits< double >::max();
  double D = std::numeric_limits< double >::max();
  if (size_ == 0)
  {
    throw std::logic_error("no shapes");
  }
  for (size_t i = 0; i < size_; i++)
  {
    rectangle_t buffer = shapes[i]->getFrameRect();
    A = (A > buffer.pos.x + buffer.width / 2.0) ? A : buffer.pos.x + buffer.width / 2.0;
    B = (B > buffer.pos.y + buffer.height / 2.0) ? B : buffer.pos.y + buffer.height / 2.0;
    C = (C < buffer.pos.x - buffer.width / 2.0) ? C : buffer.pos.x - buffer.width / 2.0;
    D = (D < buffer.pos.y - buffer.height / 2.0) ? D : buffer.pos.y - buffer.height / 2.0;
  }
  return {{(A + C) / 2.0, (B + D) / 2.0}, C - A, D - B};
}

void CompositeShape::push_back(const Shape * shp)
{
  Shape * clone = nullptr;
  try
  {
    clone = shp->clone();
  }
  catch (...)
  {
    delete clone;
    throw;
  }
  push_back(clone);
}

void CompositeShape::push_back(Shape * shp)
{
  if (capacity_ == size_)
  {
    Shape ** extendShapes = new Shape * [capacity_ + 10];
    capacity_ = capacity_ + 10;
    for (size_t i = 0; i < size_; i++)
    {
      extendShapes[i] = shapes[i];
    }
    delete [] shapes;
    shapes = extendShapes;
  }
  shapes[size_++] = shp;
}

void CompositeShape::pop_back()
{
  delete shapes[--size_];
}

Shape * CompositeShape::at(size_t id)
{
  if (id >= size_)
  {
    throw std::invalid_argument("incorrect argument");
  }
  return shapes[id];
}

Shape * CompositeShape::operator[](size_t id)
{
  return shapes[id];
}

const Shape * CompositeShape::at(size_t id) const
{
  if (id >= size_)
  {
    throw std::invalid_argument("incorrect argument");
  }
  return shapes[id];
}

const Shape * CompositeShape::operator[](size_t id) const
{
  return shapes[id];
}

CompositeShape * CompositeShape::clone() const
{
  Shape ** cloneShapes = new Shape * [capacity_];
  for (size_t i = 0; i < size_; i++)
  {
    try
    {
      cloneShapes[i] = shapes[i]->clone();
    }
    catch (...)
    {
      freeMemory(cloneShapes, size_);
      throw;
    }
  }
  return new CompositeShape(cloneShapes, capacity_, size_);
}

CompositeShape::CompositeShape(const CompositeShape & compositeShape):
  shapes(new Shape * [compositeShape.capacity_]),
  capacity_(compositeShape.capacity_),
  size_(compositeShape.size_)
{
  for (size_t i = 0; i < size_; i++)
  {
    try
    {
      shapes[i] = compositeShape.shapes[i]->clone();
    }
    catch (...)
    {
      freeMemory(shapes, size_);
      throw;
    }
  }
}

CompositeShape::CompositeShape(Shape ** shapes, size_t capacity, size_t size):
  shapes(shapes),
  capacity_(capacity),
  size_(size)
{}

void CompositeShape::freeMemory(Shape ** shp, size_t size) const
{
  for (size_t i = 0; i < size; i++)
  {
    delete shp[i];
  }
  delete [] shp;
}

CompositeShape & CompositeShape::operator=(const CompositeShape & compositeShape)
{
  Shape ** cloneShapes = new Shape * [compositeShape.capacity_];
  for (size_t i = 0; i < compositeShape.size_; i++)
  {
    try
    {
      cloneShapes[i] = compositeShape[i]->clone();
    }
    catch (...)
    {
      freeMemory(cloneShapes, compositeShape.size_);
      throw;
    }
  }
  freeMemory(shapes, size_);
  shapes = cloneShapes;
  size_ = compositeShape.size_;
  capacity_ = compositeShape.capacity_;
  return * this;
}

CompositeShape & CompositeShape::operator=(CompositeShape && compositeShape) noexcept
{
  freeMemory(shapes, size_);
  size_ = compositeShape.size_;
  capacity_ = compositeShape.capacity_;
  shapes = compositeShape.shapes;
  compositeShape.shapes = nullptr;
  compositeShape.size_ = 0;
  return * this;
}

