#include "createLine.hpp"
#include "expandLine.hpp"

char* psarev::createTaskLine(char* userLine, const char* presetLine, size_t userLen, const size_t presetLen)
{
  size_t elemNum = 0;
  size_t maxElemNum = 10;
  size_t extSize = 10;
  char* resLine = new char[maxElemNum] {};
  for (size_t i = 0; i < presetLen; i++) {
    if ((std::strchr(userLine, presetLine[i]) == NULL) && (std::strchr(resLine, presetLine[i]) == NULL)) {
      resLine[elemNum++] = presetLine[i];
    }
  }

  for (size_t j = 0; j < userLen; j++) {
    if ((std::strchr(presetLine, userLine[j]) == NULL) && (std::strchr(resLine, userLine[j]) == NULL)) {
      resLine[elemNum++] = userLine[j];
      if (elemNum == maxElemNum) {
        char* expandedLine = expandLine(resLine, elemNum, extSize);
        delete[] resLine;
        resLine = expandedLine;
        maxElemNum += extSize;
      }
    }
  }
  return resLine;
}
