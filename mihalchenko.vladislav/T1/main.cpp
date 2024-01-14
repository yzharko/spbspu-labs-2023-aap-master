#include <iostream>
#include <algorithm>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "poligon.hpp"
#include "funcInOut.hpp"

#include <iomanip>

int main()
{
  using namespace mihalchenko;

  bool scaleFound = false;
  size_t sizeOfArrShapes = 10;
  Shape **arrayGeomShapes = new Shape *[sizeOfArrShapes];
  size_t shapeCounter = 0;
  size_t resultScale = 0;
  std::string nameShape;
  size_t tempShapeCounter = 0;
  while ((std::cin >> nameShape) && (scaleFound == false))
  {
    tempShapeCounter = shapeCounter;
    if (shapeCounter == sizeOfArrShapes)
    {
      arrayGeomShapes = mihalchenko::resizeArrayOfShapes(arrayGeomShapes, sizeOfArrShapes);
      sizeOfArrShapes += sizeOfArrShapes;
    }

    if (nameShape == "RECTANGLE")
    {
      shapeCounter = mihalchenko::recordingArrayOfShapes(arrayGeomShapes, shapeCounter, 1);
    }
    else if (nameShape == "SQUARE")
    {
      shapeCounter = mihalchenko::recordingArrayOfShapes(arrayGeomShapes, shapeCounter, 2);
    }
    else if (nameShape == "POLYGON")
    {
      shapeCounter = mihalchenko::recordingArrayOfShapes(arrayGeomShapes, shapeCounter, 3);
    }
    else if (nameShape == "SCALE")
    {
      scaleFound = true;
      resultScale = mihalchenko::processingAndOut(arrayGeomShapes, shapeCounter);
      if (resultScale != 0)
      {
        return 1;
      }
      break;
    }
    else
    {
      bool flg = false;
      for (size_t i = 0; i < nameShape.length(); i++)
      {
        if (std::isalpha(nameShape[i]) != 0)
        {
          flg = true;
        }
      }
      if (flg == true)
      {
        std::cerr << "Error: an incorrect shape has been detected\n";
      }
    }
    if (std::cin.eof() && scaleFound == false)
    {
      std::cerr << "Error: the final word scale was not found"; //
      return 1;
    }
  }
  mihalchenko::delDinStorage(arrayGeomShapes, shapeCounter);
  return 0;
}
