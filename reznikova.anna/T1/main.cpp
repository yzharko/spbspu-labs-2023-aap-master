#include <iostream>
#include <string>
#include <iomanip>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "ring.hpp"
#include "regular.hpp"

int main()
{
  using namespace reznikova;
  bool scale_command = 0;
  std::string name = "";
  Shape* figures[1000] = {0};
  int stored = 0;
  while (!std::cin.eof())
  {
    std::cin >> name;

    if (name == "RING")
    {
      double x, y, r1, r2;
      std::cin >> x >> y >> r1 >> r2;
      point_t center(x, y);
      try
      {
        Ring ring(center, r1, r2);
      }
      catch(const std::runtime_error &e)
      {
        std::cerr << e.what();
        continue;
      }
      figures[stored++] = new Ring(center, r1, r2);
    }

    else if (name == "REGULAR")
    {
      double x0, y0, x1, y1, x2, y2;
      std::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
      point_t center(x0, y0);
      point_t point1(x1, y1);
      point_t point2(x2, y2);
      try
      {
        Regular regular(center, point1, point2);
      }
      catch(const std::runtime_error &e)
      {
        std::cerr << e.what();
        continue;
      }
      figures[stored++] = new Regular(center, point1, point2);
    }

    else if (name == "RECTANGLE")
    {
      double lx, ly, rx, ry;
      std::cin >> lx >> ly >> rx >> ry;
      point_t leftpoint(lx, ly);
      point_t rightpoint(rx, ry);
      try
      {
        Rectangle rectangle(leftpoint, rightpoint);
      }
      catch(const std::runtime_error &e)
      {
        std::cerr << e.what();
        continue;
      }
      figures[stored++] = new Rectangle(leftpoint, rightpoint);
    }

    else if (name == "SCALE")
    {
      scale_command = 1;
      double x, y, n;
      std::cin >> x >> y >> n;
      point_t center(x, y);
      if (n <= 0)
      {
        std::cerr << "Negative Coeff Scale";
        return 1;
      }

      if (stored == 0)
      {
        std::cerr << "nothing to scale\n";
        return 1;
      }
      double sum_area = 0;
      for (int i = 0; i < stored; i++)
      {
        sum_area += figures[i]->getArea();
      }
      std::cout << std::fixed << std::setprecision(1) << sum_area << " ";

      for (int i = 0; i < stored; i++)
      {
        rectangle_t frame_rect = figures[i]->getFrameRect();
        std::cout << std::fixed << std::setprecision(1) << frame_rect.leftpoint.x << " " << frame_rect.leftpoint.y << " ";
        std::cout << std::fixed << std::setprecision(1) << frame_rect.rightpoint.x << " " << frame_rect.rightpoint.y << " ";
      }
      std::cout << "\n";

      double new_sum_area = 0;
      for (int i = 0; i < stored; i++)
      {
        figures[i]->scale(center, n);
        new_sum_area += figures[i]->getArea();
      }

      std::cout << std::fixed << std::setprecision(1) << new_sum_area << " ";

      for (int i = 0; i < stored; i++)
      {
        rectangle_t frame_rect = figures[i]->getFrameRect();
        std::cout << std::fixed << std::setprecision(1) << frame_rect.leftpoint.x << " " << frame_rect.leftpoint.y << " ";
        std::cout << std::fixed << std::setprecision(1) << frame_rect.rightpoint.x << " " << frame_rect.rightpoint.y << " ";
        delete figures[i];
      }
      std::cout << "\n";

      break;
    }
  }

  if (scale_command == 0)
  {
    std::cerr << "no scale command\n";
    return 1;
  }

  return 0;
}

