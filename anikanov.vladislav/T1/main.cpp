#include <iostream>
#include "base-types.cpp"
#include "rectangle.cpp"
#include "square.cpp"

int main(){
  Square square;
  std::cin >> square;
  std::cout << square.getFrameRect();
}
