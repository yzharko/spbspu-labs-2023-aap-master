#include "funcsDepot.hpp"
#include <cmath>

bool psarev::rectDataRework(std::istream& input, std::vector<double>& data, std::vector<char>& queue)
{
  double coo = 0.0;
  size_t iter = 0;
  bool result = false;
  for (size_t i = 0; i < 4; i++) {
    if (std::cin >> coo) {
      data.push_back(coo);
      iter++;
    } else {
      result = true;
      break;
    }
  }
  if ((iter == 4) && (data[iter - 4] < data[iter - 2]) && (data[iter - 3] < data[iter - 1])) {
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
    if (std::cin >> coo) {
      data.push_back(coo);
      iter++;
    } else {
      result = true;
      break;
    }
  }
  if ((iter == 4) && (data[iter - 1] > 0) && (data[iter - 2] > data[iter - 1])) {
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
    if (std::cin >> coo) {
      data.push_back(coo);
      iter++;
    }
    else {
      result = true;
      break;
    }
  }
  if (iter == 6) {
    double firEdge = (sqrt(pow(data[iter - 4] - data[iter - 6], 2) + pow(data[iter - 3] - data[iter - 5], 2)));
    double secEdge = (sqrt(pow(data[iter - 2] - data[iter - 4], 2) + pow(data[iter - 1] - data[iter - 3], 2)));
    double thirEdge = (sqrt(pow(data[iter - 2] - data[iter - 6], 2) + pow(data[iter - 1] - data[iter - 5], 2)));
    bool result = 0;
    result = (firEdge + secEdge > thirEdge) && (firEdge + thirEdge > secEdge) && (secEdge + secEdge > firEdge);
    if (result) {
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
