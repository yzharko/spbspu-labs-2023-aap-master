#include <iostream>
#include <iomanip>
#include <new>
#include "class.hpp"
#include "func.hpp"

int main()
{
  try
  {
    sobolevsky::Array str1(21);
    char c = 0;
    size_t read1 = 0;
    std::cin >> std::noskipws;
    while (std::cin >> c)
    {
      if ((read1 % 20 == 0) && (read1 > 0))
      {
        sobolevsky::Array str1Help(21 + read1);
        for (size_t i = 0; i < read1; i++)
        {
          str1Help.str[i] = str1.str[i];
        }
        delete[] str1.str;
        str1.str = str1Help.str;
      }
      if (c == '\n')
      {
        break;
      }
      if ((isalpha(c)) || isspace(c))
      {
        str1.str[read1++] = c;
      }
      else
      {
        std::cerr << "вводите только английские буквы или пробел\n";
        return 1;
      }
    }

    sobolevsky::Array str2(21);
    size_t read2 = 0;

    while (std::cin >> c)
    {
      if ((read2 % 20 == 0) && (read2 > 0))
      {
        sobolevsky::Array str2Help(21 + read2);
        for (size_t i = 0; i < read2; i++)
        {
          str2Help.str[i] = str2.str[i];
        }
        delete[] str2.str;
        str2.str = str2Help.str;
      }
      if (c == '\n')
      {
        break;
      }
      if ((isalpha(c)) || isspace(c))
      {
        str1.str[read1++] = c;
      }
      else
      {
        std::cerr << "вводите только английские буквы или пробел\n";
        return 1;
      }
    }
    std::cin >> std::skipws;
    char * uniqArray = new char[(read1 + read2 + 1)];
    sobolevsky::changeString(str1.str, str2.str, uniqArray, read1, read2);

    for (size_t i = 0; i < (read1 + read2 + 1); i++)
    {
      std::cout << uniqArray[i];
    }
    std::cout << "\n";

    delete[] str1.str;
    delete[] str2.str;
    delete[] uniqArray;
    return 0;
  }
  catch(const std::bad_alloc & ba)
  {
    std::cerr << ba.what() << '\n';
    return 1;
  }
}
