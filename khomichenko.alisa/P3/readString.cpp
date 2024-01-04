#include "readString.hpp"

void khomichenko::swapStrings ( char * first, char * second, int size)
{
  for (int i = 0; i < size;  i++)
  {
    second[i] = first[i];
  }
}

char * khomichenko::createBiggerString (int * size, char * first)
{
  char * secondInput = new char [(*size) + (*size)] {};
  swapStrings(first, secondInput, (*size));
  (*size) += (*size);
  delete [] first;
  first = new char [(*size)] {};
  swapStrings(secondInput, first, (*size));
  delete [] secondInput;
  return first;
}
