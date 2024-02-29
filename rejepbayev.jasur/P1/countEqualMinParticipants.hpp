#ifndef COUNTEQUALMINPARTICIPANTS_HPP
#define COUNTEQUALMINPARTICIPANTS_HPP
#include <climits>
#include <vector>

namespace jasur
{
  class MinCounter
  {
    public:
      MinCounter();
      void process(int value);
      int operator()() const;
    private:
      std::vector<int> data;
      int min_value;
      int count;
  };
}

#endif
