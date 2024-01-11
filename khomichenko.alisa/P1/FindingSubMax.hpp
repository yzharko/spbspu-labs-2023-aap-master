#ifndef FINDING_SUB_MAX_HPP
#define FINDING_SUB_MAX_HPP
#include <cstddef>

namespace khomichenko
{
  struct FindingSubMax
  {
  public:
    FindingSubMax();
    void operator()(size_t num);
    size_t operator()() const;
  private:
    size_t subMax_;
    size_t max_;
  };
}
#endif
