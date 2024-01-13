#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "regular.hpp"
#include "compositeShape.hpp"

int main()
{
  using namespace smolyakov;

  Regular* regular = new Regular(point_t{0, 0}, point_t{0, 1}, point_t{1, 1});
  std::cout << regular->getArea() << '\n';
}
