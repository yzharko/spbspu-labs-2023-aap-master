#include "maxLen.hpp"
#include <iostream>

psarev::maxLen::maxLen():
  seqLen(0),
  maxSeqLen(0),
  preValue(0)
{}

void psarev::maxLen::operator()(int value)
{
  if (seqLen == 0 && value == 0) {
    throw std::logic_error("Error: Not a sequence!\n");
  }

  if (value >= preValue) {
    seqLen++;
    if (seqLen > maxSeqLen) {
      maxSeqLen = seqLen;
    }
  } else {
    seqLen = 1;
  }

  preValue = value;
}

int psarev::maxLen::operator()()
{
  return maxSeqLen;
}
