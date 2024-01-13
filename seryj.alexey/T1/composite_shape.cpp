#include "composite_shape.hpp"
#include <exception>
#include <cmath>
#include <iostream>
using namespace seryj;
CompositeShape::CompositeShape()
{
  this->shapes_amount = 0;
  this->capacity = this->shape_vector.max_size();
}
CompositeShape::CompositeShape(std::vector<Shape*> v)
{
  shapes_amount = v.size();
  capacity = v.max_size();
  for (size_t i = 0; i < shapes_amount; i++)
  {
    shape_vector.push_back(v[i]);
  }
}
CompositeShape::CompositeShape(const CompositeShape& cs)
{
  this->shapes_amount = cs.shapes_amount;
  this->capacity = cs.capacity;
  for (size_t i = 0; i < this->shapes_amount; i++)
  {
    this->shape_vector[i] = cs.shape_vector[i];
  }
}
CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < this->shapes_amount; i++)
  {
    delete this->shape_vector[i];
  }
  this->shape_vector.clear();
}
void CompositeShape::operator+=(Shape* s)
{
  if (shapes_amount < capacity)
  {
    this->shape_vector.push_back(s);
    shapes_amount = shape_vector.size();
  }
}
void CompositeShape::operator-=(Shape* s)
{
  std::vector<Shape*>::iterator iter;
  for (size_t i = 0; i < this->shapes_amount; i++)
  {
    if (this->shape_vector[i] == s)
    {
      delete this->shape_vector[i];
      iter = this->shape_vector.begin() + i;
      break;
    }
  }
  this->shape_vector.erase(iter);
}

double CompositeShape::getArea()const
{
  double area = 0;
  for (size_t i = 0; i < this->shapes_amount; i++)
  {
    area += shape_vector[i]->getArea();
  }
  return area;
}
std::vector<rectangle_t> CompositeShape::getFrameRect()const
{
  std::vector<rectangle_t> rec_vec;
  for (size_t i = 0; i < this->shapes_amount; i++)
  {
    rec_vec.push_back(this->shape_vector[i]->getFrameRect());
  }
  return rec_vec;
}
void CompositeShape::move(std::vector<point_t> v)
{
  for (size_t i = 0; i < std::min(this->shapes_amount, v.size()); i++)
  {
    this->shape_vector[i]->move(v[i]);
  }
}
void CompositeShape::move(double x, double y)
{
  for (size_t i = 0; i < this->shapes_amount; i++)
  {
    this->shape_vector[i]->move(x, y);
  }
}
void CompositeShape::scale(point_t p, double k)
{
  if (k < 0)
    throw std::invalid_argument("Negative scale is no\n");
  if (this->shapes_amount == 0)
    throw std::invalid_argument("Nothing to scale\n");
  for (size_t i = 0; i < this->shapes_amount; i++)
  {
    point_t shape_pos = this->shape_vector[i]->getFrameRect().pos;
    this->shape_vector[i]->move({ p.x + k * (shape_pos.x - p.x), p.y + k * (shape_pos.y - p.y) });
    this->shape_vector[i]->scale(k);
  }
}
