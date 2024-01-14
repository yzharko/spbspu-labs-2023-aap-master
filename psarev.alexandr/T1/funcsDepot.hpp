#ifndef FUNCS_DEPOT_HPP
#define FUNCS_DEPOT_HPP
#include "shape.hpp"
#include "base-types.hpp"
#include <cstddef>

namespace psarev
{
  double* increaseArr(double* arr, size_t& arrSize);
  bool addRectData(double* data, size_t& dataSize, double* queue, size_t& order);
  bool addRingData(double* data, size_t& dataSize, double* queue, size_t& order);
  bool addTriData(double* data, size_t& dataSize, double* queue, size_t& order);
  void fillData(double* framesData, psarev::rectangle_t& frame, const size_t& order);
  void modify(point_t& sCen, const double& k, Shape& figure, rectangle_t& frame);
}

#endif
