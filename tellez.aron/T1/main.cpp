#include <iostream>
#include "base-types.hpp"
#include "readWriteShapes.hpp"
#include "compositeShape.hpp"

using namespace tellez;

int main()
{
  const size_t basicCapacity = 10;
  CompositeShape compositeShape(basicCapacity);
  std::string line;
  scale_t scale = {{0.0, 0.0}, 2.0};
  bool isscale = false;
  Shape * buffer = nullptr;
  while (std::cin)
  {
    std::cin >> line;
    try
    {
      if (line == "RECTANGLE")
      {
        buffer = createRectangle(std::cin);
        compositeShape.push_back(buffer);
        buffer = nullptr;
      }
    }
    catch (const std::logic_error & error)
    {
      std::cerr << error.what() << "\n";
      delete buffer;
    }
    try
    {
      if (line == "RING")
      {
        buffer = createRing(std::cin);
        compositeShape.push_back(buffer);
        buffer = nullptr;
      }
    }
    catch (const std::logic_error & error)
    {
      std::cerr << error.what() << "\n";
      delete buffer;
    }
    try
    {
      if (line == "ELLIPSE")
      {
        buffer = createEllipse(std::cin);
        compositeShape.push_back(buffer);
        buffer = nullptr;
      }
    }
    catch (const std::logic_error & error)
    {
      std::cerr << error.what() << "\n";
      delete buffer;
    }
    try
    {
      if (line == "SCALE")
      {
        try
        {
          scale = getScale(std::cin);
          isscale = true;
        }
        catch (const std::logic_error & error)
        {
          std::cerr << error.what() << "\n";
        }
        break;
      }
    }
    catch (const std::logic_error & error)
    {
      std::cerr << error.what() << "\n";
    }
  }
  if (compositeShape.empty())
  {
    std::cerr << "nothing to scale" << "\n";
    return 1;
  }
  if (!isscale)
  {
    std::cerr << "no scale command" << "\n";
    return 1;
  }
  printAreaPoints(std::cout, compositeShape);
  try
  {
    compositeShape.scale(scale);
  }
  catch (const std::logic_error & error)
  {
    std::cerr << error.what() << "\n";
    return 1;
  }
  printAreaPoints(std::cout, compositeShape);
  return 0;
}
