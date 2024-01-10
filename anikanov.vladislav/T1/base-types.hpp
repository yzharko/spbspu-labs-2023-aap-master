#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

#include <iosfwd>

namespace anikanov {
  struct PointT {
    float x;
    float y;

    explicit PointT();

    explicit PointT(float x, float y);

    PointT(const PointT &);

    PointT &operator=(PointT another_point);

    PointT &operator+(PointT another_point);

//    friend std::istream &operator>>(std::istream &, PointT &);
//
//    friend std::ostream &operator<<(std::ostream &, const PointT &);
  };

  struct RectangleT {
    float width;
    float height;
    PointT pos;

    explicit RectangleT();

    explicit RectangleT(PointT pos, float width, float height);

//    friend std::ostream &operator<<(std::ostream &, const RectangleT &);
  };
}

#endif
