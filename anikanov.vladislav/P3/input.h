#ifndef INPUT_H
#define INPUT_H

#include <iosfwd>

size_t input(std::istream &, char *&, size_t);

size_t resize(char *&, size_t);

void print(std::ostream &, const char *, size_t);

#endif
