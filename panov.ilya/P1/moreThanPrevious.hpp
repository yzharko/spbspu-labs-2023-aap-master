#ifndef MORETHENPREVIOUS_HPP
#define MORETHENPREVIOUS_HPP
#include <cstddef>
namespace panov
{
  struct MoreThanPrevious
  {
    public:
      MoreThanPrevious();
      void operator()(int number);
      size_t operator()() const;
    private:
      size_t count;
      int first;
  };
}
#endif
