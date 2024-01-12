#include <iostream>
#include "rectangle.hpp"
#include "square.hpp"
#include "ellipse.hpp"


int main() 
{
  std::cout << "1 RECTANGLE" << '\n';
  nikiforov::Rectangle Rect({ 1.0, 1.0 }, { 5.0, 3.0 });
  Rect.point(Rect);
  std::cout << "Area - " << Rect.getArea() << '\n' << '\n';


  std::cout << "2 RECTANGLE" << '\n';
  Rect.scale(2.0);
  Rect.point(Rect);
  std::cout << "Area - " << Rect.getArea() << '\n' << '\n';

  std::cout << "1 SQUARE" << '\n';
  nikiforov::Square SQ({ 1.0, 1.0 }, 2.0);
  SQ.point(SQ);
  std::cout << "Area - " << SQ.getArea() << '\n' << '\n';


  std::cout << "2 SQUARE" << '\n';
  SQ.scale(2.0);
  SQ.point(SQ);
  std::cout << "Area - " << SQ.getArea() << '\n' << '\n';

  std::cout << "1 ELLIPSE" << '\n';
  nikiforov::Ellipse ELL({ 1.0, 1.0 }, 2.0 , 4.0);
  ELL.point(ELL);
  std::cout << "Area - " << ELL.getArea() << '\n' << '\n';


  std::cout << "2 ELLIPSE" << '\n';
  ELL.scale(2.0);
  ELL.point(ELL);
  std::cout << "Area - " << ELL.getArea() << '\n' << '\n';


  return 0;
}

