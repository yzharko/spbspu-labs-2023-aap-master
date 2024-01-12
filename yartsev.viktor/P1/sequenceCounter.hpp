#ifndef SEQUENCECOUNTER_HPP
#define SEQUENCECOUNTER_HPP

namespace yartsev{
  struct MaxSequenceCounter {
    public:
      MaxSequenceCounter();
      int operator()();
      void operator()(const int);
    private:
      int maxSequence;
      int currentSequence;
  };
}

#endif
