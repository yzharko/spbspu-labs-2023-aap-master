#include "rectangle.hpp"
#include "inpFigure.hpp"
#include "outpResult.hpp"

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

  ponomarev::outpResult(figures, countOfFigures);

  double scaleX, scaleY, k;
  std::cin >> scaleX >> scaleY >> k;

  for (size_t i = 0; i < countOfFigures; i++)
  {
    ponomarev::rectangle_t frameBeforeMove = figures[i]->getFrameRect();
    figures[i]->move({ scaleX, scaleY });
    ponomarev::rectangle_t frameAfterMove = figures[i]->getFrameRect();
    try
    {
      figures[i]->scale(k);
    }
    catch(std::invalid_argument & e)
    {
      std::cerr << "Wrong input scale coefficient\n";
      for (size_t i = 0; i < countOfFigures; i++)
      {
        delete figures[i];
      }
      delete[] figures;
      return 1;
    }
    double offsetX = (frameBeforeMove.pos.x - frameAfterMove.pos.x) * k;
    double offsetY = (frameBeforeMove.pos.y - frameAfterMove.pos.y) * k;
    figures[i]->move(offsetX, offsetY);
  }

  ponomarev::outpResult(figures, countOfFigures);

  if (isWrongFigureEnter)
  {
    std::cerr << "Wrong figure input.\n";
  }

  for (size_t i = 0; i < countOfFigures; i++)
  {
    delete figures[i];
  }
  delete[] figures;

  return 0;
}
