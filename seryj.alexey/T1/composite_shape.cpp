#include "composite_shape.hpp"
CompositeShape::CompositeShape()
{
  this->shapes = 0;
  this->capacity = this->shapeptrs.max_size();
}
CompositeShape::CompositeShape(std::vector<Shape*> v)
{
  shapes = v.size();
  capacity = v.max_size();
  for (size_t i = 0; i < shapes; i++)
  {
    shapeptrs.push_back(v[i]);
  }
}
CompositeShape::CompositeShape(const CompositeShape& cs)
{
  this->shapes = cs.shapes;
  this->capacity = cs.capacity;
  for (size_t i = 0; i < this->shapes; i++)
  {
    this->shapeptrs[i] = cs.shapeptrs[i];
  }
}
CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < this->shapes; i++)
  {
    delete this->shapeptrs[i];
  }
  this->shapeptrs.clear();
}
void CompositeShape::operator+=(Shape* s)
{
  if (shapes < capacity)
  {
    this->shapeptrs.push_back(s);
    shapes = shapeptrs.size();
  }
}
void CompositeShape::operator-=(Shape* s)
{
  std::vector<Shape*>::iterator iter;
  for (size_t i = 0; i < this->shapes; i++)
  {
    if (this->shapeptrs[i] == s)
    {
      delete this->shapeptrs[i];
      iter = this->shapeptrs.begin() + i;
      break;
    }
  }
  this->shapeptrs.erase(iter);
}

double CompositeShape::getArea()
{
  double area = 0;
  for (size_t i = 0; i < this->shapes; i++)
  {
    area += shapeptrs[i]->getArea();
  }
  return area;
}
std::vector<rectangle_t> CompositeShape::getFrameRect()
{
  std::vector<rectangle_t> rec_vec;
  for (size_t i = 0; i < this->shapes; i++)
  {
    rec_vec.push_back(this->shapeptrs[i]->getFrameRect());
  }
  return rec_vec;
}
void CompositeShape::move(std::vector<point_t> v)
{
  for (size_t i = 0; i < std::min(this->shapes, v.size()); i++)
  {
    this->shapeptrs[i]->move(v[i]);
  }
}
void CompositeShape::move(double x, double y)
{
  for (size_t i = 0; i < this->shapes; i++)
  {
    this->shapeptrs[i]->move(x, y);
  }
}
void CompositeShape::scale(point_t p, double k)
{
  for (size_t i = 0; i < this->shapes; i++)
  {
    point_t shape_pos = this->shapeptrs[i]->getFrameRect().pos;
    this->shapeptrs[i]->move({ p.x + k * (shape_pos.x - p.x), p.y + k * (shape_pos.y - p.y) });
    this->shapeptrs[i]->scale(k);
  }
}
