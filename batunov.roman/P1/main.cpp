#include <iostream>

int main()
{
  int last, value, count = 1, max_count = 1;
  std::cout << "Enter a sequence of numbers.\n";
  std::cin >> value;
  last = value + 1;
  if (value == 0)
  {
    std::cout << "The maximum number of consecutive equal elements: 0.\n";
  }
  else
  {
    while (value != 0)
    {
      if (value == last)
      {
        count += 1;
      }
      else
      {
        count = 1;
      }
      if (count > max_count)
      {
        max_count = count;
      }
      last = value;
      std::cin >> value;
    }
    std::cout << "The maximum number of consecutive equal elements: " << max_count << ".\n";
    return 0;
  }
}