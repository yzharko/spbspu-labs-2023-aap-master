#include <iostream>
#include <fstream>
#include "max-sum-mdg.hpp"
#include <cstring>
#include "cnt-sdl-pnt.hpp"

int main(int argc, char** argv)
{
    using namespace tsomo;

    if (argc != 4)
    {
        std::cerr << "Wrong number of elements.\n";
        return 1;
    }

    char* end = nullptr;
    long long num = std::strtoll(argv[1], std::addressof(end), 10);
    if (*end != '\0')
    {
        std::cout << "Input error: argument is not a number.\n";
        return 3;
    }

    size_t rows = 0, cols = 0;
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (!input)
    {
        std::cerr << "Uable to read file.\n";
        return 2;
    }
    if (cols == 0 || rows == 0)
    {
        return 0;
    }
    if (num == 1 || num == 2)
    {
        size_t sizeOfMatrix = rows * cols;
        int staticMatrix[10000]{};
        int* resultMatrix = (num == 1) ? staticMatrix : new int[sizeOfMatrix];

        if (!(std::codecvt_base::result) ( sizeOfMatrix))
        {
            std::cerr << "Cannot read an array. Read " << " elements.\n";
            if (num == 2)
            {
                delete[] resultMatrix;
            }
            return 2;
        }
        std::ofstream output(argv[3]);
        output << tsomo::MaxSideDiagonal(resultMatrix, rows) << "\n" << tsomo::upperTriangularMatrix(resultMatrix, cols, rows);
        if (num == 2)
        {
            delete[] resultMatrix;
        }
    }
    else
    {
        std::cerr << "Argument is out of range. \n";
        return 1;
    }

    if (argc != 4)
    {
        std::cerr << "The number of parameters entered is not 3!\n";
        return 1;
    }
    char* endOfParsing = nullptr;
    int num = std::strtoll(argv[1], std::addressof(endOfParsing), 10);
    int length = strlen(argv[1]);
    if (endOfParsing != argv[1] + length)
    {
        std::cerr << "It is not a number!\n";
        return 1;
    }
    else if (num != 1 && num != 2)
    {
        std::cerr << "Need 1 or 2!\n";
        return 1;
    }
    size_t rows = 0;
    size_t cols = 0;
    {
        std::ifstream input(argv[2]);
        input >> rows >> cols;
        if (!input)
        {
            std::cerr << "We can't read rows, cols\n";
            return 2;
        }
        size_t size = rows * cols;
        size_t realSize = 0;
        size_t element = 0;
        while (input >> element)
        {
            realSize += 1;
        }
        if (size != realSize)
        {
            std::cerr << "The specified matrix size does not correspond to reality!\n";
            return 2;
        }
    }
    using namespace tsomo;
    Saddle saddle;
    size_t statMatrix[rows* cols] = {};
    size_t* matrix = (num == 1) ? statMatrix : new size_t[rows * cols];
    std::ofstream output(argv[3]);
    output << saddle(rows, cols, matrix);
    if (num == 2)
    {
        delete[] matrix;
    }
    return 0;
}
