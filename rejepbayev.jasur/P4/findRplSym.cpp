#include "findRplSym.hpp"
#include "formingString.hpp"

char* rejepbayev::findRplSym(const char* string, int size, int newSize, char simbolOld, char simbolNew)
{
  char* resultString = new char[size + 1];
  int sizeNum = 0;
  while (string[sizeNum] != '\0')
  {
    if (size == sizeNum)
    {
      char* newString = rejepbayev::formingString(resultString, sizeNum, newSize);
      delete[] resultString;
      resultString = newString;
      size += newSize;
    }
    resultString[sizeNum] = (string[sizeNum] == simbolOld ? simbolNew : string[sizeNum]);
    ++sizeNum;
  }
  resultString[sizeNum] = '\0';
  return resultString;
}
