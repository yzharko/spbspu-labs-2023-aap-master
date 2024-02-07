#ifndef DYNAMIC_STRING_READER_HPP
#define DYNAMIC_STRING_READER_HPP
#include <cstddef>
#include <istream>

namespace cringecode
{
  class DynamicStringReader
  {
  public:
    DynamicStringReader(int bufferIncrement);
    ~DynamicStringReader();
    char* read(std::istream& stream);
    std::size_t getLength() const;
  private:
    char* buffer_;
    std::size_t bufferIncrement_;
    std::size_t length_;
    std::size_t maxLength_;
    void increaseBufferSize();
  };
}

#endif
