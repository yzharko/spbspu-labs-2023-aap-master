#include <iostream>
#include "base-types.cpp"
#include "rectangle.cpp"
#include "square.cpp"
#include "complexquad.cpp"

int main(){
  Complexquad complexquad;
  std::cin >> complexquad;
  std::cout << complexquad.getFrameRect();
}
