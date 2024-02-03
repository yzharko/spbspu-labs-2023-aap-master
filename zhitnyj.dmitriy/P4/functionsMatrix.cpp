#include "functionsMatrix.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>

Matrix::Matrix(int r, int c, int arrayType) : rows(r), cols(c), arrayType(arrayType) {
    if (arrayType == 1) {
        if (rows > MAX_SIZE || cols > MAX_SIZE) {
            throw std::invalid_argument("Invalid size for static array.");
        }
    } else if (arrayType == 2) {
        allocateDynamicArray();
    } else {
        throw std::invalid_argument("Invalid array type.");
    }
}

Matrix::~Matrix() {
    if (arrayType == 2) {
        deallocateDynamicArray();
    }
}

void Matrix::allocateDynamicArray() {
    dynamicArray = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        dynamicArray[i] = new int[cols]{};
    }
    if (!dynamicArray[0]) {
        throw std::invalid_argument("Invalid matrix data");
    }
}

void Matrix::deallocateDynamicArray() {
    for (int i = 0; i < rows; ++i) {
        delete[] dynamicArray[i];
    }
    delete[] dynamicArray;
}

void Matrix::readFromFile(std::ifstream &infile) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arrayType == 1) {
                infile >> staticArray[i][j];
            } else {
                infile >> dynamicArray[i][j];
            }
        }
    }
    if ((arrayType == 1 && !staticArray[0][0]) || ( arrayType == 0 && dynamicArray[0][0] )) {
        throw std::invalid_argument("Invalid matrix data");
    }
}

void Matrix::calculateMaxSumDiagonal() const {
    int maxSum = 0;
    for (int d = 0; d < cols; ++d) {
        int sum = 0;
        for (int i = 0, j = d; i < rows && j < cols; ++i, ++j) {
            sum += (arrayType == 1) ? staticArray[i][j] : dynamicArray[i][j];
        }
        maxSum = std::max(maxSum, sum);
    }
    for (int d = 1; d < rows; ++d) {
        int sum = 0;
        for (int i = d, j = 0; i < rows && j < cols; ++i, ++j) {
            sum += (arrayType == 1) ? staticArray[i][j] : dynamicArray[i][j];
        }
        maxSum = std::max(maxSum, sum);
    }
    std::cout << maxSum << std::endl;
}

void Matrix::transformMatrix() {
    int decrement = 1;
    int startRow = 0, endRow = rows - 1;
    int startCol = 0, endCol = cols - 1;

    while (startRow <= endRow && startCol <= endCol) {
        for (int i = startCol; i <= endCol; ++i) {
            if (arrayType == 1) {
                staticArray[startRow][i] -= decrement++;
            } else {
                dynamicArray[startRow][i] -= decrement++;
            }
        }
        startRow++;

        for (int i = startRow; i <= endRow; ++i) {
            if (arrayType == 1) {
                staticArray[i][endCol] -= decrement++;
            } else {
                dynamicArray[i][endCol] -= decrement++;
            }
        }
        endCol--;

        if (startRow <= endRow) {
            for (int i = endCol; i >= startCol; --i) {
                if (arrayType == 1) {
                    staticArray[endRow][i] -= decrement++;
                } else {
                    dynamicArray[endRow][i] -= decrement++;
                }
            }
            endRow--;
        }

        if (startCol <= endCol) {
            for (int i = endRow; i >= startRow; --i) {
                if (arrayType == 1) {
                    staticArray[i][startCol] -= decrement++;
                } else {
                    dynamicArray[i][startCol] -= decrement++;
                }
            }
            startCol++;
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arrayType == 1) {
                std::cout << staticArray[i][j] << " ";
            } else {
                std::cout << dynamicArray[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

void Matrix::writeToOutput(std::ofstream &outfile) const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int value = (arrayType == 1) ? staticArray[i][j] : dynamicArray[i][j];
            outfile << value << " ";
        }
        outfile << std::endl;
    }
}
