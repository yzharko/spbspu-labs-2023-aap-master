#include <iostream>
#include <string>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "ring.hpp"
#include "regular.hpp"

int main()
{
  bool scale_command = 0;
  std::string name = "";
  reznikova::Shape * figures[1000]{};
  int stored = 0;
  while (!std::cin.eof())
  {
    std::cin >> name;

    if (name == "RING")
    {
      double x, y, r1, r2;
      std::cin >> x >> y >> r1 >> r2;
      reznikova::point_t center(x, y);
      try
      {
        reznikova::Ring ring(center, r1, r2);
      }
      catch(const std::runtime_error &e)
      {
        std::cerr << e.what();
        continue;
      }
      reznikova::Ring ring(center, r1, r2);
      figures[stored++] = &ring;
    }

    else if (name == "REGULAR")
    {
      double x0, y0, x1, y1, x2, y2;
      std::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
      reznikova::point_t center(x0, y0);
      reznikova::point_t point1(x1, y1);
      reznikova::point_t point2(x2, y2);
      try
      {
        reznikova::Regular regular(center, point1, point2);
      }
      catch(const std::runtime_error &e)
      {
        std::cerr << e.what();
        continue;
      }
      reznikova::Regular regular(center, point1, point2);
      figures[stored++] = &regular;
    }

    else if (name == "RECTANGLE")
    {
      double lx, ly, rx, ry;
      std::cin >> lx >> ly >> rx >> ry;
      reznikova::point_t leftpoint(lx, ly);
      reznikova::point_t rightpoint(rx, ry);
      try
      {
        reznikova::Rectangle rectangle(leftpoint, rightpoint);
      }
      catch(const std::runtime_error &e)
      {
        std::cerr << e.what();
        continue;
      }
      reznikova::Rectangle rectangle(leftpoint, rightpoint);
      figures[stored++] = &rectangle;
    }

    else if (name == "SCALE")
    {
      scale_command = 1;
      double x, y, n;
      std::cin >> x >> y >> n;
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
      std::cout << sum_area << " ";

      for (int i = 0; i < stored; i++)
      {
        reznikova::rectangle_t frame_rect = figures[i]->getFrameRect();
        double lx = frame_rect.pos.x - frame_rect.width/2;
        double ly = frame_rect.pos.y - frame_rect.height/2;
        double rx = frame_rect.pos.x + frame_rect.width/2;
        double ry = frame_rect.pos.y + frame_rect.height/2;
        std::cout << lx << " " << ly << " " << rx << " " << ry << " ";
      }
      std::cout << "\n";

      double new_sum_area = 0;
      for (int i = 0; i < stored; i++)
      {
        figures[i]->scale(n);
        new_sum_area += figures[i]->getArea();
      }

      std::cout << new_sum_area << " ";

      for (int i = 0; i < stored; i++)
      {
        reznikova::rectangle_t new_frame_rect = figures[i]->getFrameRect();
        double lx = new_frame_rect.pos.x - new_frame_rect.width/2;
        double ly = new_frame_rect.pos.y - new_frame_rect.height/2;
        double rx = new_frame_rect.pos.x + new_frame_rect.width/2;
        double ry = new_frame_rect.pos.y + new_frame_rect.height/2;
        std::cout << lx << " " << ly << " " << rx << " " << ry << " ";
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
