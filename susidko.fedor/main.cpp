#include <iostream>
#include <iomanip>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "polygon.hpp"

int main()
{
  std::string name = "";
  Shape ** shapes = new Shape * [10]{};
  int counter = 0;
  while (std::cin)
  {
    std::cin >> name;
    if (name == "RECTANGLE")
    {
      double a, b, c, d;
      std::cin >> a >> b >> c >> d;
      shapes[counter++] = new Rectangle{point_t {a, b}, point_t {c, d}};
      //std::cout << counter;
      //shapes[counter]->print();
    }
    else if (name == "SCALE")
    {
      double x, y, coef;
      std::cin >> x >> y >> coef;
      double areasSum = 0;
      rectangle_t frameRects[counter] {};
      rectangle_t newFrameRects[counter] {};
      for (int i = 0; i < counter; i++)
      {
        frameRects[i] = shapes[i]->getFrameRect();
        areasSum += shapes[i]->getArea();
        try
        {
          newFrameRects[i] = shapes[i]->scale(x, y, coef, frameRects[i]);
        }
        catch(const std::logic_error & e)
        {
          std::cerr << e.what();
          return 1;
        }
      }
      std::cout << std::fixed << std::setprecision(1);
      std::cout << areasSum << ' ';
      for (int i = 0; i < counter; i++)
      {
        rectangle_t temp = frameRects[i];
        std::cout << temp.pos.x - (temp.wight)/2 << ' ';
        std::cout << temp.pos.y - (temp.height)/2 << ' ';
        std::cout << temp.pos.x + (temp.wight)/2 << ' ';
        std::cout << temp.pos.y + (temp.height)/2 << ' ';
      }
      std::cout << '\n';
      std::cout << coef * coef * areasSum << ' ';
      for (int i = 0; i < counter; i++)
      {
        rectangle_t temp = newFrameRects[i];
        std::cout << temp.pos.x - (temp.wight)/2 << ' ';
        std::cout << temp.pos.y - (temp.height)/2 << ' ';
        std::cout << temp.pos.x + (temp.wight)/2 << ' ';
        std::cout << temp.pos.y + (temp.height)/2 << ' ';
      }
      return 0;
    }
    else if (name == "EX")
    {
      return 0;
    }
    else
    {
      std::cout << "Ne realizoval yet";
    }
  }
  return 0;
}
