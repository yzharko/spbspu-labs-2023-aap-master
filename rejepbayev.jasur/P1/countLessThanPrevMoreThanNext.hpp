#ifndef COUNT_LESS_THAN_PREV_MORE_THAN_NEXT_HPP
#define COUNT_LESS_THAN_PREV_MORE_THAN_NEXT_HPP

#include <stdexcept>

namespace jasur
{
  class LessMoreCounter
  {
    private:
      int count;
      int prevValue;
      bool isFirstValue;
   public:
     LessMoreCounter();
     void process(int value);
     int operator()() const;
  };
}
#endif
