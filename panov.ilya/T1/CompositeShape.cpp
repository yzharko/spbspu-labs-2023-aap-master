#include "CompositeShape.h"
#include <iostream>

CompositeShape::CompositeShape() {
  maxs_ = 0;
  currs_ = 0;
  pos_ = Point();
  shapes_ = nullptr;
}

CompositeShape::CompositeShape(int maxs) {
  maxs_ = maxs;
  if (maxs <= 0 || std::isalpha(maxs)) {
    std::cerr << "Incorrect input!";
    exit(-1);
  }
  shapes_ = new Shape * [maxs_];
}

CompositeShape::CompositeShape(const CompositeShape& comp) {
  maxs_ = comp.maxs_;
  currs_ = comp.currs_;
  pos_ = comp.pos_;
  shapes_ = new Shape * [maxs_];
  for (int i = 0; i < currs_; i++)
  {
    shapes_[i] = comp.shapes_[i];
  }
}

CompositeShape::CompositeShape(CompositeShape&& comp) noexcept {
  shapes_ = comp.shapes_;
  maxs_ = comp.maxs_;
  currs_ = comp.currs_;
  pos_ = comp.pos_;
  shapes_ = nullptr;
  maxs_ = 0;
  currs_ = 0;
  pos_ = Point();

}

CompositeShape::~CompositeShape() {
  delete[] this->shapes_;
}

CompositeShape& CompositeShape::operator=(const CompositeShape& comp) {
  maxs_ = comp.maxs_;
  currs_ = comp.currs_;
  shapes_ = new Shape * [maxs_];
  for (int i = 0; i < currs_; i++)
  {
    shapes_[i] = comp.shapes_[i];
  }
  return *this;
}

CompositeShape& CompositeShape::operator=(CompositeShape&& comp) noexcept {
  delete[] shapes_;
  maxs_ = comp.maxs_;
  currs_ = comp.currs_;
  shapes_ = comp.shapes_;
  comp.shapes_ = nullptr;
  maxs_ = 0;
  currs_ = 0;
  return *this;
}

void CompositeShape::addShape(Shape* shape) {
  if (currs_ < maxs_) {
    shapes_[currs_] = shape;
    currs_ += 1;
  }
}

Shape* CompositeShape::operator[](int k) {
  return shapes_[k];
}

double CompositeShape::getArea() {
  double area = 0.0;
  for (int i = 0; i < currs_; i++) {
    area += shapes_[i]->getArea();
  }
  return area;
}

FrameRectangle CompositeShape::getFrameRectangle() {
  double mnx = shapes_[0]->getFrameRectangle().getPos().getX();
  double mxx = shapes_[0]->getFrameRectangle().getPos().getX() +
    shapes_[0]->getFrameRectangle().getWidth();
  double mny = shapes_[0]->getFrameRectangle().getPos().getY();
  double mxy = shapes_[0]->getFrameRectangle().getPos().getY() +
    shapes_[0]->getFrameRectangle().getHeight();

  for (int i = 0; i < currs_; i++) {
    double x1 = shapes_[i]->getFrameRectangle().getPos().getX();
    double x2 = shapes_[i]->getFrameRectangle().getPos().getX() +
      shapes_[i]->getFrameRectangle().getWidth();
    double y1 = shapes_[i]->getFrameRectangle().getPos().getY();
    double y2 = shapes_[i]->getFrameRectangle().getPos().getY() +
      shapes_[i]->getFrameRectangle().getHeight();

    if (x1 < mnx) {
      mnx = x1;
    }
    if (x2 > mxx) {
      mxx = x2;
    }
    if (y1 < mny) {
      mny = y1;
    }
    if (y2 > mxy) {
      mxy = y2;
    }
  }

  double width = mxx - mnx;
  double height = mxy - mny;
  pos_.setX(mnx);
  pos_.setY(mny);
  FrameRectangle frameRect(width, height, pos_);
  return frameRect;
}

void CompositeShape::move(double dx, double dy) {
  pos_ = Point(pos_.getX() + dx, pos_.getY() + dy);
}

void CompositeShape::scale(double size) {
  if (size <= 0 || std::isalpha(size)) {
    std::cerr << "Incorrect input!";
    exit(-1);
  }
  for (int i = 0; i < currs_; i++) {
    shapes_[i]->scale(size);
  }
}

Shape* CompositeShape::clone() {
  return new CompositeShape(*this);
}

std::string CompositeShape::getName() {
  return "COMPOSITE SHAPE";
}