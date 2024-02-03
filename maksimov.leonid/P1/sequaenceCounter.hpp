#ifndef sequaenceCounter_HPP
#define sequaenceCounter_HPP

namespace number
{
  struct Sequaence
  {
  public:
    void operator()(int & newN);
    void counterSeq();
    int answer();
  private:
    int firstN = 0;
    int secondN = 0;
    int thirdN = 0;
    int count = 0;
    int counter = 0;
  };
}

#endif
