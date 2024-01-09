#include "functionsMatrix.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Incorrect number of arguments.\n";
        return 1;
    }

    int arrayType = std::atoi(argv[1]);
    std::ifstream infile(argv[2]);
    std::ofstream outfile(argv[3]);
    if (!infile || !outfile) {
        std::cerr << "File error.\n";
        return 1;
    }

    int rows, cols;
    if (!(infile >> rows >> cols)) {
        std::cerr << "Failed to read matrix size.\n";
        return 1;
    }

    try {
        Matrix matrix(rows, cols, arrayType);
        matrix.readFromFile(infile);
        matrix.calculateMaxSumDiagonal();
        matrix.transformMatrix();
        matrix.writeToOutput(outfile);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    infile.close();
    outfile.close();
    return 0;
}
