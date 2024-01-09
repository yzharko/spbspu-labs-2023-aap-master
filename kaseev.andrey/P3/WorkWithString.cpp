#include "WorkWithString.hpp"
#include <iostream>
#include <cstring>

const char *kaseev::readLine()
{
  const int initialSize = 10;
  int currentSize = initialSize;
  char* charArray = new char[currentSize];
  if (charArray == nullptr)
  {
    std::cerr << "Memory error";
    return nullptr;
  }
  int c;
  int index = 0;
  while ((c = std::getchar()) != '\n' && c != EOF)
  {
    charArray[index++] = static_cast<char>(c);
    if (index == currentSize - 1)
    {
      currentSize *= 2;
      char* tempArray = new char[currentSize];
      if (tempArray == nullptr)
      {
        std::cerr << "Memory erorr";
        delete[] charArray;
        return nullptr;
      }
      std::copy(charArray, charArray + index, tempArray);
      delete[] charArray;
      charArray = tempArray;
    }
  }
  charArray[index] = '\0';
  return charArray;
}

char* kaseev::interleaveStrings(const char* str1,const char* str2)
{
  if (str1 == nullptr)
  {
    return nullptr;
  }
  size_t len1 = kaseev::lent(str1);
  size_t len2 = 4;
  size_t newLen = len1 + len2 + 1;
  size_t t = 0;
  if (newLen <= 1)
  {
    return nullptr;
  }
  char *newStr = new(std::nothrow) char[newLen];
  if (newStr == nullptr)
  {
    return nullptr;
  }
  for (size_t i = 0; i < std::min(len1, len2); ++i)
  {
    newStr[t++] = str1[i];
    newStr[t++] = str2[i];
  }
  if (len1 < len2)
  {
    strcpy(newStr + t, str2 + len1);
  }
  else if (len1 > len2)
  {
    strcpy(newStr + t, str1 + len2);
  }
  else
  {
    newStr[t] = '\0';
  }
  return newStr;
}

size_t kaseev::lent(const char* str1)
{
  size_t len = 0;
  while (str1[len] != '\0')
  {
    len++;
  }
  return len;
}
