#include <iostream>
#include <cstddef>
#include "functions.hpp"

int main()
{
  try
  {
    char *str1 = new char[1000];
    size_t len1 = zheleznyakov::readLine(str1);
    if (len1 < 2)
    {
      std::cerr << "Empty string provided; exiting\n";
      delete[] str1;
      return 1;
    }
    const char *str2 = "abc ef";
    size_t len2 = 6;
    char *nonDuplicateDest = new char[1000];
    size_t nonDuplicateDestSize = zheleznyakov::findNonDuplicateChars(nonDuplicateDest, str1, str2, len1, len2);
    for (size_t i = 0; i < nonDuplicateDestSize; i++)
    {
      std::cout << nonDuplicateDest[i];
    }
    std::cout << '\n';
    delete[] nonDuplicateDest;
    char *removeLettersDest = new char[1000];
    size_t removeLettersDestSize = zheleznyakov::removeLetters(removeLettersDest, str1, len1);
    for (size_t i = 0; i < removeLettersDestSize; i++)
    {
      std::cout << removeLettersDest[i];
    }
    std::cout << '\n';
    delete[] removeLettersDest;
    delete[] str1;
    return 0;
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
