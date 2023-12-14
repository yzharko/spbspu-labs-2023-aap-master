#ifndef ZHITNYJ_FUNCSUMDUP_H
#define ZHITNYJ_FUNCSUMDUP_H

#include <cstddef>

namespace zhitnyj {
  struct funcSumDup {
  public:
    funcSumDup();

    void operator()(int);

    size_t operator()();

  private:
    size_t count, len;
    int elm1, elm2;
  };
}

#endif // ZHITNYJ_FUNCSUMDUP_H
