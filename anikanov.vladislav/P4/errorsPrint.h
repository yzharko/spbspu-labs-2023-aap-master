#ifndef ERRRSPRINT_H
#define ERRRSPRINT_H

#include <iosfwd>

void printErrorByErrcode(std::ostream &, const char *code);

void wrongCountParams(std::ostream &);

void invalidInput(std::ostream &);

void invalidFirstArgument(std::ostream &);

#endif
