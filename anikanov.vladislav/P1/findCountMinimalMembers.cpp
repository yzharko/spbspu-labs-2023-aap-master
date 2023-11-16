#include "findCountMinimalMembers.hpp"
#include <iostream>
#include <limits>

long long findCountMinimalMembers(std::istream &cin)
{
  const long long max_count = std::numeric_limits< long long >::max();
  long long count = 0;
  long long min_member = max_count;
  long long number;
  if (!(cin >> number)) {
    throw std::invalid_argument("Wrong input");
  }
  while (number != 0) {
    if (number <= min_member) {
      count = number == min_member ? count + 1 : 1;
      min_member = std::min(min_member, number);
    }
    if (count < 0) {
      throw std::overflow_error("To much minimal numbers");
    }
    if (!(cin >> number)) throw std::invalid_argument("Wrong input");
  }
  return count;
}
