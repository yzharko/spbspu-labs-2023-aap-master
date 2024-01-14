#include "inpFigure.hpp"
#include <stdexcept>
#include "rectangle.hpp"
#include "base-types.hpp"
#include <iomanip>

void ponomarev::inpFigure(std::string nameOfFigure, std::istream & input, ponomarev::Shape ** figures, size_t & countOfFigures)
{
  if (nameOfFigure == "RECTANGLE")
  {
    double x1, y1, x2, y2;
    input >> x1 >> y1 >> x2 >> y2;
    try
    {
      figures[countOfFigures++] = new Rectangle(point_t{ x1, y1 }, point_t{ x2, y2 });
    }
    catch(const std::invalid_argument & e)
    {
      throw std::invalid_argument("Rectangle is wrong");
    }
  }
}
