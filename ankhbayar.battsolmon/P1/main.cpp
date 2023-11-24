#include <iostream>

#include <vector>

int countSignChanges(const std::vector<int>& sequence) {

  int count = 0;

  for (int i = 1; i < sequence.size(); i++) {

    if ((sequence[i - 1] < 0 && sequence[i] >= 0) || (sequence[i - 1] >= 0 && sequence[i] < 0)) {

        count++;

    }

  }

  return count;
}



int main() {

  std::vector<int> sequence{ -2, 1, -2, 0 };

  int signChanges = countSignChanges(sequence);

  std::cout << signChanges << std::endl;



  return 0;
}
