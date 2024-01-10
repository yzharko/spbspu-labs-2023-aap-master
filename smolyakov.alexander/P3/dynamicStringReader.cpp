#include "dynamicStringReader.hpp"
#include <stddef.h>

cringecode::DynamicStringReader::DynamicStringReader(int bufferIncrement)
{
  buffer_ = new char[bufferIncrement + 1];
  length_ = 0;
  maxLength_ = bufferIncrement;
  bufferIncrement_ = bufferIncrement;
}

cringecode::DynamicStringReader::~DynamicStringReader()
{
  delete[] buffer_;
}

char* cringecode::DynamicStringReader::read(std::istream& stream)
{
  char currentCharacter;
  stream >> std::noskipws;
  while (stream >> currentCharacter && currentCharacter != '\n')
  {
    if (length_ == maxLength_)
    {
      increaseBufferSize();
    }
    buffer_[length_] = currentCharacter;
    length_++;
  }

  buffer_[length_] = '\0';
  return buffer_;
}

std::size_t cringecode::DynamicStringReader::getLength() const
{
  return length_;
}

void cringecode::DynamicStringReader::increaseBufferSize()
{
  maxLength_ += bufferIncrement_;
  char* newBuffer = new char[maxLength_ + 1];
  for (size_t i = 0; i < length_; i++)
  {
    newBuffer[i] = buffer_[i];
  }
  delete[] buffer_;
  buffer_ = newBuffer;
}
