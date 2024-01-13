#include "compositeShape.hpp"
#include <algorithm>
#include <cstddef>
#include <limits>
#include <stdexcept>
#include "base-types.hpp"
#include "shape.hpp"

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

  size_t insertAt = 0;
  while (shapeptrs[insertAt] != nullptr)
  {
    insertAt++;
  }
  shapeptrs[insertAt] = &shape;
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
      for (size_t j = ++i; j < capacity; j++)
      {
	shapeptrs[j-1] = shapeptrs[j];
      }
    }
    i++;
  }
  if (flag)
  {
    throw std::logic_error("The provided shape could not be found.");
  }
}

double smolyakov::CompositeShape::getArea() const
{
  double area = 0;
  for (size_t i = 0; (i < capacity) || (shapeptrs[i] != nullptr); i++)
  {
    area += shapeptrs[i]->getArea();
  }
  return area;
}

smolyakov::rectangle_t smolyakov::CompositeShape::getFrameRect() const
{
  double maxValue = std::numeric_limits<double>().max();
  double minValue = std::numeric_limits<double>().min();
  point_t min = {maxValue, maxValue};
  point_t max = {minValue, minValue}; 
  for (size_t i = 0; (i < capacity) || (shapeptrs[i] != nullptr); i++)
  {
    rectangle_t shapeFrame = shapeptrs[i]->getFrameRect();
    min.x = std::min(min.x, shapeFrame.pos.x - shapeFrame.width / 2.0);
    min.y = std::min(min.y, shapeFrame.pos.y - shapeFrame.height / 2.0);
    max.x = std::max(max.x, shapeFrame.pos.x - shapeFrame.width / 2.0);
    max.y = std::max(max.y, shapeFrame.pos.y - shapeFrame.height / 2.0);
  }
  point_t pos = {(max.x - min.x) / 2.0, (max.y - min.y) / 2.0};
  return rectangle_t{pos, max.x - min.x, max.y - min.y};
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
      shapeptrs[i]->moveBy(point_t{x, y});
    }
    i++;
  }
}

void smolyakov::CompositeShape::scale(point_t pivot, double factor)
{
  for (size_t i = 0; (i < capacity) || (shapeptrs[i] != nullptr); i++)
  {
    shapeptrs[i]->scale(factor);
    point_t scaleCenter = shapeptrs[i]->getScaleCenter();
    point_t delta = {scaleCenter.x - pivot.x, scaleCenter.y - pivot.y};
    delta.x *= factor;
    delta.y *= factor;
    shapeptrs[i]->moveBy(delta);
  }
}
