#include "readingString.hpp"
#include "formingString.hpp"

char * rejepbayev::readingString(std::istream& input, int size, int newSize)
{
  char* string = new char[size];
  int sizeNum = 0;
  input >> std::noskipws;
  do
  {
    if (size == sizeNum)
    {
      try
      {
        char * newString = rejepbayev::formingString(string, sizeNum, newSize);
        delete[] string;
        string = newString;
        size += newSize;
      }
      catch(const std::exception& e)
      {
        delete[] string;
        throw std::logic_error("Error forming string, couldn't reed the string.");
      }
    }
  }
  while ((input >> string[sizeNum] ) && (string[sizeNum++] != '\n'));
  string[sizeNum != 0 ? sizeNum - 1 : sizeNum] = '\0';
  if (string[0] == '\0')
  {
    delete[] string;
    throw std::logic_error("Error: nothing was entered, an empty input");
  }
  input >> std::skipws;
  return string;
}
