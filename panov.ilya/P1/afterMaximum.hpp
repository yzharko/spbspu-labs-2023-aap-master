#ifndef AFTERMAXIMUM_HPP
#define AFTERMAXIMUM_HPP
#include <cstddef>
namespace panov
{
  struct AfterMaximum
  {
  public:
    AfterMaximum();
    void operator()(int number);
    size_t operator()() const;
  private:
    size_t count;
    int first;
    int max_number;
  };
}
#endif
