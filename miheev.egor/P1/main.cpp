#include "functions.hpp"
#include "dividing_counter.hpp"
#include <iostream>

int main()
{
  try
  {
    using namespace miheev;
    DevidingCounter dividing_counter(getNumberFromCin());
    dividing_counter.checkFirstPrevious();
    while(dividing_counter.getPrevious() != 0)
    {
      dividing_counter(getNumberFromCin());
    }
    if (!dividing_counter.getIfSeqLongEnough())
    {
      throw std::logic_error("Sequence is too short");
    }
    std::cout << dividing_counter.getCounter()<< '\n';
    return 0;
  }
  catch (const std::invalid_argument& error)
  {
    std::cout << error.what() << '\n';
    return 1;
  }
  catch (const std::logic_error& error)
  {
    std::cout << error.what() << '\n';
    return 2;
  }
}

