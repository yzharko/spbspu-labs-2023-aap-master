#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace likhachev
{
  struct point_t {
    public:
      double x;
      double y;
      point_t(double newX, double newY);
      void operator()(double newNumber);
      point_t operator+(const point_t& rhs);
      bool operator==(const point_t& rhs);
      point_t operator-(const point_t& rhs);
      point_t& operator+=(const point_t& rhs);
      point_t& operator-=(const point_t& rhs);
  };

  struct rectangle_t {
    public:
      rectangle_t(double width, double height, likhachev::point_t pos);
      double getArea() const;
      double getWidth() const;
      double getHeight() const;
      likhachev::point_t getPos() const;
      void setWidth(double width);
      void setHeight(double height);
      void setPos(likhachev::point_t pos);
    private:
      double width_;
      double height_;
      likhachev::point_t pos_;
  };
}
#endif
