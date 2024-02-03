#include "iostream"
#include "kolvo.h"

int main()
{
  int count = 0 ;
  int number = 0;
  int lastnumber = 0;
  int result = 0;

  while (true)
  {
    try
    {
      std::cin >> number;
      if (std::cin.fail())
      {
        return 2;
      }
      else if (number == 0)
      {
        break;
      }
      else
      {
        kolvo(number,lastnumber,count,result);
        count++;
      }
    }
    catch (std::exception & ex)
    {
      std::cout << ex.what() << "\n";
    }
  }
  if (count > 1)
  {
    std::cout << result << "\n";
  }
  else
  {
    std::cout << "The sequence is too small" << "\n";
  }
}
