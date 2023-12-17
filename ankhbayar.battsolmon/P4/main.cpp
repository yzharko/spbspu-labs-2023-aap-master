#include <iostream>
#include <vector>

int findMaxSum(const std::vector<std::vector<int>>& matrix) {
    int maxSum = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();

    if (rows == 0 || cols == 0) {
        return maxSum;
    }

    if (rows != cols) {
        throw std::invalid_argument("Матрица должна быть квадратной");
    }

    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            if (i + j == rows - 1) {
                sum += matrix[i][j];
            }
        }
        if (sum > maxSum) {
            maxSum = sum;
        }
    }

    return maxSum;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {3, 3, 1},
        {2, 3, 4},
        {5, 6, 7}
    };

    try {
        int maxSum = findMaxSum(matrix);
        std::cout << "Максимальная сумма: " << maxSum << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
