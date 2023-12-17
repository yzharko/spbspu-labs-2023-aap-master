#ifndef INOUTARRAY_H
#define INOUTARRAY_H
#include <iosfwd>

int inputArray(std::istream &, int *array, int n, int m);

void printArray(std::ostream &, int const *array, int n, int m);

#endif
