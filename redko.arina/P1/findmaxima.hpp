#ifndef FINDMAXIMA_HPP
#define FINDMAXIMA_HPP
namespace redko
{
  struct FindMaxima
  {
  public:
    FindMaxima();
    void operator()(int value);
    int operator()() const;
  private:
    int firstMaxValue;
    int secondMaxValue;
  };
}
#endif
