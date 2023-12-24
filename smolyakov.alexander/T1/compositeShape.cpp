#include "compositeShape.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include <cstddef>
#include <stdexcept>

smolyakov::CompositeShape::CompositeShape(size_t defaultCapacity)
  : capacity(defaultCapacity), shapes(0)
{
  shapeptrs = new Shape*[capacity];
}

smolyakov::CompositeShape::CompositeShape(const CompositeShape& source)
  : capacity(source.capacity), shapes(source.shapes)
{
  shapeptrs = new Shape*[capacity];
  for (std::size_t i = 0; i < shapes; i++)
  {
    shapeptrs[i] = source.shapeptrs[i];
  }
}

smolyakov::CompositeShape::CompositeShape(CompositeShape&& source)
  : capacity(source.capacity), shapes(source.shapes), shapeptrs(source.shapeptrs)
{
  source.capacity = 0;
  source.shapes = 0;
  source.shapeptrs = nullptr;
}

smolyakov::CompositeShape::~CompositeShape()
{
  delete[] shapeptrs;
}

void smolyakov::CompositeShape::addShape(Shape& shape)
{
  if (++shapes >= capacity)
  {
    shapes--;
    throw std::logic_error("Maximum shapes limit is reached.");
  }
  bool flag = true;
  size_t i = 0;
  while (flag)
  {
    if (shapeptrs[i] == nullptr)
    {
      flag = false;
      shapeptrs[i] = &shape;
    }
    i++;
  }
}

void smolyakov::CompositeShape::removeShape(Shape& shape)
{
  if (--shapes < 0)
  {
    shapes++;
    throw std::logic_error("No shapes are present.");
  }
  bool flag = true;
  size_t i = 0;
  while (flag)
  {
    if (shapeptrs[i] == &shape)
    {
      flag = false;
      shapeptrs[i] = nullptr;
    }
    i++;
  }
  if (flag)
  {
    throw std::logic_error("The proveded shape could not be found.");
  }
}

double smolyakov::CompositeShape::getArea() const
{
  double area = 0;
  size_t checkedShapes = 0;
  size_t i = 0;
  while ((i < capacity) && (checkedShapes < shapes))
  {
    if (shapeptrs[i] != nullptr)
    {
      checkedShapes++;
      area += shapeptrs[i]->getArea();
    }
    i++;
  }
  return area;
}

smolyakov::rectangle_t smolyakov::CompositeShape::getFrameRect() const
{
  throw std::logic_error("Not implemented.");
}

void smolyakov::CompositeShape::moveBy(double x, double y)
{
  size_t checkedShapes = 0;
  size_t i = 0;
  while ((i < capacity) && (checkedShapes < shapes))
  {
    if (shapeptrs[i] != nullptr)
    {
      checkedShapes++;
      shapeptrs[i]->moveBy(x, y);
    }
    i++;
  }
}

void smolyakov::CompositeShape::scale(double factor)
{
  size_t checkedShapes = 0;
  size_t i = 0;
  while ((i < capacity) && (checkedShapes < shapes))
  {
    if (shapeptrs[i] != nullptr)
    {
	checkedShapes++;
	shapeptrs[i]->scale(factor);
    }
    i++;
  }
}
