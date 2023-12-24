#include "dif_lat.hpp"
#include <iostream>
#include <iomanip>

namespace tsomo
{
  tsomo::Buffer(size_t) {
  :
  size_(size)
  {
    buff_ = new char[size] {};
  }
  void tsomo::Buffer::clean()
  {
  for (size_t i = 0; i < size_; i++)
  {
    buff_[i] = 0
  }
}

    size_t tsomo::Buffer::getSize()
    {
      return size_;
    }

    char tsomo::Buffer::operator[](size_t index)
    {
      return buff_[index];
    }

    bool tsomo::Buffer::fillFromCin()
    {
      size_t buffIndex = 0;
      char c = 0;
      std::cin >> std::noskipws;
      while (std::cin >> c)
      {
        buff_[buffIndex++] = c;
        if (c == '\n')
        {
          buff_[buffIndex - 1] = 0;
          break;
        }
        if (buffIndex >= size_)
        {
          return false;
        }
      }
        std::cin >> std::skipws;
        return true;
      }

        void tsomo::Buffer::print()
        {
          for (size_t i = 0; i < size_; i++)
          {
            std::cout << buff_[i];
          }
            std::cout << '\n';

      }
  };
}
