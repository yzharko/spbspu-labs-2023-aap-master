#include <iostream>
#include <exception>
#include <limits>
#include "funcs.h"

int main()
{
  int first_elem = 0;
  int second_elem = 0;
  int third_elem = 0;
  int forth_elem = 0;
  int cou = 0;
  try
  {
    forth_elem = susidko::read(first_elem);
    while (forth_elem != 0)
    {
      if ((forth_elem == susidko::sum(second_elem, third_elem)) && (second_elem != 0))
      {
        cou += 1;
      }
      first_elem = second_elem;
      second_elem = third_elem;
      third_elem = forth_elem;
      forth_elem = susidko::read(first_elem);
    }
    std::cout << cou << "\n";
    return 0;
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what();
    return 2;
  }
  catch (const std::istream::failure & e)
  {
    std::cerr << "Not a sequence";
    return 1;
  }
  catch (const std::overflow_error & e)
  {
    std::cerr << e.what();
    return 1;
  }
}

