#include <iostream>
#include <vector>

int countPythagoreanTriples(const std::vector<int>& sequence) {
  int count = 0;
  for (int i = 0; i < sequence.size() - 2; i++) {
    int a = sequence[i];
    int b = sequence[i + 1];
    int c = sequence[i + 2];

    if (a * a + b * b == c * c || c * c + b * b == a * a || a * a + c * c == b * b)
    {
      count++;
    }
  }
  return count;
}

int main() {
  std::vector<int> sequence{ 3, 4, 5, 3, 4, 5, 0 };
  int pythagoreanTriples = countPythagoreanTriples(sequence);
  std::cout << pythagoreanTriples << std::endl;

  return 0;
}
