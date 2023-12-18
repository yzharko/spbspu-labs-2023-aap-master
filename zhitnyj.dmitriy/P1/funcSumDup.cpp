#include <iostream>
#include <stdexcept>
#include "funcSumDup.h"

zhitnyj::funcSumDup::funcSumDup()
{
  count = 0;
  elm1 = 0;
  elm2 = 0;
  len = 0;
}

void zhitnyj::funcSumDup::operator()(int elm)
{
  len++;
  if (len == 1) {
    elm2 = elm;
  }
  if (len == 2) {
    elm1 = elm;
  }
  if (len >= 3) {
    if (elm1 + elm2 == elm) {
      count++;
    }
    elm2 = elm1;
    elm1 = elm;
  }
}

size_t zhitnyj::funcSumDup::operator()()
{
  if (len < 4) {
    throw std::length_error("Sequence must be longer!");
  }
  return count;
}
