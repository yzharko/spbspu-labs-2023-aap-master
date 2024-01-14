#include "funcsDepot.hpp"
#include <cmath>
#include <iostream>

double* psarev::increaseArr(double* arr, size_t& arrSize)
{
  double* newArr = new double [arrSize * 2];
  for (size_t i = 0; i < arrSize; i++) {
    newArr[i] = arr[i];
  }
  arrSize *= 2;
  delete[] arr;
  arr = newArr;
  return arr;
}

bool psarev::addRectData(double* data, size_t& dataSize, double* queue, size_t& order)
{
  double llCornerX, llCornerY, urCornerX, urCornerY;
  if (std::cin >> llCornerX >> llCornerY >> urCornerX >> urCornerY) {
    if ((llCornerX < urCornerX) && (llCornerY < urCornerY)) {
      queue[order] = 1;
      order += 1;
      int fl = 0;
      for (size_t i = 0; i < order; i++) {
        if (queue[i] == 1) {
          fl += 1;
        }
      }
      if (fl > 1) {
        data = psarev::increaseArr(data, dataSize);
      }
      data[dataSize - 4] = llCornerX;
      data[dataSize - 3] = llCornerY;
      data[dataSize - 2] = urCornerX;
      data[dataSize - 1] = urCornerY;
      return false;
    } else {
      return true;
    }
  } else {
    return true;
  }
}

bool psarev::addRingData(double* data, size_t& dataSize, double* queue, size_t& order)
{
  double centerX, centerY, extRad, inRad;
  if (std::cin >> centerX >> centerY >> extRad >> inRad) {
    if ((extRad > inRad) && (inRad > 0)) {
      queue[order] = 2;
      order += 1;
      int fl = 0;
      for (size_t i = 0; i < order; i++) {
        if (queue[i] == 2) {
          fl += 1;
        }
      }
      if (fl > 1) {
        data = psarev::increaseArr(data, dataSize);
      }
      data[dataSize - 4] = centerX;
      data[dataSize - 3] = centerY;
      data[dataSize - 2] = extRad;
      data[dataSize - 1] = inRad;
      return false;
    } else {
      return true;
    }
  } else {
    return true;
  }
}

bool psarev::addTriData(double* data, size_t& dataSize, double* queue, size_t& order)
{
  double firCornerX, firCornerY, secCornerX, secCornerY, thiCornerX, thiCornerY;
  if (std::cin >> firCornerX >> firCornerY >> secCornerX >> secCornerY >> thiCornerX >> thiCornerY) {
    double firSide = (sqrt(pow(secCornerX - firCornerX, 2) + pow(secCornerY - firCornerY, 2)));
    double secSide = (sqrt(pow(thiCornerX - secCornerX, 2) + pow(thiCornerY - secCornerY, 2)));
    double thirSide = (sqrt(pow(thiCornerX - firCornerX, 2) + pow(thiCornerY - firCornerY, 2)));
    bool rightTri = 0;
    double maxSide = fmax(firSide, secSide);
    maxSide = fmax(maxSide, thirSide);
    rightTri = (maxSide < (firSide + secSide + thirSide - maxSide));
    if (rightTri) {
      queue[order] = 3;
      order += 1;
      int fl = 0;
      for (size_t i = 0; i < order; i++) {
        if (queue[i] == 3) {
          fl += 1;
        }
      }
      if (fl > 1) {
        data = psarev::increaseArr(data, dataSize);
      }
      data[dataSize - 6] = firCornerX;
      data[dataSize - 5] = firCornerY;
      data[dataSize - 4] = secCornerX;
      data[dataSize - 3] = secCornerY;
      data[dataSize - 2] = thiCornerX;
      data[dataSize - 1] = thiCornerY;
      return false;
    } else {
      return true;
    }
  } else {
    return true;
  }
}

void psarev::fillData(double* framesData, rectangle_t& frame, const size_t& order)
{
  framesData[order - 4] = frame.pos.x - (frame.width / 2);
  framesData[order - 3] = frame.pos.y - (frame.height / 2);
  framesData[order - 2] = frame.pos.x + (frame.width / 2);
  framesData[order - 1] = frame.pos.y + (frame.height / 2);
}

void psarev::modify(point_t& scaleCenter, const double& coef, Shape& figure, rectangle_t& frame)
{
  figure.move({ scaleCenter.x, scaleCenter.y });
  rectangle_t newFrame = figure.getFrameRect();
  point_t newPos;
  newPos.x = fabs(frame.pos.x - newFrame.pos.x) * coef;
  newPos.y = fabs(frame.pos.y - newFrame.pos.y) * coef;
  figure.scale(coef);
  figure.move(newPos.x, newPos.y);
  frame = figure.getFrameRect();
}
