#include <iostream>
#include "base-types.cpp"
#include "rectangle.cpp"

int main(){
  Rectangle rec;
  std::cin >> rec;
  std::cout << rec.getFrameRect();
}
