#ifndef MIN_COUNT_HPP
#define MIN_COUNT_HPP
#include <cstddef>

namespace sukacheva
{
  struct minCount
  {
  public:
    minCount();
    void operator()(long long value);
    size_t operator()() const;
  private:
    long long count;
    long long min_value;
    long long max_count;
  };
}
#endif
