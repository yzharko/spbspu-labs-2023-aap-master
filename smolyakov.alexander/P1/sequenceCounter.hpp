#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP
#include <cstddef>

struct SequenceCounter
{
public:
  void operator()(int v);
  int operator()() const;

private:
  size_t elementsCount_;
  int triples_;
  int seqEnd_;
  int seqMid_;
  int seqStart_;

  void clear();
  bool validate() const;
};

#endif
