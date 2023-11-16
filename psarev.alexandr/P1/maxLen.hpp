#ifndef MAXLEN_H
#define MAXLEN_H
#include <cstddef>

namespace psarev
{
  class maxLen
  {
  public:
    maxLen();
    void operator()(int value);
    int operator()();

  private:
    size_t seqLen;
    size_t maxSeqLen;
    int preValue;
  };
}
#endif
