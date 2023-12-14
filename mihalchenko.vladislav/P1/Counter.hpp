#ifndef COUNTER_HPP
#define COUNTER_HPP

namespace mihalchenko
{
  struct CounterAfterMax
  {
  public:
    CounterAfterMax();
    void operator()(int number, int seqCounter);
    unsigned int operator()(int seqCounter) const;
  private:
    int fMinus_;
    int fPlus_;
    int fMaxNum_;
    unsigned int countNumAfterMax_;
  };
}
#endif // !COUNTER_HPP
