#include <iostream>
#include <vector>

int main() {
    std::vector<int> sequence;
    int num;

    while (std::cin >> num && num != 0) {
        sequence.push_back(num);
    }

    int positiveCount = 0;
    int negativeCount = 0;

    for (int i = 0; i < sequence.size(); i++) {
        if (sequence[i] > 0) {
            positiveCount++;
        } else if (sequence[i] < 0) {
            negativeCount++;
        }
    }

    std::cout << "Positive Count: " << positiveCount << std::endl;
    std::cout << "Negative Count: " << negativeCount << std::endl;

    return 0;
}
