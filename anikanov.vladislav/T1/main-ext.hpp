#ifndef MAIN_EXT_HPP
#define MAIN_EXT_HPP

#include "compositeShape.hpp"

using namespace anikanov;

bool isNumber(const char *);

void checkFigure(char *, CompositeShape &);

void clearWord(char *, size_t &length, size_t &bufferSize);

char * inputWord(char *, size_t &length, size_t &bufferSize);

#endif
