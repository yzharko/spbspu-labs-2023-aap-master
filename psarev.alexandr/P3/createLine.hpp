#ifndef CREATE_LINE_HPP
#define CREATE_LINE_HPP
#include <cstring>

namespace psarev
{
  char* createTaskLine(char* userLine, const char* presetLine, size_t userLen, const size_t presetLen);
};
#endif
