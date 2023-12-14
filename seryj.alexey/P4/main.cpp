#include <iostream>
#include <fstream>
#include <string>
#include "fillArray.hpp"
#include "smoothedMatrix.hpp"
int main(int args, const char* argv[])
{
  int task = 0;
  try
  {
    task = std::stoi(argv[1], nullptr, 10);
    if(argv[1][1])
    {
      std::cerr << "First argument is wrong\n";
      return 1;
    }
  }
  catch (std::logic_error const& e)
  {
    std::cerr << "First argument is not a number\n";
    return 1;
  }
  if (args != 4 || !(task == 2 || task == 1))
  {
   std::cerr << "Invalid arguments\n";
   return 1;
  }
  int line = 0;
  int column = 0;
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  if (!input.is_open() || !output.is_open()) {
    std::cerr << "Wrong path to file\n";
    return 1;
  }
  if (!(input >> line) || !(input >> column)) {
    std::cerr << "Wrong sizes\n";
    return 2;
  }
  size_t to_read = line * column;
  const size_t max_size = 10000;
  int first_task_array [max_size] = { 0 };
  int * values = (task == 1) ? first_task_array : new int[to_read];
  size_t result = seryj::fillArray ((task == 1) ? max_size : to_read, to_read, input, values);
  if (result != to_read)
  {
    std::cerr << "Could only read " << result << " numbers. I needed " << to_read << "\n";
    if (task == 2)
      delete[] values;
    return 1;
  }
  seryj::printAvgOfNeigbours(line, column, output, values);
  if (task == 2)
    delete[] values;
  return 0;
}
