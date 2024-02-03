#ifndef FUNCTIONS_MATRIX_H
#define FUNCTIONS_MATRIX_H

#include <fstream>
#include <cstdlib>

struct Matrix {
public:
    Matrix(int r, int c, int arrayType);
    ~Matrix();
    void readFromFile(std::ifstream &infile);
    void calculateMaxSumDiagonal() const;
    void transformMatrix();
    void writeToOutput(std::ofstream &outfile) const;

private:
    static const int MAX_SIZE = 100;
    int staticArray[MAX_SIZE][MAX_SIZE];
    int **dynamicArray;
    int rows, cols;
    int arrayType;

    void allocateDynamicArray();
    void deallocateDynamicArray();
};

#endif
