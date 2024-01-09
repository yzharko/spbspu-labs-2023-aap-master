#ifndef BASETYPES_HPP
#define BASETYPES_HPP
#include<iostream>

struct point_t
{
  double x;
  double y;
};
struct rectangle_t
{
  double width;
	double height;
  point_t pos;
};
bool operator==(const point_t& lhs, const point_t& rhs);
std::ostream& operator << (std::ostream& os, const base_types::point_t& point);
std::ostream& operator << (std::ostream& os, const base_types::rectangle_t& rectangle);
#endif
