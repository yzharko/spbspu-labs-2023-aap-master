#include <iostream>
#include <iomanip>
#include <cctype>
#include "read_input.hpp"
#include "shr_sym.hpp"
#include "dgt_snd.hpp"

int main()
{
  std::cin >> std::noskipws;
  size_t readStr1 = 0;
  size_t readStr2 = 0;
  char * string1 = new char[25];
  char * string2 = new char[25];
  try
  {
    readStr1 = kovshikov::readInput(string1);
    readStr2 = kovshikov::readInput(string2);
  }
  catch(const std::bad_alloc &e)
  {
    std:: cerr << "Unable to allocate memory\n";
    return 1;
  }
  char outputShrSym[26] = {};
  kovshikov::missingChar(string1, outputShrSym, readStr1);
  char outputDgtSnd[readStr1 + readStr2] = {};
  kovshikov::withDigits(string1, string2, outputDgtSnd, readStr2, readStr1);
  std::cout << outputShrSym << "\n";
  std::cout << outputDgtSnd << "\n";
  std::cin >> std::skipws;
  delete[] string1;
  delete[] string2;
  return 0;
}
