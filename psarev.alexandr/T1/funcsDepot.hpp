#ifndef FUNCS_DEPOT_HPP
#define FUNCS_DEPOT_HPP
#include <vector>
#include <iostream>

namespace psarev
{
  bool rectDataRework(std::istream& input, std::vector<double>& data, std::vector<char>& queue);
  bool ringDataRework(std::istream& input, std::vector<double>& data, std::vector<char>& queue);
  bool triDataRework(std::istream& input, std::vector<double>& data, std::vector<char>& queue);
}

#endif
