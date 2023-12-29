#include <iostream>
#include "functions.hpp"

int main()
{
  char * stringFRQTOP = new char[10];
  char * stringEXCSND1 = new char[10];
  char * stringEXCSND2 = new char[10];
  try
  {
    int lengthFRQTOP = khoroshkin::inputLine(stringFRQTOP, 10);
    int lengthEXCSND1 = khoroshkin::inputLine(stringEXCSND1, 10);
    int lengthEXCSND2 = khoroshkin::inputLine(stringEXCSND2, 10);
    if (lengthFRQTOP < 3)
    {
      throw std::logic_error("Error: Too short string\n");
    }
    char * resultFRQTOP = khoroshkin::getFrequency(stringFRQTOP, lengthFRQTOP);
    char * resultEXCSND = khoroshkin::generateNewWithTwo(stringEXCSND1, stringEXCSND2, lengthEXCSND1, lengthEXCSND2);
    std::cout << "Result for var FRQ-TOP: " << resultFRQTOP << '\n';
    std::cout << "Result for var EXC-SND: " << resultEXCSND << '\n';
    delete[] resultFRQTOP;
    delete[] resultEXCSND;
    delete[] stringFRQTOP;
    delete[] stringEXCSND1;
    delete[] stringEXCSND2;
    return 0;
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what();
    delete[] stringFRQTOP;
    delete[] stringEXCSND1;
    delete[] stringEXCSND2;
    return 1;
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Error: Cannot allocate memory\n";
    delete[] stringFRQTOP;
    delete[] stringEXCSND1;
    delete[] stringEXCSND2;
    return 1;
  }
}
