#include <iostream>
#include "shape.hpp"
#include "parallelogram.hpp"
#include "rectangle.hpp"
#include "concave.hpp"

int main()
{
  try
  {
    point_t point{ 3, 4 };
    redko::Rectangle rec({ 0, 0 }, { 2, 4 });
    redko::Parallelogram par({ 2, 2 }, { 0, 3 }, { 3, 0 });
    redko::Concave con({ 0, 5 }, { 0, 0 }, { 10, -1 }, { 10, -1 });
    rec.move({ 5, 5 });
    rec.scale({ 5, 5 }, 2);
    par.scale({ 0, 0 }, 2);
    con.scale({ 0, 0 }, 2);
    std::cout << rec.getArea() << " " << par.getArea() << " " << con.getArea() << '\n';
    return 0;
  }
  catch (std::invalid_argument& e)
  {
    std::cerr << e.what();
    return 1;
  }
}
