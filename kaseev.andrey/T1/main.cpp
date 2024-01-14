#include <iostream>
#include <string>
#include <iomanip>
#include "shape.hpp"
#include " base-types.hpp"
#include "rectangle.hpp"
#include "Parallelogram.hpp"
#include "Ellipse.hpp"

using namespace kaseev;

int main()
{
  struct CompositeShape {
    size_t shapes;
    size_t capacity;
    kaseev::shape **shapeptrs;

    ~CompositeShape()
    {
      for (size_t i = 0; i < shapes; ++i)
      {
        delete shapeptrs[i];
      }
      delete[] shapeptrs;
    }
  };

  size_t arraySize = 10;
  kaseev::shape **figuers = new kaseev::shape *[arraySize];
  size_t counter = 0;

  std::string figureType;
  while (std::cin)
  {
    std::cin >> figureType;
    if (std::cin.eof())
    {
      for (size_t i = 0; i < counter; i++)
      {
        delete figuers[i];
      }
      delete[] figuers;
      return 1;
    }
    if (counter == arraySize)
    {
      arraySize += 10;
      kaseev::shape **newArray = new kaseev::shape *[arraySize];
      std::copy(figuers, figuers + arraySize - 10, newArray);
      for (size_t i = 0; i < (arraySize - 10); i++)
      {
        delete figuers[i];
      }
      delete[] figuers;
      figuers = newArray;
    }

    if (figureType == "RECTANGLE")
    {
      point_t lPoint, rPoint;
      if ((std::cin >> lPoint.x >> lPoint.y >> rPoint.x >> rPoint.y) && (lPoint.x < rPoint.x) && (lPoint.y < rPoint.y))
      {
        figuers[counter++] = new kaseev::Rectangle(lPoint, rPoint);
      } else
      {
        std::cerr << "wrong arguments \n";
      }
    } else if (figureType == "ELLIPSE")
    {
      point_t center;
      double vertRad, gorRad;
      if (std::cin >> center.x >> center.y >> vertRad >> gorRad)
      {
        figuers[counter++] = new kaseev::Ellipce(center, vertRad, gorRad);
      } else
      {
        std::cerr << "wrong arguments \n";
      }
    } else if (figureType == "PARALLELOGRAM")
    {
      point_t A, B, C;
      if ((std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y))
      {
        figuers[counter++] = new kaseev::Parallelogram(A, B, C);
      } else
      {
        std::cerr << "wrong arguments \n";
      }
    }
    // there must be scale...
  }
}
