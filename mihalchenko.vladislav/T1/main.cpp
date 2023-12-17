#include <iostream>
#include <cstring>
#include "base-types.hpp"
#include "shape.hpp"
#include "myStruct.hpp"
#include "myStruct.hpp"
#include "rectangle.hpp"
#include "poligon.hpp"
#include "square.hpp"

using namespace mihalchenko;

int main()
{
/*std::cout <<"Введите (через пробел) координаты X,Y точки Point:" << std::endl;
  Point_t point;
  input(point);
  output(point);

  std::cout << std::endl;
  std::cout <<"Rectangle:" << std::endl;
  Rectangle_t rectangleWH;
  rectangleWH.setAll(10, 20, 7, 7);

  std::cout <<"Введите тип фигуры с параметрами:" << std::endl;
*/
  char element = 0;
  DinString s1(1, '0');
  std::cin >> std::noskipws;

  while ((std::cin >> element) && (element != '\n'))
  {
    if (s1.counterCurrent < s1.size)
    {
        s1.dinAppend(element);
    }
    else
    {
      try
      {
        s1.dinResize();
        s1.dinAppend(element);
      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << '\n';
        return 1;
      }
    }
  }
  //s1.dinOutput();
  std::cout << std::endl;

  float squareSUM = 0;
  //Считываем и анализируем принятую строку
  size_t rezTypeStr = 0;
  rezTypeStr = mihalchenko::stringAnalyz(s1.dinstr, s1.size);
  if (rezTypeStr == 1)
  {
    Square mySquare;
    std::cout << mySquare.getArea(1, 1.0, 2.7) << std::endl;
    squareSUM = squareSUM + mySquare.getArea(1, 1.0, 2.7);
  }
  else if (rezTypeStr == 2)
  {
    Poligon myPoligon;
    std::cout << myPoligon.getArea(1.0, 2.7) << std::endl;
    squareSUM = squareSUM + myPoligon.getArea(1.0, 2.7);
  }
  else if (rezTypeStr == 3)
  {
    Restangle myRestangle;
    std::cout << myRestangle.getArea(1.0, 2.7, 5.0, 7.7) << std::endl;
    squareSUM = squareSUM + myRestangle.getArea(1.0, 2.7, 5.0, 7.7);
  }
  std::cout << "squareSUM=" << squareSUM << std::endl;
}
