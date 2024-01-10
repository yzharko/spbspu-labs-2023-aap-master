#include "myStruct.hpp"
#include <iostream>
#include <cstring>
#include <cmath>

extern size_t countGlobal;

mihalchenko::DinString::DinString(size_t n, char c)
{
  this->dinstr = new char[n + 1];

  for (size_t i = 0; i < n; i++)
  {
    this->dinstr[i] = c;
  }
  this->dinstr[n] = '\0';
  size = n;
  counterCurrent = 0;
  addArr = 1;
}

mihalchenko::DinString::~DinString()
{
  delete[] dinstr;
}

void mihalchenko::DinString::dinResize()
{
  char *tmp = new char[size + addArr];
  char *newInput = new char[size + addArr];
  for (size_t i = 0; i < size; i++)
  {
    newInput[i] = dinstr[i];
  }
  size = size + addArr;
  delete[] dinstr;
  dinstr = newInput;
}

void mihalchenko::DinString::dinAppend(char elem)
{
  dinstr[counterCurrent++] = elem;
}

void mihalchenko::DinString::dinOutput()
{
  std::cout << "Введена строка:" << std::endl;
  for (size_t i = 0; i < size; i++)
  {
    std::cout << dinstr[i] << " ";
  }
  std::cout << std::endl;
}

size_t mihalchenko::findString(char *str1, char *str2, size_t size1, size_t size2)
{
  if (size1 >= size2)
  {
    return 1;
  }
  size_t revers = 0;
  for (size_t i = 0; i < size1; i++)
  {
    if (str1[i] == str2[i])
    {
      revers++;
    }
  }
  if (revers == size1)
  {
    return 0;
  }
  return 3;
}

size_t mihalchenko::stringAnalyz(char *strInput, size_t sizeStrInput)
{
  char wremStr1[] = "SQUARE";
  char *find_str = nullptr;
  find_str = new char[std::strlen(wremStr1)];
  for (size_t i = 0; i < strlen(wremStr1); i++)
  {
    find_str[i] = wremStr1[i];
  }
  size_t res = mihalchenko::findString(find_str, strInput, std::strlen(wremStr1), sizeStrInput);
  if (res == 0)
  {
    std::cout << "Ввели SQUARE" << std::endl;
    delete[] find_str;
    return 1;
  }
  char wremStr2[] = "POLIGON";
  find_str = new char[std::strlen(wremStr2)];
  for (size_t i = 0; i < strlen(wremStr2); i++)
  {
    find_str[i] = wremStr2[i];
  }
  res = mihalchenko::findString(find_str, strInput, std::strlen(wremStr2), sizeStrInput);
  if (res == 0)
  {
    std::cout << "Ввели POLIGON" << std::endl;

    delete[] find_str;
    return 2;
  }
  char wremStr3[] = "RECTANGLE";
  find_str = new char[std::strlen(wremStr3)];
  for (size_t i = 0; i < strlen(wremStr3); i++)
  {
    find_str[i] = wremStr3[i];
  }
  res = mihalchenko::findString(find_str, strInput, std::strlen(wremStr3), sizeStrInput);
  if (res == 0)
  {
    std::cout << "Ввели RECTANGLE" << std::endl;
    delete[] find_str;
    return 3;
  }
  char wremStr4[] = "SCALE";
  find_str = new char[std::strlen(wremStr4)];
  for (size_t i = 0; i < strlen(wremStr4); i++)
  {
    find_str[i] = wremStr4[i];
  }
  res = mihalchenko::findString(find_str, strInput, std::strlen(wremStr4), sizeStrInput);
  if (res == 0)
  {
    std::cout << "Ввели SCALE" << std::endl;

    delete[] find_str;
    return 4;
  }
  std::cout << "Ввели некорректную строку" << std::endl;
  return 0;
}
