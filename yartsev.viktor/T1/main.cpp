#include <iostream>
#include "rectangle.hpp"
#include "base-types.hpp"

int main()
{
  std::string str = "";
  double x = 0, y = 0;
  std::cin >> str;
  std:: cin >> x >> y;
  yartsev::point_t bottomLeftPoint{x, y};
  std::cin >> x >> y;
  yartsev::point_t topRightPoint{x, y};
  std::cout << bottomLeftPoint.x_ << " " << bottomLeftPoint.y_ << "\n";
  std::cout << topRightPoint.x_ << " " << topRightPoint.y_ << "\n";
  return 0;
}
