#ifndef CLASS_HPP
#define CLASS_HPP
#include <iostream>
#include <string>

namespace matrix
{
  class Matrix
  {
  public:
    void creatStaticMatrix(const std::string &);
    bool isSquareMatrix();
    bool matrixConditionCheck(int);
    void delMatrix();
    void creatDynamicMatrix(const std::string&);

    Matrix operator()(const std::string &);

  private:
    size_t rows;
    size_t cols;

    int * matrix;
    int staticMatrix[10000] = {0};

    std::string fileText;
  };
}

#endif
