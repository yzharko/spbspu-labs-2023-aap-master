#ifndef ARRAYMODIFICATIONS_H
#define ARRAYMODIFICATIONS_H

#include <iosfwd>

void spiralIncrease(int *array, int n, int m);

void setRight(int &dx, int &dy, int &x, int &y, int &move);

void setTop(int &dx, int &dy, int &x, int &y, int &move);

void setLeft(int &dx, int &dy, int &x, int &y, int &move);

void setBottom(int &dx, int &dy, int &x, int &y, int &move);

bool checkPosition(const bool *map, int x, int y, int m);

void generateMap(bool *map, int n, int m);

#endif
