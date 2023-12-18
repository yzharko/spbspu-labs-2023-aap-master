#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace miheev
{
  struct point_t
  {
    point_t();
    point_t(double x, double y);
    double x_;
    double y_;
    double distTo(point_t) const;
    point_t findMiddle(point_t rhs) const;
    void move(double dx, double dy);
  };

  struct rectangle_t
  {
  public:
    rectangle_t(point_t pos, double width, double height);
  private:
    double width_;
    double height_;
    point_t pos_;
  };
}

#endif
