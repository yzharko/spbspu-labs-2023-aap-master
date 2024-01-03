#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <cstddef>
namespace tsomo
{
  class Buffer
  {
    public:
      Buffer(const size_t size);
      void clean();
      size_t getSize();
      char operator[](size_t index);
      bool fillFromCin();
      void print();

    private:
      char* buff_;
      size_t size_;
  };
}

#endif
