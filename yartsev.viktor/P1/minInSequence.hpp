#ifndef MININSEQUENCE_HPP
#define MININSEQUENCE_HPP

namespace yartsev {
  struct MinInSequenceCounter {
    public:
      MinInSequenceCounter();
      int operator()();
      void operator()(const int);
    private:
      int minElement;
      int minCounter;
  };
}

#endif
