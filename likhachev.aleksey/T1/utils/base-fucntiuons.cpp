#include "base-fucntiuons.hpp"

double likhachev::strtod(const std::string& str)
{
  double result = 0.0;
  int integerPart = 0;
  int decimalPart = 0;
  double divisor = 1.0;
  bool isNegative = false;
  bool hasDecimal = false;
  int size = str.size();

  int i = 0;
  if (str[0] == '-') {
    isNegative = true;
    i = 1;
  }

  for (; i < size; ++i) {
    if (str[i] == '.') {
      hasDecimal = true;
      break;
    }
    int digit = chartonum(str[i]);
    if (str[i] != '0' && digit == 0) {
      throw std::logic_error("The passed string is not a double!");
    }
    integerPart = integerPart * 10 + digit;
  }

  if (hasDecimal) {
    for (++i; i < size; ++i) {
      int digit = chartonum(str[i]);
      if (str[i] != '0' && digit == 0) {
        throw std::logic_error("The passed string is not a double!");
      }
      decimalPart = decimalPart * 10 + digit;
      divisor *= 10.0;
    }
  }

  result = integerPart + (decimalPart) / divisor;
  if (isNegative) {
    result = -result;
  }

  return result;
}

int likhachev::chartonum(const char chr)
{
  if (chr == '0') {
    return 0;
  }
  if (chr == '1') {
    return 1;
  }
  if (chr == '2') {
    return 2;
  }
  if (chr == '3') {
    return 3;
  }
  if (chr == '4') {
    return 4;
  }
  if (chr == '5') {
    return 5;
  }
  if (chr == '6') {
    return 6;
  }
  if (chr == '7') {
    return 7;
  }
  if (chr == '8') {
    return 8;
  }
  if (chr == '9') {
    return 9;
  }

return 0;
}
