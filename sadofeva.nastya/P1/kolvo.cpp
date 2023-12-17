#include "kolvo.h"

int kolvo(int & number, int & lastnumber, int & count, int & result)
{
  if (count != 0)
  {
    if (number % lastnumber == 0)
    {
      result++;
    }
  }
  lastnumber = number;
  return 0;
}
