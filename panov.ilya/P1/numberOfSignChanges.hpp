#ifndef NUMBEROFSIGNCHANGES_HPP
#define NUMBEROFSIGNCHANGES_HPP
#include <cstddef>
namespace panov
{
  struct NumberOfSignChanges
  {
  public:
    NumberOfSignChanges();
    void operator()(int number);
    size_t operator()() const;
  private:
    size_t count;
    int first;
  };
}
#endif
