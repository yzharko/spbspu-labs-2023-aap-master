#include "base-types.hpp"
#include <iostream>

mihalchenko::Point_t::Point_t() : x_(0.0), y_(0.0) {}

mihalchenko::Point_t::Point_t(float x, float y) : x_(x), y_(y) {}

mihalchenko::Point_t::~Point_t() {}

void mihalchenko::Point_t::setX(float x)
{
  x_ = x;
}

void mihalchenko::Point_t::setY(float y)
{
  y_ = y;
}

float mihalchenko::Point_t::getX() const
{
  return x_;
}

float mihalchenko::Point_t::getY() const
{
  return y_;
}

void mihalchenko::input(Point_t &point)
{
  float x = 5;
  float y = 5;
  std::cin >> x >> y;
  //std::cout << "ВВЕЛИ(" << x << ", " << y << ")\n";
  point.setX(x);
  point.setY(y);
}

void mihalchenko::output(const Point_t &point)
{
  std::cout << "(" << point.getX() << ", " << point.getY() << ")\n";
}

//  std::cout << "Pos(" << x_ << "," << y_ << ")" << std::endl;


//===================================================================================
mihalchenko::Rectangle_t::Rectangle_t() : width_(10.0) , height_(10.0), x_(0.0), y_(0.0) {}

mihalchenko::Rectangle_t::Rectangle_t(float width, float height, float x, float y) : width_(width), height_(height), x_(x), y_(y) {};

mihalchenko::Rectangle_t::~Rectangle_t() {};

void mihalchenko::Rectangle_t::Rectangle_t::setAll(float width, float height, float pointX, float pointY)
{
  outPos('A', pointX - width/2, pointY - height/2);
  outPos('B', pointX - width/2, pointY + height/2);
  outPos('C', pointX + width/2, pointY + height/2);
  outPos('D', pointX + width/2, pointY - height/2);
}

void mihalchenko::Rectangle_t::outPos(char simbol, float posX, float posY)
{
  x_ = posX;
  y_ = posY;
  std::cout << simbol << "(" << x_ << "," << y_ << ")" << std::endl;
}
