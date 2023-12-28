#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace mihalchenko
{
  struct Point_t
  {
  public:
    float x_ = 5;
    float y_ = 7;
    Point_t();
    Point_t(float posX, float posY);
    ~Point_t();
    void setX(float x);
    void setY(float y);
    float getX() const;
    float getY() const;
  };

  struct Rectangle_t
  {
  public:
    float x_ = 7;
    float y_ = 7;
    float width_ = 10;
    float height_ = 20;
    Rectangle_t();
    Rectangle_t(float width, float height, float posX, float posY);
    ~Rectangle_t();
    void outPos(char simbol, float x, float y);
    void setAll(float width, float height, float posX, float posY);
  };

  void input(Point_t &point);
  void output(const Point_t &point);
}
#endif
