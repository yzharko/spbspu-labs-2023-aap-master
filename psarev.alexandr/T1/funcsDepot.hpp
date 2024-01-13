#ifndef FUNCS_DEPOT_HPP
#define FUNCS_DEPOT_HPP
#include "base-types.hpp"
#include "rectangle.hpp"
#include <vector>
#include <iostream>

namespace psarev
{
  bool rectDataRework(std::istream& input, std::vector<double>& data, std::vector<char>& queue);
  bool ringDataRework(std::istream& input, std::vector<double>& data, std::vector<char>& queue);
  bool triDataRework(std::istream& input, std::vector<double>& data, std::vector<char>& queue);
  bool triDataRework(std::istream& input, std::vector<double>& data, std::vector<char>& queue);
  void fillData(std::vector<double>& framesData, psarev::rectangle_t& frame);
  void modify(point_t& sCen, double& k, Shape& figure, rectangle_t& frame);
}

#endif
