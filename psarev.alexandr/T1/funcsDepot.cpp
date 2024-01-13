#include "funcsDepot.hpp"
#include <cmath>

using namespace psarev;

bool psarev::rectDataRework(std::istream& input, std::vector<double>& data, std::vector<char>& queue)
{
  double coo = 0.0;
  size_t iter = 0;
  bool result = false;
  for (size_t i = 0; i < 4; i++) {
    if (input >> coo) {
      data.push_back(coo);
      iter++;
    } else {
      result = true;
      break;
    }
  }
  if ((iter == 4) && (data[data.size() - 4] < data[data.size() - 2]) && (data[data.size() - 3] < data[data.size() - 1])) {
    queue.push_back('r');
  } else {
    for (size_t i = 0; i < iter; i++) {
      data.pop_back();
    }
    result = true;
  }
  return result;
}

bool psarev::ringDataRework(std::istream& input, std::vector<double>& data, std::vector<char>& queue)
{
  double coo = 0.0;
  size_t iter = 0;
  bool result = false;
  for (size_t i = 0; i < 4; i++) {
    if (input >> coo) {
      data.push_back(coo);
      iter++;
    } else {
      result = true;
      break;
    }
  }
  if ((iter == 4) && (data[data.size() - 1] > 0) && (data[data.size() - 2] > data[data.size() - 1])) {
    queue.push_back('i');
  } else {
    for (size_t i = 0; i < iter; i++) {
      data.pop_back();
    }
    result = true;
  }
  return result;
}

bool psarev::triDataRework(std::istream& input, std::vector<double>& data, std::vector<char>& queue)
{
  double coo = 0.0;
  size_t iter = 0;
  bool result = false;
  for (size_t i = 0; i < 6; i++) {
    if (input >> coo) {
      data.push_back(coo);
      iter++;
    }
    else {
      result = true;
      break;
    }
  }
  if (iter == 6) {
    double firSide = (sqrt(pow(data[data.size() - 4] - data[data.size() - 6], 2) + pow(data[data.size() - 3] - data[data.size() - 5], 2)));
    double secSide = (sqrt(pow(data[data.size() - 2] - data[data.size() - 4], 2) + pow(data[data.size() - 1] - data[data.size() - 3], 2)));
    double thirSide = (sqrt(pow(data[data.size() - 2] - data[data.size() - 6], 2) + pow(data[data.size() - 1] - data[data.size() - 5], 2)));
    bool rightTri = 0;
    double maxSide = fmax(firSide, secSide);
    maxSide = fmax(maxSide, thirSide);
    rightTri = (maxSide < (firSide + secSide + thirSide - maxSide));
    if (rightTri) {
      queue.push_back('t');
    } else {
      for (size_t i = 0; i < iter; i++) {
        data.pop_back();
      }
      result = true;
    }
  } else {
    for (size_t i = 0; i < iter; i++) {
      data.pop_back();
    }
    result = true;
  }
  return result;
}

void psarev::fillData(std::vector<double>& framesData, rectangle_t& frame)
{
  framesData.push_back(frame.pos.x - (frame.width / 2));
  framesData.push_back(frame.pos.y - (frame.height / 2));
  framesData.push_back(frame.pos.x + (frame.width / 2));
  framesData.push_back(frame.pos.y + (frame.height / 2));
}

void psarev::modify(point_t& scaleCenter, double& coef, Shape& figure, rectangle_t& frame)
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
