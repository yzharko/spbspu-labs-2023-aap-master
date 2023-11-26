#ifndef SEQCOUNTER_HPP
#define SEQCOUNTER_HPP

namespace yartsev {
  struct SequenceCounter {
    public:
      SequenceCounter();
      void operator()();
      void updateMinCounter(int);
      void updateMaxSequence(int);
    private:
      int maxSequence;
      int currentSequence;
      int minElement;
      int minCounter;
  };
}

#endif
