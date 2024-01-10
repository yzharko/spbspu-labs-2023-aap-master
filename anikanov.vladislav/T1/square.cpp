#include "square.hpp"
#include <iostream>

Square::Square()
{
  side = 0;
  cPoint = PointT();
}

void Square::setSide(float newSide){
  side = newSide;
}

float Square::getSide() const{
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

void Square::move(float x, float y){
  cPoint = PointT(x, y);
}

void Square::scale(float k){
  if (k < 0){
    throw std::logic_error("Invalid scale argument");
  }
  side *= k;
}

std::istream &operator>>(std::istream &in, Square &square){
  PointT leftBottom;
  if (!(in >> leftBottom >> square.side) || square.side <= 0){
    throw std::overflow_error("Invalid Input Square");
  }
  square.cPoint = PointT(leftBottom.x + square.side / 2,
                         leftBottom.y + square.side / 2);
  return in;
}
