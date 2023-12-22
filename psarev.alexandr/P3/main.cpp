#include "readLine.hpp"
#include "createLine.hpp"
#include "expandLine.hpp"

int main()
{
  size_t maxElemNum = 10;
  size_t extSize = 10;
  const char* presetLine = "abc ef";
  char* userLine = psarev::readLine(std::cin, extSize, maxElemNum);

  size_t presetLen = strlen(presetLine);
  size_t userLen = strlen(userLine);

  if (userLen == 0) {
    std::cerr << "Error: Not enough values or memory to allocate!\n";
    delete[] userLine;
    return 1;
  }

  char* resLine = psarev::createTaskLine(userLine, presetLine, userLen, presetLen);
  size_t resLen = strlen(resLine);

  delete[] userLine;

  for (size_t i = 0; i < resLen; i++) {
    std::cout << resLine[i];
  }
  std::cout << '\n';
  delete[] resLine;
  return 0;
}
