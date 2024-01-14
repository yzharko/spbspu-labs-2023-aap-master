#include <iostream>
#include "rectangle.hpp"
#include "inpFigure.hpp"
#include <iomanip>

using namespace ponomarev;

int main()
{
  ponomarev::Shape ** figures = new ponomarev::Shape * [3];
  size_t countOfFigures = 0;
  bool isWrongFigureEnter = 0;
  bool isInputScale = 0;

  while (std::cin)
  {
    std::string nameOfFigure;
    std::cin >> nameOfFigure;

    if (nameOfFigure == "SCALE" && countOfFigures == 0)
    {
      std::cerr << "Nothing to scale.\n";
      delete[] figures;
      return 1;
    }

    if (nameOfFigure == "SCALE")
    {
      isInputScale = true;
      break;
    }

    try
    {
      ponomarev::inpFigure(nameOfFigure, std::cin, figures, countOfFigures);
    }
    catch(const std::invalid_argument & e)
    {
      isWrongFigureEnter = true;
    }
  }

  if (!isInputScale)
  {
    std::cerr << "Scale is not entered.\n";
    for (size_t i = 0; i < countOfFigures; i++)
    {
      delete figures[i];
    }
    delete[] figures;
    return 1;
  }

  double squareBefScale = 0;
  for (size_t i = 0; i < countOfFigures; i++)
  {
    squareBefScale += figures[i]->getArea();
  }
  std::cout << std::fixed << std::setprecision(1) << squareBefScale << " ";

  for (size_t i = 0; i < countOfFigures; i++)
  {
    ponomarev::rectangle_t frame = figures[i]->getFrameRect();
    double lowerX = frame.center.x - frame.width * 0.5;
    double lowerY = frame.center.y - frame.height * 0.5;
    double upperX = frame.center.x + frame.width * 0.5;
    double upperY = frame.center.y + frame.height * 0.5;
    std::cout << std::fixed << std::setprecision(1) << lowerX << " " << lowerY << " " << upperX << " " << upperY;
  }
  std::cout << "\n";
  if (isWrongFigureEnter)
  {
    std::cerr << "Wrong figure input";
    return 1;
  }

  for (size_t i = 0; i < countOfFigures; i++)
  {
    delete figures[i];
  }
  delete[] figures;

  return 0;
}
