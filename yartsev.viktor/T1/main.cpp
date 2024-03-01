#include <iostream>
#include <iomanip>
#include "rectangle.hpp"
#include "base-types.hpp"
#include "shapesInput.hpp"
#include "shapes-output.hpp"

int main()
{
  size_t shapesAmount = 0;
  yartsev::Shape * shapes[100]{};
  std::string str = "";
  bool wasScale = false;
  while (!std::cin.eof()) {
    std::cin >> str;
    if (str == "SCALE") {
      wasScale = true;
      double x, y, scaling;
      std::cin >> x >> y >> scaling;
      yartsev::point_t center(x, y);
      double area = 0;
      for (int i = 0; i < shapesAmount; i++) {
        area += shapes[i]->getArea();
      }
      std::cout << std::fixed << std::setprecision(1) << area;
      for (int i = 0; i < shapesAmount; i++) {
        yartsev::printFrameRect(shapes[i]);
      }
      std::cout << "\n";
      double newArea = 0;
      for (int i = 0; i < shapesAmount; i++) {
        shapes[i]->pointScale(center, scaling);
        newArea += shapes[i]->getArea();
      }
      std::cout << std::fixed << std::setprecision(1) << newArea;
      for (int i = 0; i < shapesAmount; i++) {
        yartsev::printFrameRect(shapes[i]);
      }
      std::cout << "\n";
    } else {
      inputFigure(str, &shapes[shapesAmount], &shapesAmount);
    }
  }
  if (!wasScale) {
    std::cerr << "No SCALE was written\n";
    return 1;
  }
  return 0;
}
