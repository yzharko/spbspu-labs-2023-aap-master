#ifndef COUNT_SIGN_CHANGE_HPP
#define COUNT_SIGN_CHANGE_HPP

namespace ankhbayar
{
  struct CountSignChange
  {
  public:
    CountSignChange();
    void operator() (int number);
    unsigned int operator()() const;

  private:
    int lastNumber;
    unsigned int signChange;
  };
}
#endif
