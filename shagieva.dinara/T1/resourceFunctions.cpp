#include "resourceFunctions.hpp"

void shagieva::increaseResource(shagieva::Shape ** shapes, size_t & capacity, const size_t & shapeCount)
{
  capacity *= 2;
  shagieva::Shape ** newShapes = new shagieva::Shape * [capacity];
  for (size_t i = 0; i < shapeCount; ++i)
  {
    newShapes[i] = shapes[i];
    delete[] shapes[i];
  }
  delete[] shapes;
  shapes = newShapes;
}

void shagieva::clearResource(shagieva::Shape ** shapes, const size_t & shapeCount)
{
  for (size_t i = 0; i < shapeCount; ++i)
    {
      delete shapes[i];
    }
  delete[] shapes;
}
