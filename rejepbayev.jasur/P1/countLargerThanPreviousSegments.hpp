#ifndef COUNT_LARGER_THAN_PREVIOUS_SEGMENTS_HPP
#define COUNT_LARGER_THAN_PREVIOUS_SEGMENTS_HPP

namespace jasur
{
  class LargerSegmentsCounter
  {
    private:
      int count;
      int prevElement;
    public:
      LargerSegmentsCounter();
      void operator()(int current);
      int operator()() const;
  };
}

#endif
