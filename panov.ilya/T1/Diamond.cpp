#include "Shape.h"
#include "Diamond.h"
#include <iostream>
#include <locale.h>
#include <math.h>

Diamond::Diamond(Point one, Point two, Point three) :
  one(one),
  two(two),
  three(three)
{}

double Diamond::getArea()
{
  return 2 * (two.getY() - three.getY()) * (three.getX() - one.getX());
}

FrameRectangle Diamond::getFrameRectangle()
{
  double width = 2 * (three.getX() - one.getX());
  double height = 2 * (two.getY() - three.getY());
  FrameRectangle frameRect(three, width , height);
  return frameRect;
}

void Diamond::move(double dX, double dY)
{
  two = Point(two.getX() + dX, two.getY() + dY);
  three = Point(three.getX() + dX, three.getY() + dY);
  one = Point(one.getX() + dX, one.getY() + dY);
}

void Diamond::move(Point dPos)
{
  Point delta = { three.getX() - dPos.getX(), three.getY() - dPos.getY() };
  Diamond::move(delta.getX(), delta.getY());
}

void Diamond::scale(double k)
{
  Point center(0, 0);
  Point newA(one.getX() - three.getX(), one.getY() - three.getY());
  Point newB(two.getX() - three.getX(), two.getY() - three.getY());

  newA.setX(newA.getX() * k);
  newA.setY(newA.getY() * k);

  newB.setX(newB.getX() * k);
  newB.setY(newB.getY() * k);

  one.setX(newA.getX() + three.getX());
  one.setY(newA.getY() + three.getY());
  two.setX(newB.getX() + three.getX());
  two.setY(newB.getY() + three.getY());
}
Shape* Diamond::clone(){
  return new Diamond(*this);
}
std::string Diamond::getName() const {
  return "DIAMOND";
}
void Diamond::show() {
  std::cout << std::fixed;
  std::cout.precision(1);
  std::cout << "DIAMOND " << one.getX() << " " << one.getY()<< " " << two.getX() << " " << two.getY()<< " " << three.getX() << " " << three.getY() << "\n";
}
