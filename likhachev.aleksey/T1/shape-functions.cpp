#include "shape-functions.hpp"

void likhachev::coutShapesData(likhachev::Shape **shapes, size_t shapeCount)
{
  double areaSum = 0.0;
  for (size_t i = 0; i < shapeCount; i++) {
    areaSum += shapes[i]->getArea();
  }

  std::cout << areaSum;
  for (size_t i = 0; i < shapeCount; i++) {
    likhachev::rectangle_t frameRect = shapes[i]->getFrameRect();
    likhachev::point_t distance;
    distance.x = frameRect.width / 2;
    distance.y = frameRect.height / 2;
    likhachev::point_t lowerLeft = frameRect.pos - distance;
    likhachev::point_t upperRight = frameRect.pos + distance;
    std::cout << " " << lowerLeft.x << " " << lowerLeft.y << " " << upperRight.x << " " << upperRight.y;
  }
}
