#ifndef HELPFULFUNCS_HPP
#define HELPFULFUNCS_HPP
#include <cstddef>
#include <iostream>
#include "shape.hpp"

namespace khoroshkin
{
  void implementRectangle(Shape ** allFigures, size_t & figuresCounter);
  void implementCircle(Shape ** allFigures, size_t & figuresCounter);
  void implementComplexquad(Shape ** allFigures, size_t & figuresCounter);
  bool isRectangleCorrect(double x1, double y1, double x2, double y2);
  bool isComplexquad(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4);
  Shape ** expandArray(Shape ** array, size_t currSize, size_t newSize);
  void deleteFigures(Shape ** allFigures, size_t figuresCounter);
  void printResult(Shape ** allFigures, size_t figuresCounter);
  void makeScale(Shape ** allFigures, size_t figuresCounter, double x, double y, double scale);
}

#endif
