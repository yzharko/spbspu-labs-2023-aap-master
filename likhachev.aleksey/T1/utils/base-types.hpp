#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace likhachev
{
  struct Point_t {
    public:
      double x;
      double y;
      Point_t(double newX, double newY);
      void operator()(double newNumber);
      Point_t operator+(const Point_t& rhs);
      bool operator==(const Point_t& rhs);
      Point_t operator-(const Point_t& rhs);
      Point_t& operator+=(const Point_t& rhs);
      Point_t& operator-=(const Point_t& rhs);
  };

  struct Rectangle_t {
    public:
      Rectangle_t(double width, double height, Point_t pos);
      double getArea() const;
      double getWidth() const;
      double getHeight() const;
      likhachev::Point_t getPos() const;
      void setWidth(double width);
      void setHeight(double height);
      void setPos(Point_t pos);
    private:
      double width_;
      double height_;
      likhachev::Point_t pos_;
  };
}
#endif
