#include <iostream>
#include "RMVVOW.h"
#include "REPDGT.h"
#include "input.h"

int main()
{
  char *line_p = nullptr;
  char *answerRMVVOW_p = nullptr;
  size_t n = 2;
  try {
    char *line = new char[n]{'\0', '\0'};
    line_p = line;
    n = input(std::cin, line, n);
    if (std::strlen(line) == 0){
      delete[] line;
      std::cerr << "invalid input\n";
      return 1;
    }
    char *answerRMVVOW = new char[n];
    answerRMVVOW_p = answerRMVVOW;
    dropVowels(answerRMVVOW, line);
    print(std::cout, answerRMVVOW, n);
    std::cout << "\n";
    delete[] answerRMVVOW;
    answerRMVVOW_p = nullptr;
    std::cout << hasDuplicateDigits(line) << "\n";
    delete[] line;
    line_p = nullptr;
  } catch (const std::exception &ex) {
    if (line_p != nullptr){
      delete[] line_p;
    }
    if (answerRMVVOW_p != nullptr){
      delete[] line_p;
    }
    line_p = nullptr;
    answerRMVVOW_p = nullptr;
    std::cerr << ex.what() << "\n";
    return 1;
  }
}
