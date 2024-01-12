#include "deleteData.hpp"

void shagieva::deleteData(shagieva::Shape ** shapes, const size_t & shapeCount)
{
  for (size_t i = 0; i < shapeCount; ++i)
    {
      delete shapes[i];
    }
  delete[] shapes;
}
