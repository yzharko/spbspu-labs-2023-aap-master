#include <iostream>

int main(int argc, char ** argv)
{
  if (argc < 4) {
    std::cerr << "Not enough arguments\n";
    return 1;
  } else if (argc > 4) {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  try {
    int num = std::stol(argv[1]);
    if (num < 1 || num > 2) {
        std::cerr << "First parameter is out of range\n";
        return 1;
    }
  } catch (std::invalid_argument & e) {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  std::cout << "OK\n";
  return 0;
}