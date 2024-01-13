#ifndef DIAMOND_H
#define DIAMOND_H

class Diamond : public Shape
{
public:
  Diamond(Point one, Point two, Point three);
  double getArea();
  FrameRectangle getFrameRectangle();
  void move(double dX, double dY);
  void move(Point dPos);
  void scale(double k);
  Shape* clone();
  std::string getName() const;
  void show();

  Point one;
  Point two;
  Point three;
};
#endif
