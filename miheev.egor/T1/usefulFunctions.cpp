#include "usefulFunctions.hpp"
#include <iostream>
#include <cmath>

double roundWithDeep(double x, size_t deepness)
{
  return std::round(x * std::pow(10, deepness))/std::pow(10, deepness);
}

void printPoint(double x, double y)
{
  std::cout << roundWithDeep(x, 1) << ' ' << roundWithDeep(y, 1);
}

void printRect(miheev::rectangle_t rect)
{
  printPoint(rect.pos.x - rect.width/2, rect.pos.y - rect.width/2);
  printPoint(rect.pos.x + rect.width/2, rect.pos.y + rect.height/2);
}

void miheev::printCurrentState(double sumArea, miheev::rectangle_t* rects, size_t rectsAmount)
{
  std::cout << sumArea << ' ';
  for (size_t i = 0; i < rectsAmount; i++)
  {
    ::printRect(rects[i]);
  }
  std::cout << '\n';
}