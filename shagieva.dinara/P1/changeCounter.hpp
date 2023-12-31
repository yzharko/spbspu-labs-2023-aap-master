#ifndef CHANGE_COUNTER_HPP
#define CHANGE_COUNTER_HPP

namespace shagieva
{
  struct ChangeCounter
  {
  public:
    ChangeCounter();
    void operator()(int number);
    unsigned int operator()() const;

  private:
    int lastNumber;
    unsigned int signChange;
  };
}
#endif
