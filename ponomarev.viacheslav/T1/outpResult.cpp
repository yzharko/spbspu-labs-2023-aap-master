#include "outpResult.hpp"

void ponomarev::outpResult(const ponomarev::Shape * const * const figures, const size_t & countOfFigures)
{
  double squareBefScale = 0;
  for (size_t i = 0; i < countOfFigures; i++)
  {
    squareBefScale += figures[i]->getArea();
  }
  std::cout << std::fixed << std::setprecision(1) << squareBefScale << " ";

  for (size_t i = 0; i < countOfFigures; i++)
  {
    ponomarev::rectangle_t frame = figures[i]->getFrameRect();
    double lowerX = frame.pos.x - frame.width * 0.5;
    double lowerY = frame.pos.y - frame.height * 0.5;
    double upperX = frame.pos.x + frame.width * 0.5;
    double upperY = frame.pos.y + frame.height * 0.5;
    std::cout << std::fixed << std::setprecision(1) << lowerX << " " << lowerY << " " << upperX << " " << upperY;
    std::cout << ((i == (countOfFigures - 1)) ? "\n" : " ");
  }
}
