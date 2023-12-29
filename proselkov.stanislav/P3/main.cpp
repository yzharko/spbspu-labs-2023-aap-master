#include <iostream>
#include <iomanip>
#include <cstddef>
#include <cctype>
#include <string>
#include "readLine.hpp"
#include "DgtSnd.hpp"

int main()
{
  const char input2[10]{"g1h2k"};
  int read2 = 6;
  try
  {
    char * input1 = new char[10]{};
    int read1 = readLine(input1);
    char output[read1 + read2] = {};
    DgtSnd(input1, input2, output, read1, read2);
    std::cout << output << "\n";

    delete[] input1;
    delete input2;
    delete[] output;
    return 0;
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
