#ifndef ZHITNYJ_FUNCEQLSEQ_H
#define ZHITNYJ_FUNCEQLSEQ_H

#include <cstddef>

namespace zhitnyj {
  struct funcEqlSeq {
  public:
    funcEqlSeq();

    void operator()(int);

    size_t operator()();

  private:
    size_t count, maxCount, len;
    int prevElm;
  };
}

#endif // ZHITNYJ_FUNCEQLSEQ_H
