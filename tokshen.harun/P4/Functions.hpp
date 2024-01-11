#ifndef FUNCS_HPP
#define FUNCS_HPP
namespace toksen
{
  class Matrix
  {
  public:
    int line;
    int column;
    int *values;
    void fillArray();
    void writeAnswer()const;
    double findAnswer(int rows, int cols)const;   
  };
  int fillArguments(int, const char* []);
  int readInput();
}
#endif
