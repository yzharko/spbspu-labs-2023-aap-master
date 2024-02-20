#include <iostream>
#include <string>
#include "shape.hpp"
#include "rectangle.hpp"
#include "parallelogram.hpp"
#include "regular.hpp"
#include "functions.hpp"

namespace toksen
{
  void freeMemory(Shape** shapes, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      delete shapes[i];
    }
    delete[] shapes;
  }

  void printRectangle(const Rectangle& rectangle)
  {
    Rectangle_t frame = rectangle.getFrameRect();
    std::cout << "Rectangle - Width: " << frame.width << ", Height: " << frame.height
        << ", Position: (" << frame.pos.x << ", " << frame.pos.y << "\n square :  " << rectangle.getArea() << ")\n";
  }

  void printRegular(const Regular& regular)
  {
    Rectangle_t frame = regular.getFrameRect();
    std::cout << "Regular - Width: " << frame.width << ", Height: " << frame.height
        << ", Position: (" << frame.pos.x << ", " << frame.pos.y << "\n square :  " << regular.getArea() << ")\n";
  }

  void printParallelogram(const Parallelogram& parallelogram)
  {
    Rectangle_t frame = parallelogram.getFrameRect();
    std::cout << "Parallelogram - Width: " << frame.width << ", Height: " << frame.height
        << ", Position: (" << frame.pos.x << ", " << frame.pos.y << "\n square :  " << parallelogram.getArea() << ")\n";
  }

  void scaleShape(Shape* shape, double scaleFactor)
  {
    shape->scale(scaleFactor);
  }

  void moveShape(Shape* shape, double dx, double dy)
  {
    shape->move(dx, dy);
  }
}
