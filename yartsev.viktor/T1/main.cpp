#include <iostream>
#include <iomanip>
#include "rectangle.hpp"
#include "base-types.hpp"
#include "shapesInput.hpp"
#include "shapes-output.hpp"
#include "circle.hpp"
#include "ellipse.hpp"

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
      if (scaling <= 0) {
        for (size_t i = 0; i < shapesAmount; i++) {
          delete shapes[i];
        }
        std::cerr << "Scaling is below or equals zero\n";
        return 1;
      }
      yartsev::point_t center(x, y);
      double area = 0;
      for (size_t i = 0; i < shapesAmount; i++) {
        area += shapes[i]->getArea();
      }
      std::cout << std::fixed << std::setprecision(1) << area;
      for (size_t i = 0; i < shapesAmount; i++) {
        yartsev::printFrameRect(shapes[i]);
      }
      std::cout << "\n";
      double newArea = 0;
      for (size_t i = 0; i < shapesAmount; i++) {
        shapes[i]->pointScale(center, scaling);
        newArea += shapes[i]->getArea();
      }
      std::cout << std::fixed << std::setprecision(1) << newArea;
      for (size_t i = 0; i < shapesAmount; i++) {
        yartsev::printFrameRect(shapes[i]);
      }
      std::cout << "\n";
      break;
    } else {
      try {
        inputFigure(str, &shapes[shapesAmount], shapesAmount);
      } catch (const std::logic_error& e) {
        std::cerr << e.what();
      }
    }
  }
  for (size_t i = 0; i < shapesAmount; i++) {
    delete shapes[i];
  }
  if (!wasScale) {
    std::cerr << "No SCALE was written\n";
    return 1;
  }
  return 0;
}
