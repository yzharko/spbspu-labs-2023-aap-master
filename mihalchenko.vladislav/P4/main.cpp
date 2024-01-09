#include <iostream>
#include <fstream>
#include <cmath>
#include <ctype.h>
#include "matrix.hpp"
#include "inputArray.hpp"
#include "outputArray.hpp"
#include "dopFunc.hpp"

int main(int argc, char** argv)

{
  using namespace mihalchenko;
  if ((argc < 4) || (argc > 4))
  {
    (argc < 4) ? (std::cerr << "Not enough arguments\n") : ( std::cerr << "Too many arguments\n");
    return 1;
  }

  if (isdigit(*argv[1]) != true)
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }

  if ((*argv[1] != '1') && (*argv[1] != '2'))
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  int num = 0;

  try
  {
    if (ifAlp(argv[1]) == true)
    {
      num = std::stoll(argv[1]);
    }
    else
    {
      std::cout << "It's not a digit\n";
      return 1;
    }
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Cannot parse a value!!!!";
    return 1;
  }

  std::ifstream input(argv[2]);
  size_t rows = 0, cols = 0;

  input >> rows >> cols;
  {
    if (!input)
    {
      std::cerr << "Cannot read an input.\n";
      return 2;
    }
  }

  if ((rows == 0) && (cols == 0))
  {
    std::ofstream output(argv[3]);
    output << rows << " " << cols << " ";
    return 0;
  }

  if (((rows == 0) || (cols == 0)) && (!((rows == 0) && (cols == 0))))
  {
    std::cout << "Cannot be an element\n";
    return 1;
  }

  size_t prod = rows * cols;

  if (num == 1)
  {
    if (prod > 10000)
    {
      std::cerr << "The number of matrix elements exceeds 10000";
      return 1;
    }

    float masInput[prod];
    size_t result = inputArray(input, masInput, prod);

    if (!input)
    {
      std::cerr << "Read " << result << " elements...\n";
      return 2;
    }
    outputDinArray(argv[3], masInput, rows, cols);
    return 0;
  }

  if (num == 2)
  {
    float* m1 = nullptr;
    try
    {
      m1 = createMatrix(m1, rows, cols);
      if (m1 == nullptr)
      {
        return 2;
      }
    }
    catch(...)
    {
      freeMatrix(m1);
      return 2;
    }

    for (size_t i = 0; i < prod; i++)
    {
      if (!(input >> m1[i]))
      {
        freeMatrix(m1);
        return i;
      }
    }
    outputDinArray(argv[3], m1, rows, cols);
    freeMatrix(m1);
    return 0;
  }
  else
  {
    return 2;
  }
}
