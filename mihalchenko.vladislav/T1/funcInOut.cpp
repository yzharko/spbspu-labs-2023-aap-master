#include "funcInOut.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "poligon.hpp"
#include "base-types.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace mihalchenko;

bool mihalchenko::isPoligon()
{
  return true;
}

Shape **mihalchenko::resizeArrayOfShapes(Shape **arrayGeomShapes, size_t sizeOfArrShapes)
{
  sizeOfArrShapes += sizeOfArrShapes;
  Shape **tempContainer = new Shape *[sizeOfArrShapes];
  std::copy(arrayGeomShapes, arrayGeomShapes + sizeOfArrShapes, tempContainer);
  for (size_t i = 0; i < sizeOfArrShapes; ++i)
  {
    delete arrayGeomShapes[i];
  }
  delete[] arrayGeomShapes;
  arrayGeomShapes = tempContainer;
  return arrayGeomShapes;
}

void mihalchenko::delDinStorage(mihalchenko::Shape **arrayGeomShapes, size_t shapeCounter)
{
  for (size_t i = 0; i < shapeCounter; ++i)
  {
    if (arrayGeomShapes[i] != nullptr)
    {
      delete arrayGeomShapes[i];
    }
  }
  delete[] arrayGeomShapes;
}

size_t mihalchenko::recordingArrayOfShapes(mihalchenko::Shape **arrayGeomShapes, size_t shapeCounter, size_t markerGeomShape)
{
  switch (markerGeomShape)
  {
  case 1:
  {
    double x1, y1, x2, y2, width;
    if (std::cin >> x1 >> y1 >> x2 >> y2 && (x1 < x2 && y1 < y2))
    {
      arrayGeomShapes[shapeCounter++] = new mihalchenko::Rectangle(point_t{x1, y1}, point_t{x2, y2});
    }
    else
    {
      std::cerr << "Error: wrong rectangle input\n";
    }
    break;
  }
  case 2:
  {
    double x, y, width;
    if (std::cin >> x >> y >> width && width > 0)
    {
      arrayGeomShapes[shapeCounter++] = new mihalchenko::Square(point_t{x, y}, width);
    }
    else
    {
      std::cerr << "Error: an incorrect SQUARE has been detected\n";
    }
    break;
  }
  case 3:
  {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    /*if (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 && mihalchenko::isPoligon())
    {
      arrayGeomShapes[shapeCounter++] = new mihalchenko::Poligon();
    }
    else
    {
      std::cerr << "Error: an incorrect POLYGON has been detected\n";
    }*/
    break;
  }
  // case 4:
  default:
    std::cerr << "Error: wrong markerGeomShape input\n";
    break;
  }
  return shapeCounter;
}

size_t mihalchenko::processingAndOut(mihalchenko::Shape **arrayGeomShapes, size_t shapeCounter)
{
  double x, y, scale;
  if (shapeCounter == 0)
  {
    std::cerr << "Error: the word SCALE was not found";
    for (size_t i = 0; i < shapeCounter; ++i)
    {
      delete arrayGeomShapes[i];
    }
    delete[] arrayGeomShapes;
    return 1;
  }
  if (std::cin >> x >> y >> scale && scale > 0)
  {
    std::cout << std::fixed << std::setprecision(1);
    double squareOfShapes = 0;
    for (size_t i = 0; i < shapeCounter; ++i)
    {
      squareOfShapes += arrayGeomShapes[i]->getArea();
    }
    std::cout << squareOfShapes << " ";
    for (size_t i = 0; i < shapeCounter; ++i)
    {
      std::cout << arrayGeomShapes[i]->getFrameRect().pos_.x_ - arrayGeomShapes[i]->getFrameRect().width_ / 2 << " ";
      std::cout << arrayGeomShapes[i]->getFrameRect().pos_.y_ - arrayGeomShapes[i]->getFrameRect().height_ / 2 << " ";
      std::cout << arrayGeomShapes[i]->getFrameRect().pos_.x_ + arrayGeomShapes[i]->getFrameRect().width_ / 2 << " ";
      std::cout << arrayGeomShapes[i]->getFrameRect().pos_.y_ + arrayGeomShapes[i]->getFrameRect().height_ / 2;
      if (i != shapeCounter - 1)
      {
        std::cout << " ";
      }
    }
    std::cout << "\n";
    for (size_t i = 0; i < shapeCounter; ++i)
    {
      point_t centrePointOld = arrayGeomShapes[i]->getFrameRect().pos_;
      arrayGeomShapes[i]->move({x, y});
      point_t changePosition;
      changePosition.x_ = fabs(centrePointOld.x_ - arrayGeomShapes[i]->getFrameRect().pos_.x_) * scale;
      changePosition.y_ = fabs(centrePointOld.y_ - arrayGeomShapes[i]->getFrameRect().pos_.y_) * scale;
      arrayGeomShapes[i]->scale(scale);
      arrayGeomShapes[i]->move(changePosition.x_, changePosition.y_);
    }
    squareOfShapes = 0;
    for (size_t i = 0; i < shapeCounter; ++i)
    {
      squareOfShapes += arrayGeomShapes[i]->getArea();
    }
    std::cout << squareOfShapes << " ";
    for (size_t i = 0; i < shapeCounter; ++i)
    {
      std::cout << arrayGeomShapes[i]->getFrameRect().pos_.x_ - arrayGeomShapes[i]->getFrameRect().width_ / 2 << " ";
      std::cout << arrayGeomShapes[i]->getFrameRect().pos_.y_ - arrayGeomShapes[i]->getFrameRect().height_ / 2 << " ";
      std::cout << arrayGeomShapes[i]->getFrameRect().pos_.x_ + arrayGeomShapes[i]->getFrameRect().width_ / 2 << " ";
      std::cout << arrayGeomShapes[i]->getFrameRect().pos_.y_ + arrayGeomShapes[i]->getFrameRect().height_ / 2;
      if (i != shapeCounter - 1)
      {
        std::cout << " ";
      }
    }
    std::cout << "\n";
    return 0;
  }
  else
  {
    std::cerr << "Error: an incorrect SCALE has been detected \n";
    mihalchenko::delDinStorage(arrayGeomShapes, shapeCounter);
    return 1;
  }
}
