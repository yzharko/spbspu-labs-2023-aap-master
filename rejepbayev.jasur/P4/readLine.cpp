#include "readLine.hpp"

char* rejepbayev::readLine(std::istream& input, char* str, size_t& userLen)
{
  char c = '\0';
  size_t size = 10;
  size_t read = 0;
  size_t maxlenth = 0;

  while (input >> c)
  {
    if (read == maxlenth)
    {
      str = rejepbayev::AddElem(str, size, read);
      maxlenth += size;
    }
    str[read++] = c;
    if (c == '\n') {
      str[--read] = 0;
      break;
    }
    userLen++;
  }
  return str;
}
