#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP
namespace zheleznyakov
{
  struct SequenceCounter
  {
    public:
      SequenceCounter();
      void operator()(int number);
      int operator()() const;
    private:
      int counter_;
      int previousElement_;
  };
}
#endif
