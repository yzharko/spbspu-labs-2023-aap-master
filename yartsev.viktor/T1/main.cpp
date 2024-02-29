#include <iostream>
#include "rectangle.hpp"
#include "base-types.hpp"
#include "shapesInput.hpp"

int main()
{
  size_t shapesAmount = 0;
  size_t shapesSize = 100;
  yartsev::Shape ** shapes = new yartsev::Shape * [shapesSize];
  std::string str;
  std::cin >> str;
  inputFigure(str, &shapes[shapesAmount]);
  std::cout << shapes[shapesAmount]->getArea();
  return 0;
}
