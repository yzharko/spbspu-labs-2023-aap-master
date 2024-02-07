#include "transform.hpp"
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

std::string transformString(const std::string& input) {
    // Используем unordered_map для подсчета частоты символов
    std::unordered_map<char, int> charFrequency;
    for (char c : input) {
        if (std::isalpha(c)) {  // Игнорируем не-буквенные символы
            charFrequency[c]++;
        }
    }

    // Используем vector для сортировки символов по частоте
    std::vector<std::pair<char, int>> sortedChars(charFrequency.begin(), charFrequency.end());
    std::sort(sortedChars.begin(), sortedChars.end(),
        [](const auto& a, const auto& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        });

    // Собираем новую строку из трех самых часто встречающихся символов
    std::string result;
    for (int i = 0; i < std::min(3, static_cast<int>(sortedChars.size())); ++i) {
        result += sortedChars[i].first;
    }

    // Сортируем символы в итоговой строке по ASCII-коду
    std::sort(result.begin(), result.end());

    return result;
}