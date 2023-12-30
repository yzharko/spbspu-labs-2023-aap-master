#include "composite-shape.hpp"
#include <algorithm>
#include <stdexcept>

CompositeShape::CompositeShape() :
    shapeptrs_(nullptr), shapes_(0), capacity_(0)
{
}

CompositeShape* CompositeShape::clone() const
{
  CompositeShape* newComposite = new CompositeShape();
  for (size_t i = 0; i < this->shapes_; ++i)
  {
    newComposite->addShape(this->shapeptrs_[i]->clone());
  }
  return newComposite;
}

CompositeShape::CompositeShape(const CompositeShape& other) :
    shapeptrs_(new Shape* [other.capacity_]), shapes_(other.shapes_), capacity_(other.capacity_)
{
  for (size_t i = 0; i < shapes_; ++i)
  {
    shapeptrs_[i] = other.shapeptrs_[i]->clone();
  }
}

CompositeShape::CompositeShape(CompositeShape&& other) noexcept:
    shapeptrs_(std::move(other.shapeptrs_)), shapes_(other.shapes_), capacity_(other.capacity_)
{
  other.shapes_ = 0;
  other.capacity_ = 0;
}

CompositeShape& CompositeShape::operator=(const CompositeShape& other)
{
  if (this != &other)
  {
    std::unique_ptr<Shape* []> newShapes(new Shape* [other.capacity_]);
    for (size_t i = 0; i < other.shapes_; ++i)
    {
      newShapes[i] = other.shapeptrs_[i]->clone();
    }
    shapes_ = other.shapes_;
    capacity_ = other.capacity_;
    shapeptrs_ = std::move(newShapes);
  }
  return *this;
}

CompositeShape& CompositeShape::operator=(CompositeShape&& other) noexcept
{
  if (this != &other)
  {
    shapeptrs_ = std::move(other.shapeptrs_);
    shapes_ = other.shapes_;
    capacity_ = other.capacity_;
    other.shapes_ = 0;
    other.capacity_ = 0;
  }
  return *this;
}

CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < shapes_; ++i)
  {
    delete shapeptrs_[i];
  }
}

void CompositeShape::addShape(Shape* shape)
{
  if (shapes_ >= capacity_)
  {
    expandCapacity();
  }
  shapeptrs_[shapes_++] = shape;
}

void CompositeShape::removeShape(size_t index)
{
  if (index >= shapes_)
  {
    throw std::out_of_range("Index is out of range");
  }
  delete shapeptrs_[index];
  for (size_t i = index; i < shapes_ - 1; ++i)
  {
    shapeptrs_[i] = shapeptrs_[i + 1];
  }
  shapeptrs_[shapes_ - 1] = nullptr;
  --shapes_;
}

size_t CompositeShape::getShapesCount() const
{
  return shapes_;
}

float CompositeShape::getArea() const
{
  float totalArea = 0.0;
  for (size_t i = 0; i < shapes_; ++i)
  {
    totalArea += shapeptrs_[i]->getArea();
  }
  return totalArea;
}

rectangle_t CompositeShape::getFrameRect() const
{
  if (shapes_ == 0)
  {
    return { 0, 0, { 0, 0 }};
  }
  rectangle_t frame = shapeptrs_[0]->getFrameRect();
  float minX = frame.pos.x - frame.width / 2;
  float maxX = frame.pos.x + frame.width / 2;
  float minY = frame.pos.y - frame.height / 2;
  float maxY = frame.pos.y + frame.height / 2;

  for (size_t i = 1; i < shapes_; ++i)
  {
    frame = shapeptrs_[i]->getFrameRect();
    minX = std::min(minX, frame.pos.x - frame.width / 2);
    maxX = std::max(maxX, frame.pos.x + frame.width / 2);
    minY = std::min(minY, frame.pos.y - frame.height / 2);
    maxY = std::max(maxY, frame.pos.y + frame.height / 2);
  }

  return { maxX - minX, maxY - minY, { (minX + maxX) / 2, (minY + maxY) / 2 }};
}

void CompositeShape::move(const point_t& newPos)
{
  point_t center = getFrameRect().pos;
  move(newPos.x - center.x, newPos.y - center.y);
}

void CompositeShape::move(float dx, float dy)
{
  for (size_t i = 0; i < shapes_; ++i)
  {
    shapeptrs_[i]->move(dx, dy);
  }
}

void CompositeShape::scale(float scaleFactor)
{
  point_t center = getFrameRect().pos;
  for (size_t i = 0; i < shapes_; ++i)
  {
    point_t shapeCenter = shapeptrs_[i]->getFrameRect().pos;
    shapeptrs_[i]->move((shapeCenter.x - center.x) * (scaleFactor - 1),
        (shapeCenter.y - center.y) * (scaleFactor - 1));
    shapeptrs_[i]->scale(scaleFactor);
  }
}

void CompositeShape::expandCapacity()
{
  size_t newCapacity = (capacity_ > 0) ? 2 * capacity_ : 1;
  std::unique_ptr<Shape* []> newShapes(new Shape* [newCapacity]);
  for (size_t i = 0; i < shapes_; ++i)
  {
    newShapes[i] = shapeptrs_[i];
  }
  shapeptrs_ = std::move(newShapes);
  capacity_ = newCapacity;
}
