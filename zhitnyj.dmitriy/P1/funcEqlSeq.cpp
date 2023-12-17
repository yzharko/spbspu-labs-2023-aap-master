#include <iostream>
#include "funcEqlSeq.h"

zhitnyj::funcEqlSeq::funcEqlSeq()
{
  count = 0;
  maxCount = 0;
  prevElm = 0;
  len = 0;
}

void zhitnyj::funcEqlSeq::operator()(int elm)
{
  len++;
  if (len == 1) {
    prevElm = elm;
    count++;
  }
  if (len >= 2) {
    if (elm == prevElm) {
      count++;
    } else {
      maxCount = std::max(count, maxCount);
      count = 1;
    }
    prevElm = elm;
  }
}

size_t zhitnyj::funcEqlSeq::operator()()
{
  maxCount = std::max(count, maxCount);
  return maxCount;
}
