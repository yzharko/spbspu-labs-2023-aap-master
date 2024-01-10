#include "dinString.hpp"
#include <iostream>
#include <cstring>
#include <cmath>

mihalchenko::DinString::DinString(size_t n)
{
  this->dinstr_ = new char[n + 1];

  for (size_t i = 0; i <= n; i++)
  {
    this->dinstr_[i] = '\0';
  }
  size_ = n;
  counterCurrent_ = 0;
  addArr_ = 2;
}

mihalchenko::DinString::~DinString()
{
  delete[] dinstr_;
}

void mihalchenko::DinString::dinResize()
{
  char *newInput = new char[size_ * addArr_];
  for (size_t i = 0; i < size_; i++)
  {
    newInput[i] = dinstr_[i];
  }
  for (size_t i = size_; i < size_ * addArr_; i++)
  {
    newInput[i] = '\0';
  }
  size_ = size_ * addArr_;
  if (dinstr_ != nullptr)
  {
    delete[] dinstr_;
  }
  dinstr_ = newInput;
}

void mihalchenko::DinString::dinAppend(char elem)
{
  dinstr_[counterCurrent_++] = elem;
}

size_t mihalchenko::DinString::getSize()
{
  return size_;
}

size_t mihalchenko::DinString::getCounterCurrent()
{
  return counterCurrent_;
}

char *mihalchenko::DinString::getDinstr()
{
  return dinstr_;
}

size_t mihalchenko::findIdenticalChars(char *str1, char *str2, size_t size1, size_t size2, char *resStr)
{
  size_t countLen = 0;

  countLen = 0;
  if (size1 > size2)
  {
    for (size_t i = 0; i < size2; i++)
    {
      if ((std::strchr(str1, str2[i]) != 0) && (str2[i] != '\0'))
      {
        resStr[countLen++] = str2[i];
      }
    }
  }
  else
  {
    for (size_t i = 0; i < size1; i++)
    {
      if ((std::strchr(str2, str1[i]) != 0) && (str1[i] != '\0'))
      {
        resStr[countLen++] = str1[i];
      }
    }
  }

  char *newTwoInOne = new char[countLen];
  for (size_t i = 0; i < countLen; i++)
  {
    newTwoInOne[i] = resStr[i];
  }

  newTwoInOne = arrUniq(newTwoInOne, countLen);

  size_t counter = 0;
  while ((newTwoInOne[counter] != '\0') && (counter < countLen))
  {
    counter++;
  }

  char *itogUniq = new char[counter];
  size_t counterItog = 0;

  for (size_t i = 0; i < countLen; i++)
  {
    for (size_t j = 0; j < counter; j++)
    {
      if (resStr[i] == newTwoInOne[j])
      {
        itogUniq[counterItog++] = resStr[i];
        newTwoInOne[j] = '\0';
      }
    }
  }
  for (size_t i = 0; i < counterItog; i++)
  {
    resStr[i] = itogUniq[i];
  }

  if (newTwoInOne != nullptr)
  {
    delete[] newTwoInOne;
  }
  if (itogUniq != nullptr)
  {
    delete[] itogUniq;
  }
  return counterItog;
}

char *mihalchenko::arrUniq(char *mas, size_t size)
{
  for (size_t i = 0; i < size - 1; i++)
  {
    for (size_t j = i + 1; j < size; j++)
    {
      if (i != j)
      {
        if (mas[i] == mas[j])
        {
          while ((mas[j] == mas[size - 1]) && (j < size - 1))
          {
            size--;
          }

          if ((i != size - 1) || (j != size - 1))
          {
            std::swap(mas[size - 1], mas[j]);
            size--;
          }
        }
      }
    }
  }
  char *resultArr = nullptr;
  resultArr = new char[size + 1];
  for (size_t i = 0; i < size; i++)
  {
    resultArr[i] = mas[i];
  }
  resultArr[size] = '\0';
  delete[] mas;
  mas = resultArr;
  return mas;
}
