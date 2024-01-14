#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP
#include <limits>
namespace likhachev
{
  struct SequenceLocalMaxCount
  {
    public:
      SequenceLocalMaxCount();
      void operator()(int newNumber);
      int operator()() const;
      int getCount() const;
    private:
      int currValue;
      int count;
      int localMax;
      int localMaxCount;
      void checkLocalMax();
  };

  struct SequenceSignChangeCount
  {
    public:
      SequenceSignChangeCount();
      void operator()(int newNumber);
      int operator()() const;
      int getCount() const;
    private:
      int currValue;
      int count;
      int singChangeCount;
      void checkSamgeSign(int newNumber);
  };
};
#endif
