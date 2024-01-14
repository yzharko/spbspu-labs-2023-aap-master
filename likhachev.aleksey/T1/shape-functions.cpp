#include "shape-functions.hpp"
#include "base-types.hpp"

void likhachev::coutShapesData(likhachev::Shape **shapes, size_t shapeCount)
{
  double areaSum = 0.0;
  for (size_t i = 0; i < shapeCount; i++) {
    areaSum += shapes[i]->getArea();
  }

  std::cout << areaSum;
  for (size_t i = 0; i < shapeCount; i++) {
    likhachev::rectangle_t frameRect = shapes[i]->getFrameRect();
    double width = frameRect.getWidth();
    double height = frameRect.getHeight();
    likhachev::point_t lowerLeft = frameRect.getPos() - likhachev::point_t(width / 2, height / 2);
    likhachev::point_t upperRight = frameRect.getPos() + likhachev::point_t(width / 2, height / 2);
    std::cout << " " << lowerLeft.x << " " << lowerLeft.y << " " << upperRight.x << " " << upperRight.y;
  }
}
