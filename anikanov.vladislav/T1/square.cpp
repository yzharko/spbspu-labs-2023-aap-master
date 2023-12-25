#include "square.h"
#include <iostream>

Square::Square()
{
  side = 0;
  cPoint = PointT();
}

void Square::setSide(double newSide){
  side = newSide;
}

double Square::getSide() const{
  return side;
}

PointT Square::getCPoint() const{
  return cPoint;
}

long long Square::getArea(){
  return side * side;
}

RectangleT Square::getFrameRect(){
  return RectangleT(cPoint, side, side);
}

void Square::move(PointT newCPoint){
  cPoint = newCPoint;
}

void Square::move(double x, double y){
  cPoint = PointT(x, y);
}

void Square::scale(double k){
  side *= k;
}

std::istream &operator>>(std::istream &in, Square &square){
  PointT leftBottom;
  if (!(in >> leftBottom >> square.side)){
    throw std::runtime_error("Invalid Input");
  }
  square.cPoint = PointT(leftBottom.x + square.side / 2,
                         leftBottom.y + square.side / 2);
  return in;
}
